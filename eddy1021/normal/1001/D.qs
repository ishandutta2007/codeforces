namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit) : Int
    {
        body
        {
          mutable result=Zero;
          H(q);
          set result=M(q);
          if(result == Zero){
            return 1;
          }else{
            return -1;
          }
        }
    }
}