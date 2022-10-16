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

    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : ()
    {
        body
        {
            let n = Length(b);
            for (i in 0..n-1) {
                if (b[i] > 0) {
                    CNOT(x[i], y);
                }
            }
        }
    }
}