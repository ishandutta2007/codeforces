namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            let size = Length(qs);
            mutable ret = 0;
            for(i in 0..size-1) {
                if(M(qs[i]) == One) {
                    set ret = 1;
                }
            }
            return ret;
        }
    }
}