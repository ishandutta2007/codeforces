namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Unit {
        using (q = Qubit()) {
            repeat {
                ApplyToEach(H, qs);
                Controlled X(qs, q);
                let res = MResetZ(q);
            }
            until (res == Zero)
            fixup {
                ResetAll(qs);
            }
        }
    }
}