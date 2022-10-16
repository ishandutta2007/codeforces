namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Set (desired: Result, q1: Qubit) : ()
    {
        body
        {
            let current = M(q1);
            if (desired != current)
            {
                X(q1);
            }
        }
    }

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            let res = MultiM(qs);
            if (res[0] == One && res[1] == One) {
            	return 0;
            } elif (res[0] == One && res[1] == Zero) {
            	return 1;
            } elif (res[0] == Zero && res[1] == One) {
            	return 2;
            }
            return 3;
        }
    }
}