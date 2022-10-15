namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Wing(qs : Qubit[]) : ()
    {
        body
        {
            // produces the /. shape matrix
            for (i in 1..Length(qs)-1) {
                X(qs[i]);
                (Controlled X)(qs[0..i-1], qs[i]);
            }
        }
        adjoint auto;
    }

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            for (i in 0..Length(qs)-2) {
                CNOT(qs[Length(qs)-1], qs[i]);
            }
            H(qs[Length(qs)-1]);
            Wing(qs[0..Length(qs)-2]);
            for (i in 0..Length(qs)-2) {
                CNOT(qs[Length(qs)-1], qs[i]);
            }
        }
        adjoint auto;
    }
}