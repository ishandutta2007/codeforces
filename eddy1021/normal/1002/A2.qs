namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            // your code here
            mutable pre=-1;
            mutable len = Length(qs);
            for(i in 0..(len-1)){
              if(bits[i]){
                  if(pre == -1){
                    H(qs[i]);
                    set pre=i;
                  }else{
                    CNOT(qs[pre], qs[i]);
                  }
              }
            }
        }
    }
}