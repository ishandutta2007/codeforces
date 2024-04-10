namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Sub (ar : Qubit[], x : Qubit[]) : Unit {
        body (...) {
            X(ar[0]);
            for (i in 0..Length(x)-1) {
                Controlled SWAP([x[i]], (ar[0], ar[1]));
                Controlled SWAP([x[i]], (ar[1], ar[2]));
            }
        }
        adjoint auto;
    }

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            using (ar = Qubit[3]) {
                Sub(ar, x);
                CNOT(ar[0], y);
                Adjoint Sub(ar, x);
            }
        }
        adjoint auto;
    }
}