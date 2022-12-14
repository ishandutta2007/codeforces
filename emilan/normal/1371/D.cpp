#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vvi v(n, vi(n));
        
        int i = 0, j = 0;
        rep(r, k) {
            v[i][j] = 1;
            i++, j++;
            if (j == n) j = 0;
            if (i == n) i = 0, j++;
        }

        cout << (k % n ? 2 : 0) << '\n';
        rep(i, n) {
            rep(j, n) cout << v[i][j];
            cout << '\n';
        }
    }


    return 0;
}