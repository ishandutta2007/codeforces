namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable result = false;
            using (qubits = Qubit[N+1]) {
                let xs = qubits[0..N-1];
                let y = qubits[N];

                for (i in 0..N-1) {
                    H(xs[i]);
                }

                H(y);
                Z(y);

                Uf(xs, y);

                for (i in 0..N-1) {
                    H(xs[i]);
                }

                set result = true; // assume it's constant
                for (i in 0..N-1) {
                    // any 1 means it's false
                    if (M(xs[i]) == One) {
                        set result = false;
                    }
                }
                ResetAll(qubits);
            }
            return result;
        }
    }
}