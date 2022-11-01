namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], index : Int) : ()
    {
        body
        {
            if(index == 0 || index == 1) {
                H(qs[0]);
                CNOT(qs[0], qs[1]);
                if(index == 1) {
                    Z(qs[1]);
                } 
            } else {
                H(qs[0]);
                X(qs[1]);
                CNOT(qs[0], qs[1]);
                if(index == 3) {
                    Z(qs[1]);
                }
            }
        }
    }
}