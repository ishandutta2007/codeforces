namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            mutable len = Length(qs);
            mutable res = new Result[len];
            for(i in 0..(len-1)){
              set res[i] = M(qs[i]);
            }
            mutable flag = 1;
            for(i in 0..(len-1)){
              if(res[i] == Zero){
                if(bits0[i]){
                  set flag = 0;
                }
              }else{
                if(bits0[i]){
                }else{
                  set flag = 0;
                }
              }
            }
            if(flag == 1){
              return 0;
            }
            return 1;
        }
    }
}