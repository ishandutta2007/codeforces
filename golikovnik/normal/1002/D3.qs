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

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            (Controlled X)(x[0..1], y);
            (Controlled X)([x[0]; x[2]], y);
            (Controlled X)(x[1..2], y);
        }  
    }

}