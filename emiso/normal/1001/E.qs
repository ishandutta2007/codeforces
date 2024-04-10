namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable bit0 = 0;
            mutable bit1 = 0;

            CNOT(qs[0], qs[1]);
            if(M(qs[1]) == One) {
                set bit1 = 2;
            }

            H(qs[0]);
            if(M(qs[0]) == One) {
                set bit0 = 1;
            }

            return bit0 + bit1;
        }
    }
}