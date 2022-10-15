namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            let last = qs[Length(qs)-1];
            for (i in 0..Length(qs)-2) {
                (Controlled X)([last], qs[i]);
            }
            H(last);
            for (i in 0..Length(qs)-2) {
                (Controlled X)([last], qs[i]);
            }
        }
        adjoint auto;
    }
}