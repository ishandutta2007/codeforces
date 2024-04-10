#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        int A, B, C; cin >> A >> B >> C;

        int X = A + B + C;
        int Y = C + B;
        int Z = C;

        assert(X % Y == A);
        assert(Y % Z == B);
        assert(Z % X == C);
        cout << X << " " << Y << " " << Z << "\n";
    }
}