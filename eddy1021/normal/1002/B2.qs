namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            // your code here
            mutable len = Length(qs);
            mutable got = 0;
            mutable result=Zero;
            for(i in 0..(len-1)){
              set result=M(qs[i]);
              if(result == One){
                set got = got+1;
              }
            }
            if(got == 1){
              return 1;
            }
            return 0;
        }
    }
}