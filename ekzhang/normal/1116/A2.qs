namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[][]) : ()
    {
        body
        {
            using (x = Qubit[2]) {
                H(x[0]);
                H(x[1]);
                mutable nums = new Int[4];
                for (i in 0..3) {
                    mutable num = 0;
                    mutable p = 1;
                    for (j in 0..Length(qs)-1) {
                        if (bits[i][j]) {
                            (ControlledOnInt(i, X))(x, qs[j]);
                            set num = num + p;
                        }
                        set p = p * 2;
                    }
                    set nums[i] = num;
                }
                (ControlledOnInt(nums[1], X))(qs, x[0]);
                (ControlledOnInt(nums[2], X))(qs, x[1]);
                (ControlledOnInt(nums[3], X))(qs, x[0]);
                (ControlledOnInt(nums[3], X))(qs, x[1]);
            }
        }
        // adjoint auto;
    }
}