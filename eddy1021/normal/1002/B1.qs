namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            // your code here
            mutable len = Length(qs);
            mutable ret = 0;
            mutable result=Zero;
            for(i in 0..(len-1)){
              set result=M(qs[i]);
              if(result == One){
                set ret = 1;
              }
            }
            return ret;
        }
    }
}