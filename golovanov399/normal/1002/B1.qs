namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable res = 0;
            using (q = Qubit[1]) {
                for (i in 0 .. Length(qs) - 1) {
                    CNOT(qs[i], q[0]);
                }
                if (M(q[0]) == One) {
                    set res = 1;
                }
                Reset(q[0]);
            }
            return res;
        }
    }
}