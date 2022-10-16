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

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable all_zeros = true;
            for (i in 0..Length(qs)-1) {
                if (M(qs[i]) == One) {
                    set all_zeros = false;
                }
            }
            if (all_zeros) {
                return 0;
            }
            return 1;
        }
    }
}