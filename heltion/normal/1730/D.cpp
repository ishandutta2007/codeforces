#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        map<pair<char, char>, int> mp;
        for (int i = 0; i < n; i += 1)
            mp[{min(s[i], t[n - 1 -i]), max(s[i], t[n - 1 - i])}] += 1;
        int ok = 1, cnt = 0;
        for (auto [x, y] : mp)
            if (y & 1) {
                cnt += 1;
                if (x.first != x.second) ok = 0;
            }
        if (cnt > 1) ok = 0;
        cout << (ok ? "YES\n" : "NO\n");
    }
}