namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : ()
    {
        body
        {
            // your code here
            mutable pre=-1;
            mutable pos=-1;
            mutable len = Length(qs);
            for(i in 0..(len-1)){
              if(bits0[i]){
                if(bits1[i]){
                  X(qs[i]);                 
                }else{
                  if(pre == -1){
                    H(qs[i]);
                    set pre=i;
                    set pos=0;
                  }else{
                    if(pos == 1){
                      X(qs[i]);
                    }
                    CNOT(qs[pre], qs[i]);
                  }
                }
              }else{
                if(bits1[i]){
                  if(pre == -1){
                    H(qs[i]);
                    set pre=i;
                    set pos=1;
                  }else{
                    if(pos == 0){
                      X(qs[i]);
                    }
                    CNOT(qs[pre], qs[i]);
                  }
                }
              }
            }
        }
    }
}