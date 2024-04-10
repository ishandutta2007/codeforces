namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Bitwise;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], index : Int) : ()
    {
        body
        {
            if (And(index, 1) != 0) {
                X(qs[0]);
            }
            H(qs[0]);
            CNOT(qs[0], qs[1]);
            if (And(index, 2) != 0) {
                X(qs[1]);
            }
        }
    }
}