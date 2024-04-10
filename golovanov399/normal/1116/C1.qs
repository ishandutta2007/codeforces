namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            if (Length(x) == 1) {
                X(y);
            } else {
                for (i in 1 .. 2 .. Length(x) - 1) {
                    X(x[i]);
                }
                (Controlled X)(x, y);
                ApplyToEachA(X, x);
                (Controlled X)(x, y);
                ApplyToEachA(X, x);
                for (i in 1 .. 2 .. Length(x) - 1) {
                    X(x[i]);
                }
            }
        }
        adjoint auto;
    }

    operation Test () : String {
        body {
            using (x = Qubit[5]) {
                using (y = Qubit[1]) {
                    X(x[0]);
                    // X(x[1]);
                    X(x[2]);
                    // X(x[3]);
                    X(x[4]);
                    Solve(x, y[0]);
                    DumpRegister("", y);
                    ResetAll(y);
                }
                ResetAll(x);
            }
            return "ok";
        }
    }
}