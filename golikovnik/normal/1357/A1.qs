namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    
     operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using ((q1, q2) = (Qubit(), Qubit())) {
            X(q1);
            unitary([q1, q2]);
            let res = M(q2) == One ? 0 | 1;
            ResetAll([q1, q2]);
            return res;
        }
    }
}