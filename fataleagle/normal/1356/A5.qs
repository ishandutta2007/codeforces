namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;
    
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using ((c, q) = (Qubit(), Qubit())) {
            H(c);
            Controlled unitary([c], q);
            H(c);
            return IsResultOne(MResetZ(c)) ? 1 | 0;
        }
    }
 }