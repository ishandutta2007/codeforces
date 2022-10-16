namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit, sign : Int) : ()
    {
        body
        {
		H(q);
		if (sign < 0) {
			Z(q);
		}
        }
    }
}