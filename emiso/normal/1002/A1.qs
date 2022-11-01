namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            let size = Length(qs);
            for(i in 0..size-1) {
                H(qs[i]);
            }
        }
    }
}