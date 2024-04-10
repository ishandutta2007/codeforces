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
            X(r);
            unitary([q, r]);
            let result1 = IsResultOne(MResetZ(q));
            let result2 = IsResultOne(MResetZ(r));
            if (result1 and result2) {
                X(q);
                unitary([q, r]);
                Reset(q);
                return IsResultOne(MResetZ(r)) ? 3 | 0;
            }
            else {
                X(q);
                unitary([q, r]);
                Reset(q);
                return IsResultOne(MResetZ(r)) ? 1 | 2;
            }
        }
    }
}