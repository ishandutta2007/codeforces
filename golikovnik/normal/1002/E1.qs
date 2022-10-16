namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;


    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current)
            {
                X(q1);
            }
        }
    }

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {   
            mutable ans = new Int[N];
            using (y = Qubit[1]) {
                Set(One, y[0]);
                H(y[0]);
                using (x = Qubit[N]) {
                    ApplyToEachCA(H, x);
                    Uf(x, y[0]);
                    ApplyToEachCA(H, x);
                    for (i in 0..N-1) {
                        let res = M(x[i]);
                        if (res == One) {
                            set ans[i] = 1;
                        } else {
                            set ans[i] = 0;
                        }
                    }
                    ResetAll(x);
                }
                Reset(y[0]);
            }
            return ans;
        }
    }
}