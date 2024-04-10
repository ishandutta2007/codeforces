#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> vs(n);
    for (auto& s : vs)
        cin >> s;
    auto r = "theseus";
    for (int i = 0; i < n; i += 1)
        for (int j = 0; j < n; j += 1) {
            if (j + 7 <= n) {
                int ok = 1;
                for (int k = 0; k < 7; k += 1)
                    if (vs[i][j + k] != r[k])
                        ok = 0;
                if (ok) {
                    cout << "YES";
                    return 0;
                }
            }
            if (i + 7 <= n) {
                int ok = 1;
                for (int k = 0; k < 7; k += 1)
                    if (vs[i + k][j] != r[k])
                        ok = 0;
                if (ok) {
                    cout << "YES";
                    return 0;
                }
            }
            if (i + 7 <= n and j + 7 <= n) {
                int ok = 1;
                for (int k = 0; k < 7; k += 1)
                    if (vs[i + k][j + k] != r[k])
                        ok = 0;
                if (ok) {
                    cout << "YES";
                    return 0;
                }
            }
        }
    cout << "NO";
    return 0;
}