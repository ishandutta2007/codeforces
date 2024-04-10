namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Diagnostics;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Math;

    operation Solve (qs : Qubit[]) : Int {
        let angle = PI() * ToDouble(2) / ToDouble(3);
        R1(angle, qs[1]);
        R1(angle, qs[2]);

        X(qs[1]);
        CNOT(qs[2], qs[0]);
        (Controlled H)([qs[1], qs[0]], qs[2]);
        X(qs[1]);

        R1(angle, qs[1]);

        CNOT(qs[1], qs[0]);
        X(qs[2]);
        (Controlled Ry)([qs[2], qs[0]], (ToDouble(2) * ArcSin(Sqrt(ToDouble(2) / ToDouble(3))), qs[1]));
        X(qs[2]);

        // DumpRegister("", qs);

        // R1(ToDouble(2) * angle, qs[1]);
        // R1(ToDouble(2) * angle, qs[2]);

        // X(qs[2]);
        // (Controlled Ry)([qs[2]], (-ToDouble(2) * ArcSin(Sqrt(ToDouble(9) / ToDouble(17))), qs[1]));
        // X(qs[2]);

        if (M(qs[1]) == One && M(qs[2]) == Zero) {
            return 0;
        } else {
            return 1;
        }
    }

    operation RunQsharp () : Bool {
        using (x = Qubit[3]) {
            Ry(ToDouble(2) * ArcSin(ToDouble(1) / Sqrt(ToDouble(3))), x[0]);
            X(x[0]);
            (Controlled Ry)([x[0]], (PI() / ToDouble(2) , x[1]));
            X(x[1]);
            CCNOT(x[0], x[1], x[2]);
            X(x[1]);
            X(x[0]);
            R1(PI() * ToDouble(2) / ToDouble(3), x[1]);
            R1(-PI() * ToDouble(2) / ToDouble(3), x[2]);
            Message($"{Solve(x)}");
            ResetAll(x);
        }

        return true;
    }
}