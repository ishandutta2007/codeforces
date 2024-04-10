namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Period (k : Int, x : Qubit[], y : Qubit) : ()
    {
        body
        {
            for (i in 0..Length(x)-1-k) {
                CNOT(x[i + k], x[i]);
            }
            (ControlledOnInt(0, X))(x[0..Length(x)-1-k], y);
            for (j in 0..Length(x)-1-k) {
                let i = Length(x)-1-k-j;
                CNOT(x[i + k], x[i]);
            }
        }
        adjoint auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            using (ar = Qubit[Length(x) - 1]) {
                for (i in 1..Length(ar)) {
                    Period(i, x, ar[i - 1]);
                }
                X(y);
                (ControlledOnInt(0, X))(ar, y);
                for (i in 1..Length(ar)) {
                    Period(i, x, ar[i - 1]);
                }
            }
        }
        adjoint auto;
    }
}