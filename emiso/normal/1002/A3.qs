namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            let size = Length(qs);
            mutable differ = 0;
            mutable pos = -1;

            for(i in 0..size-1) {
                if(bits0[i] == true && bits1[i] == true) {
                    X(qs[i]);
                }
                if(bits0[i] == true && bits1[i] == false) {
                    if(differ == 1) {
                        CNOT(qs[pos], qs[i]);
                    }
                    if(differ == 2) {
                        CNOT(qs[pos], qs[i]);
                        X(qs[i]);
                    }
                    if(differ == 0) {
                        H(qs[i]);
                        set differ = 1;
                        set pos = i;
                    }
                }
                if(bits0[i] == false && bits1[i] == true) {
                    if(differ == 1) {
                        CNOT(qs[pos], qs[i]);
                        X(qs[i]);
                    }
                    if(differ == 2) {
                        CNOT(qs[pos], qs[i]);
                    }
                    if(differ == 0) {
                        H(qs[i]);
                        set differ = 2;
                        set pos = i;
                    }
                }
            }
        }
    }
}