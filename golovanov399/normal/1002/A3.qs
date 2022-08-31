namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            mutable x = -1;
            for (i in 0 .. Length(bits0) - 1) {
                if (bits0[i] != bits1[i]) {
                    if (x == -1) {
                        set x = i;
                        H(qs[i]);
                    } else {
                        CNOT(qs[x], qs[i]);
                    }
                }
            }
            for (i in 0 .. Length(bits0) - 1) {
                if (bits0[i] == true) {
                    X(qs[i]);
                }
            }
        }
    }
}