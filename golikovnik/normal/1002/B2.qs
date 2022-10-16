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
            mutable num_ones = 0;
            let n = Length(qs);
            for (i in 0..n-1) {
                if (M(qs[i]) == One) {
                    set num_ones = num_ones + 1;
                }
            }
            if (num_ones == 1) {
                return 1;
            }
            return 0;
        }
    }
}