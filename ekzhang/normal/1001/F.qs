namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            let n = Length(qs);
            for (i in 0..n-1) {
                if (bits0[i]) {
                    if (M(qs[i]) == Zero) {
                        return 1;
                    }
                }
                else {
                    if (M(qs[i]) == One) {
                        return 1;
                    }
                }
            }
            return 0;
        }
    }
}