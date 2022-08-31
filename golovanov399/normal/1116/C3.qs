namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (x : Qubit[], y : Qubit) : Unit {
        body (...) {
            let n = Length(x);
            ApplyToEachA(X, x);

            (Controlled X)(x, y);

            for (i in 0 .. n - 1) {
                X(x[i]);
                for (j in 0 .. i - 1) {
                    X(x[j]);
                    for (k in 0 .. j - 1) {
                        X(x[k]);
                        (Controlled X)(x, y);
                        X(x[k]);
                    }
                    X(x[j]);
                }
                X(x[i]);
            }

            if (n == 6) {
                ApplyToEachA(X, x);
                (Controlled X)(x, y);
                ApplyToEachA(X, x);
            }
            if (n == 7) {
                ApplyToEachA(X, x);
                for (i in 0 .. n - 1) {
                    X(x[i]);
                    (Controlled X)(x, y);
                    X(x[i]);
                }
                ApplyToEachA(X, x);
            }
            if (n == 8) {
                ApplyToEachA(X, x);
                for (i in 0 .. n - 1) {
                    X(x[i]);
                    for (j in 0 .. i - 1) {
                        X(x[j]);
                        (Controlled X)(x, y);
                        X(x[j]);
                    }
                    X(x[i]);
                }
                ApplyToEachA(X, x);
            }
            if (n == 9) {
                ApplyToEachA(X, x);
                for (i in 0 .. n - 1) {
                    X(x[i]);
                    for (j in 0 .. i - 1) {
                        X(x[j]);
                        for (k in 0 .. j - 1) {
                            X(x[k]);
                            (Controlled X)(x, y);
                            X(x[k]);
                        }
                        X(x[j]);
                    }
                    X(x[i]);
                }
                (Controlled X)(x, y);
                ApplyToEachA(X, x);
            }

            ApplyToEachA(X, x);
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