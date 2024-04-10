namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (x : Qubit[], y : Qubit) : ()
    {
        body
        {
            mutable len = Length(x);
            for(i in 0..(len-1)){
              CNOT(x[i], y);
            }
        }
    }
}