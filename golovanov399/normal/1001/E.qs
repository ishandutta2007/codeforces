namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            mutable x = 0;
            if (M(qs[0]) == One) {
                set x = x + 1;
            }
            if (M(qs[1]) == One) {
                set x = x + 2;
            }
            return x;
        }
    }
}