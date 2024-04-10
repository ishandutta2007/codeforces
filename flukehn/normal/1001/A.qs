namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit, sign : Int) : ()
    {
        body
        {
            // your code here
            H(q);
            if(sign==-1){
              Z(q);
            }
        }
    }
}