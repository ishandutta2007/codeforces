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

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            let n = Length(qs);
            for (i in 0..n-1) {
                H(qs[i]);
            }
        }
    }
}