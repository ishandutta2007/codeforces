#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    string S; cin >> S;

    cout << "Mike\n"; // can't win on first
    char lowest = S[0];
    for (int i = 1; i < int(S.size()); ++i) {
        lowest = min(lowest, S[i]);
        if (lowest == S[i])
            cout << "Mike\n";
        else
            cout << "Ann\n";
    }
}