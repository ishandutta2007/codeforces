namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using ((q, r) = (Qubit(), Qubit())) {
            X(q);
            unitary([q, r]);
            Reset(q);
            return IsResultOne(MResetZ(r)) ? 0 | 1;
        }
    }
}