#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector a(n, vector<int>(k));
    for (auto& ai : a)
        for (int& aij : ai)
            cin >> aij;
    map<vector<int>, int> s;
    for (auto& ai : a) s[ai] = 0;
    for (int i = 0; i < n; i += 1)
        for (int j = i + 1; j < n; j += 1) {
            vector<int> b(k);
            for (int x = 0; x < k; x += 1) {
                b[x] = a[i][x] + a[j][x];
                if (b[x] >= 3) b[x] -= 3;
                if (b[x]) b[x] = 3 - b[x];
            }
            if (s.contains(b)) s[b] += 1;
        }
    LL ans = 0;
    for (auto& [_, c] : s)
        ans += c * (c - 1) / 2;
    cout << ans;
}