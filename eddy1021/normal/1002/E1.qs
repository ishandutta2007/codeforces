namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[]
    {
        body
        {
            // your code here
          mutable ans = new Int[N];

          using(q = Qubit[N]){
            using(targetBit = Qubit[1]){
              ResetAll(q);
              ResetAll(targetBit);
 

              for(i in 0..(N-1)){
                H(q[i]);
              }
              X(targetBit[0]);
              H(targetBit[0]);

              Uf(q, targetBit[0]);
              for(i in 0..(N-1)){
                H(q[i]);
              }


              for(i in 0..(N-1)){
                let res=M(q[i]);
                if(res == One){
                  set ans[i]=1;
                }else{
                  set ans[i]=0;
                }
              }


              ResetAll(q);
              ResetAll(targetBit);
            }
          }
          return ans;
        }
    }
}