namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            // your code here
            H(qs[0]);
            H(qs[1]);
            mutable r0=M(qs[0]);
            mutable r1=M(qs[1]);
            if(r0==Zero){
              if(r1==Zero){
                return 0;
              }else{
                return 1;
              }
            }else{
              if(r1==Zero){
                return 2;
              }else{
                return 3;
              }
            }
        }
    }
}