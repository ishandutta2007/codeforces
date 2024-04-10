namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            let size = Length(qs);
            mutable ret = 0;
            mutable ans = 0;
            for(i in 0..size-1) {
                if(M(qs[i]) == One) {
                    set ret = ret + 1;
                }
            }
            if(ret == 1) {
                set ans = 1;
            }
            return ans;
        }
    }
}