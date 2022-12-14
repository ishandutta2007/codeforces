#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) []{
        int n;
        string s;
        cin >> n >> s;
        
        int lz, to;
        for (lz = 0; lz < n; lz++) if (s[lz] == '1') break;
        for (to = 0; to < n; to++) if (s[n - to - 1] == '0') break;

        cout << string(lz + (lz + to != n), '0')
             << string(to, '1') << '\n';
    }();
}