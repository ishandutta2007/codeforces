namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool
    {
        body
        {
          mutable ans=1;
          using(q = Qubit[N]){
            using(targetBit = Qubit[1]){
              ResetAll(q);
              for(i in 0..(N-1)){
                H(q[i]);
              }
              ResetAll(targetBit);
              X(targetBit[0]);
              H(targetBit[0]);
              Uf(q, targetBit[0]);
              for(i in 0..(N-1)){
                H(q[i]);
              }
              for(i in 0..(N-1)){
                let res=M(q[i]);
                if(res == One){
                  set ans=0;
                }
              }
              ResetAll(targetBit);
              ResetAll(q);
            }
          }
          if(ans == 1){
            return true;
          }else{
            return false;
          }
        }
    }
}