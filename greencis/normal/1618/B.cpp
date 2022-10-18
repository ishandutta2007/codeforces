#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int z = 0; z < t; ++z) {
        int n; cin >> n;
        vector<string> v(n - 2);
        for (int i = 0; i < n - 2; ++i) {
            cin >> v[i];
        }
        if (n == 3) cout << v[0] << "a\n";
        else {
            int idx = 0;
            for (int i = 0; i + 1 < n - 2; ++i) {
                if (v[i][1] != v[i + 1][0]) {
                    idx = i;
                    break;
                }
            }
            auto print = [&](int L, int R) {
                cout << v[L][0];
                for (int i = L; i <= R; ++i)
                    cout << v[i][1];
            };
            print(0, idx);
            print(idx + 1, n - 3);
            cout << '\n';
        }
    }
}