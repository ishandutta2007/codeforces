namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;


    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current)
            {
                X(q1);
            }
        }
    }

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            mutable idx = -1;
            let n = Length(qs);
            for (i in 0..n-1) {
                if (bits[i]) {
                    if (idx < 0) {
                        set idx = i;
                        H(qs[i]);
                    } else {
                        CNOT(qs[idx], qs[i]);
                    }
                }
            }
        }
    }
}