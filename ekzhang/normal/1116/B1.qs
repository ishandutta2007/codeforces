namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation ThreePos (qs : Qubit[]) : Unit {
        body (...) {
            let angle = -1.23095941734;
            X(qs[0]);
            X(qs[1]);
            Controlled Ry([qs[0]], (angle, qs[1]));
            Controlled H([qs[1]], qs[0]);
            Controlled Z([qs[0]], qs[1]);
            X(qs[0]);
            X(qs[1]);
        }
        adjoint auto;
    }

    operation Solve (qs : Qubit[]) : Int {
        body (...) {
            let pi = 3.141592653589793;
            CNOT(qs[1], qs[0]);
            CNOT(qs[2], qs[0]);
            Rz(4.0 * pi / 3.0, qs[1]);
            Rz(2.0 * pi / 3.0, qs[2]);
            Adjoint ThreePos(qs[1..2]);
            let a = Measure([PauliZ], [qs[1]]);
            let b = Measure([PauliZ], [qs[2]]);
            if (a == Zero && b == Zero) {
                return 0;
            }
            else {
                return 1;
            }
        }
    }
}