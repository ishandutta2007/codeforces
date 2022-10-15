namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            (ControlledOnInt(0, SWAP))([qs[0]], (qs[1], qs[2]));
            H(qs[0]);
            (ControlledOnInt(0, X))([qs[1]], qs[2]);
            (Controlled H)([qs[2]], qs[1]);
            (ControlledOnInt(0, X))([qs[1]], qs[2]);
        }
        adjoint auto;
    }
}