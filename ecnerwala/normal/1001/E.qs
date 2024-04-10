namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            mutable result = 0;
            CNOT(qs[0], qs[1]);
            if (M(qs[1]) == One) {
                set result = result + 2;
            }
            H(qs[0]);
            if (M(qs[0]) == One) {
                set result = result + 1;
            }
            return result;
        }
    }
}