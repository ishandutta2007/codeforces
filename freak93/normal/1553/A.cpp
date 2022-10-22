#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        cout << (N + 1) / 10 << "\n";
    }
}