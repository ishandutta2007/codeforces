namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            mutable x = -1;
            for (i in 0 .. Length(bits) - 1) {
                if (bits[i] == true) {
                    if (x == -1) {
                        set x = i;
                        H(qs[i]);
                    } else {
                        CNOT(qs[x], qs[i]);
                    }
                }
            }
        }
    }
}