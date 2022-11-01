namespace Solution {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;

    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        let n = Length(register!);
        if (n >= 2) {
            for (i in n - 1 .. -1 .. 1) {
                Controlled X(register![0 .. i - 1], register![i]);
            }
        }
        X(register![0]);
    }
}