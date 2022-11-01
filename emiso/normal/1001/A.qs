namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit, sign : Int) : ()
    {
        body
        {
            let res = ResultFromBool(sign == -1);
            if(M(q) != res) {
                X(q);
            }
            H(q);
        }
    }
}