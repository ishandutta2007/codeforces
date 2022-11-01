namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[1]);
            CNOT(qs[0], qs[1]);
            H(qs[0]);

            mutable ret = 3;
            if(M(qs[0]) == One) {
                set ret = ret - 1;
            }
            if(M(qs[1]) == One) {
                set ret = ret - 2;
            }
            return ret;
        }
    }
}