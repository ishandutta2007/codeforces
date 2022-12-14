#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for (auto& i : v) cin >> i;

        int cnt = 0;
        rep(i, m - 1) if (v[n - 1][i] != 'R') cnt++;
        rep(i, n - 1) if (v[i][m - 1] != 'D') cnt++;

        cout << cnt << '\n';
    }

    return 0;
}