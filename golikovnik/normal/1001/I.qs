namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
            mutable constant = true;
            using (x = Qubit[N]) {
            	using (y = Qubit[1]) {
            		for (i in 0..N-1) {
            			H(x[i]);
            		}
            		X(y[0]);
            		H(y[0]);
            		Uf(x, y[0]);
            		for (i in 0..N-1) {
            			H(x[i]);
            		}
            		for (i in 0..N-1) {
            			if (M(x[i]) == One) {
            				set constant = false;
            			}
            		}
            		ResetAll(x);
            		Reset(y[0]);
            	}
            }
            return constant;
        }
    }
}