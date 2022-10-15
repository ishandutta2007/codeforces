namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            for (i in 0..Length(x)-2) {
                CNOT(x[i + 1], x[i]);
            }
            (Controlled X)(x[0..Length(x)-2], y);
            for (i in 0..Length(x)-2) {
                let k = Length(x) - 2 - i;
                CNOT(x[k + 1], x[k]);
            }
        }
        adjoint auto;
    }
}