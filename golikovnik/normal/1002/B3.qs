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
            H(qs[0]);
            H(qs[1]);
            return MeasureIntegerBE(BigEndian(qs));
        }
    }
}