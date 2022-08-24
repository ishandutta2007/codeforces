namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (qs : Qubit[]) : Unit {
        Ry(2.0 * ArcSin(1.0 / Sqrt(3.0)), qs[0]);
        X(qs[0]);
        (Controlled H)([qs[0]], qs[1]);
        X(qs[0]);
    }

    operation RunQsharp () : Bool {
        using (x = Qubit[2]) {
            Solve(x);
            DumpMachine("");
            // using (y = Qubit[1]) {
            //     X(x[0]);
            //     // X(x[1]);
            //     X(x[2]);
            //     // X(x[3]);
            //     X(x[4]);
            //     Solve(x, y[0]);
            //     DumpRegister("", y);
            //     ResetAll(y);
            // }
            ResetAll(x);
        }
        return true;
    }
}