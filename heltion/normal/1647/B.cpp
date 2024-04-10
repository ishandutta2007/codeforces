#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (auto& si : s) cin >> si;
        int ok = 1;
        for (int i = 0; i + 1 < n; i += 1)
            for (int j = 0; j + 1 < m; j += 1) {
                int p = 0;
                for (int di = 0; di < 2; di += 1)
                    for (int dj = 0; dj < 2; dj += 1)
                        p += s[i + di][j + dj] - '0';
                if (p == 3) ok = 0;
            }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}