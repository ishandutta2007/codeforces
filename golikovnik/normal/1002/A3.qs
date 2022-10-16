namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            let n = Length(qs);
            mutable fi = -1;
            for (i in 0..n-1) {
                if (bits0[i] && bits1[i]) {
                    X(qs[i]);
                } elif (bits0[i] || bits1[i]) {
                    if (fi < 0) {
                        set fi = i;
                        H(qs[i]);
                    } else {
                        if (bits0[fi] == bits1[i]) {
                            X(qs[i]);
                        }
                        CNOT(qs[fi], qs[i]);
                    }
                }
            }
        }
    }
}