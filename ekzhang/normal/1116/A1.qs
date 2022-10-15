namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            let angle = -1.23095941734;
            X(qs[0]);
            X(qs[1]);
            (Controlled Ry)([qs[0]], (angle, qs[1]));
            (Controlled H)([qs[1]], qs[0]);
            (Controlled Z)([qs[0]], qs[1]);
            X(qs[0]);
            X(qs[1]);
        }
        adjoint auto;
    }
}