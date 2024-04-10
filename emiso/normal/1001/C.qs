namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            H(qs[0]);
            let size = Length(qs);
            for(i in 1..size-1) {
                CNOT(qs[0], qs[i]);
            }
        }
    }
}