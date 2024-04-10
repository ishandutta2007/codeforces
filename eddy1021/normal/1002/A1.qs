namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            // your code here
            mutable len = Length(qs);
            for(i in 0..(len-1)){
              H(qs[i]);
            }
        }
    }
}