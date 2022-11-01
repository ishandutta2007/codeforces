namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            let size = Length(qs);
            H(qs[0]);
            for(i in 1..size-1) {
                if(bits[i] == true) {
                    CNOT(qs[0], qs[i]);
                }
            }
        }
    }
}