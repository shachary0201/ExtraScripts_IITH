void Ex1(){
TFile *f = TFile::Open("/eos/user/c/cmsdas/long-exercises/MonoZ/CMSDAS_NTuples/WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8/tree_17.root"); //We can add any other file of choice
TTree *tree = (TTree*)f->Get("Events");

float Electron_pt[10]; //try with 10                                                                                                                                                                                                          
tree->SetBranchAddress("Electron_pt", Electron_pt);
UInt_t nElectron;
tree->SetBranchAddress("nElectron", &nElectron);

Long64_t nEntries = tree->GetEntries();
int passed = 0;

for (Long64_t i = 0; i < nEntries; ++i) {
    tree->GetEntry(i);

    if (nElectron >= 2) {
        if (Electron_pt[0] > 20 && Electron_pt[1] > 20) {
            passed++;
        }
    }
}

std::cout << "Events passing cut: " << passed << std::endl;
}



