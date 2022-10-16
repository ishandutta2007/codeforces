namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            let n = Length(qs);
            for (i in 0..n-1) {
                if (bits0[i] != bits1[i]) {
                    let one = (M(qs[i]) == One);
                    if (one == bits0[i]) {
                        return 0;
                    }
                    return 1;
                }
            }
	    return -1;
        }
    }
}