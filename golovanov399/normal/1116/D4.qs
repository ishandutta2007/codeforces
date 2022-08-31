namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (x : Qubit[]) : Unit {
        for (i in 0 .. Length(x) - 2) {
            CNOT(x[Length(x) - 1], x[i]);
        }
        for (i in Length(x) - 2 .. -1 .. 0) {
            if (i > 0) {
                SWAP(x[i], x[Length(x) - 1]);
                (Controlled X)(x[0 .. i], x[Length(x) - 1]);
                SWAP(x[i], x[Length(x) - 1]);
            } else {
                CNOT(x[Length(x) - 1], x[i]);
            }
        }
        for (i in 0 .. Length(x) - 2) {
            CNOT(x[Length(x) - 1], x[i]);
        }

        X(x[Length(x) - 1]);
        for (i in Length(x) - 2 .. -1 .. 0) {
            if (i > 0) {
                SWAP(x[i], x[Length(x) - 1]);
                (Controlled X)(x[0 .. i], x[Length(x) - 1]);
                SWAP(x[i], x[Length(x) - 1]);
            } else {
                CNOT(x[Length(x) - 1], x[i]);
            }
        }

        for (i in 1 .. Length(x) - 1) {
            CNOT(x[0], x[i]);
        }
        H(x[0]);
        for (i in 1 .. Length(x) - 1) {
            CNOT(x[0], x[i]);
        }
    }

    operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit)) : Unit {
        let size = 1 <<< N;
        
        using (qs = Qubit[N]) {
            for (k in 0 .. size - 1) {                
                // Prepare k-th basis vector
                let binary = BoolArrFromPositiveInt(k, N);
                
                //Message($"{k}/{N} = {binary}");
                // binary is little-endian notation, so the second vector tried has qubit 0 in state 1 and the rest in state 0
                ApplyPauliFromBitString(PauliX, true, binary, qs);
                
                // Apply the operation
                unitary(qs);
                
                // Dump the contents of the k-th column
                DumpMachine($"DU_{N}_{k}.txt");
                
                ResetAll(qs);
            }
        }
    }

    operation Test () : String {
        body {
            // using (x = Qubit[5]) {
            // }
            DumpUnitaryToFiles(2, Solve);
            return "ok";
        }
    }
}