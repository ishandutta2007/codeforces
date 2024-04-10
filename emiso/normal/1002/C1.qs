namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            mutable ret = 1;
            R(PauliY, 3.14159265358979 / 4.0, q);
            if(M(q) == Zero) {
                set ret = 0;
            }
            return ret;
        }
    }
}