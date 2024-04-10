#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        string S; cin >> S;
        if (S.size() == 2)
            cout << S[1] << "\n";
        else
            cout << *min_element(S.begin(), S.end()) << "\n";
    }
}