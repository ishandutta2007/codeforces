namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            using (b = Qubit[n - 1]) {
                for (len in 1 .. n - 1) {
                    for (i in n - len - 1 .. -1 .. 0) {
                        CNOT(x[i], x[i + len]);
                    }
                    ApplyToEachA(X, x[len .. n - 1]);
                    (Controlled X)(x[len .. n - 1], b[len - 1]);
                    ApplyToEachA(X, x[len .. n - 1]);
                    for (i in 0 .. n - len - 1) {
                        CNOT(x[i], x[i + len]);
                    }
                }
                X(y);
                ApplyToEachA(X, b);
                (Controlled X)(b, y);
                ApplyToEachA(X, b);
                for (len in 1 .. n - 1) {
                    for (i in n - len - 1 .. -1 .. 0) {
                        CNOT(x[i], x[i + len]);
                    }
                    ApplyToEachA(X, x[len .. n - 1]);
                    (Controlled X)(x[len .. n - 1], b[len - 1]);
                    ApplyToEachA(X, x[len .. n - 1]);
                    for (i in 0 .. n - len - 1) {
                        CNOT(x[i], x[i + len]);
                    }
                }
            }
        }
        adjoint auto;
    }

    operation RunQsharp () : Bool {
        using (x = Qubit[5]) {
            using (y = Qubit()) {
                X(x[0]);
                X(x[2]);
                X(x[4]);
                Solve(x, y);
                DumpRegister("", [y]);

                Reset(y);
            }
            ResetAll(x);
        }

        return true;
    }
}