namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            H(q);
            if (M(q) == One) {
                return -1;
            } 
            return 1;
        }
    }
}