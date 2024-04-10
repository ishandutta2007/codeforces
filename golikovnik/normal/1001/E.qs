namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            CNOT(qs[0], qs[1]);
            let psi = (M(qs[1]) == One);
            H(qs[0]);
            if (M(qs[0]) == One) {
                if (psi) {
                    return 3;
                }
                return 1;
            }
            if (psi) {
                return 2;
            }
            return 0;
        }
    }
}