#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    string A, B;
    cin >> A >> B;

    int typeA = 0, typeB = 0, typeC = 0;
    for (int i = 0; i < 2 * N; ++i)
        if (A[i] == '1' and B[i] == '1')
            ++typeA;
        else if (A[i] == '1')
            ++typeB;
        else if (B[i] == '1')
            ++typeC;

    if (typeA % 2) {
        ++typeB;
    }

    if (typeB < typeC)
        ++typeB;

    if (typeB == typeC) {
        cout << "Draw\n";
        return 0;
    }

    if (typeB > typeC) {
        cout << "First\n";
        return 0;
    }

    cout << "Second\n";
}