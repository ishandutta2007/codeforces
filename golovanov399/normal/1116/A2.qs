namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (qs : Qubit[], bits : Bool[][]) : Unit {
        let n = Length(qs);
        for (i in 0 .. n - 1) {
            mutable used = new Bool[4];
            // Message($"{i}");
            for (j in 0 .. 3) {
                if (not used[j]) {
                    mutable same = 0;
                    mutable not_same = 0;
                    for (k in j .. 3) {
                        mutable differ = false;
                        for (idx in 0 .. i - 1) {
                            if (bits[k][idx] != bits[j][idx]) {
                                set differ = true;
                            }
                        }
                        if (not differ) {
                            set used[k] = true;
                            if (not bits[k][i]) {
                                set same = same + 1;
                            } else {
                                set not_same = not_same + 1;
                            }
                        }
                    }
                    // Message($"{same}, {not_same}");

                    for (idx in 0 .. i - 1) {
                        if (not bits[j][idx]) {
                            X(qs[idx]);
                        }
                    }
                    (Controlled Ry)(qs[0 .. i - 1], (ToDouble(2) * ArcSin(Sqrt(ToDouble(not_same) / ToDouble(same + not_same))), qs[i]));
                    for (idx in 0 .. i - 1) {
                        if (not bits[j][idx]) {
                            X(qs[idx]);
                        }
                    }
                }
            }
        }
    }

    operation RunQsharp () : Bool {
        // using (x = Qubit[5]) {
        //     using (y = Qubit[1]) {
        //         X(x[0]);
        //         // X(x[1]);
        //         X(x[2]);
        //         // X(x[3]);
        //         X(x[4]);
        //         Solve(x, y[0]);
        //         DumpRegister("", y);
        //         ResetAll(y);
        //     }
        //     ResetAll(x);
        // }
        using (x = Qubit[6]) {
            let bits = [
                [false, false, false, false, true, true],
                [false, false, false, false, false, true],
                [true, true, true, true, false, true],
                [false, false, false, true, false, false]
            ];
            Solve(x, bits);
            DumpMachine("");
            ResetAll(x);
        }
        return true;
    }
}