namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            H(qs[0]);
            let n = Length(qs);
            for (index in 1 .. n-1) {
                CNOT(qs[0], qs[index]);
            }
        }
    }
}