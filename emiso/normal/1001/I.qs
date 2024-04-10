namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable answer = true;
            using(qs = Qubit[N]) {
                using(qr = Qubit[1]) {
                    for(i in 0..N-1) {
                        H(qs[i]);
                    }

                    X(qr[0]);
                    H(qr[0]);

                    Uf(qs, qr[0]);

                    for(i in 0..N-1) {
                        H(qs[i]);
                    }

                    for(i in 0..N-1) {
                        if(M(qs[i]) == One) {
                            set answer = false;
                        }
                    }

                    Reset(qr[0]);
                }
                ResetAll(qs);
            }
            return answer;
        }
    }
}