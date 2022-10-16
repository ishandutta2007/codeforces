namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    
     operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using ((q1, q2, q3, q4) = (Qubit(), Qubit(), Qubit(), Qubit())) {
            X(q1);
            unitary([q1, q2]);
            mutable res = 0;
            X(q3);
            X(q4);
            unitary([q3, q4]);
            if (M(q2) == One) {
                if (M(q4) == One) {
                  set res = 3;
                } else {
                  set res = 1;
                }
            } else {
                if (M(q3) == One) {
                  set res = 0;
                } else {
                  set res = 2;
                }
            }
            ResetAll([q1, q2, q3, q4]);
            return res;
        }
    }
}