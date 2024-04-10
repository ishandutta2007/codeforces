namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using ((c, q) = (Qubit(), Qubit())) {
            unitary([c, q]);
            return IsResultOne(MResetZ(q)) ? 0 | 1;
        }
    }
 }