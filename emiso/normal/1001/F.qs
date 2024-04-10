namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            let size = Length(bits0);
            for(i in 0..size-1) {
                if(M(qs[i]) != ResultFromBool(bits0[i])) {
                    return 1;
                }
            }
            return 0;
        }
    }
}