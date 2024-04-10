namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation PlusMinus (q : Qubit) : Int
    {
        body
        {
            H(q);
            if (M(q) == Zero) {
                return 0;
            }
            return 1;
        }
    }

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0], qs[1]);
            mutable ans = 0;
            if (M(qs[1]) == One) {
                set ans = 2;
            }
            set ans = ans + PlusMinus(qs[0]);
            return ans;
        }
    }
}