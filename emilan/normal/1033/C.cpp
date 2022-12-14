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

    int n;
    cin >> n;
    vi a(n);
    for (int& i : a) cin >> i;

    vi g(n, -1);
    function<int(int)> dfs = [&](int x) {
        if (g[x] == -1) {
            int mex = 0;
            set<int> s;
            for (int i = x % a[x]; i < n; i += a[x]) {
                if (a[i] > a[x]) s.insert(dfs(i));
            }

            for (int i : s) {
                if (i == mex) mex++;
                else break;
            }
            g[x] = mex;
        }
        return g[x];
    };
    rep(i, n) cout << (dfs(i) ? 'A' : 'B');
}