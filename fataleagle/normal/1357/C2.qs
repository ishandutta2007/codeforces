namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        let n = Length(qs);
        using (q = Qubit()) {
            repeat {
                ApplyToEach(H, qs);
                for (i in n - 1 .. -1 .. 0) {
                    Controlled X(qs[i .. i], q);
                }
                let res = MResetZ(q);
            }
            until (res == (parity == 0 ? Zero | One))
            fixup {
                ResetAll(qs);
            }
        }
    }
}