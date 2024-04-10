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

    bitset<4001> bs;

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n;
        cin >> n;
        vi a(2 * n);
        rep(i, 2 * n) cin >> a[i];

        vi cnt{1};
        int cur = a[0];
        for (int i = 1; i < 2 * n; i++) {
            if (a[i] < cur) cnt.back()++;
            else cnt.pb(1), cur = a[i];
        }

        bs[0] = 1;
        for (int i : cnt) bs = bs << i | bs;

        if (bs[n]) cout << "YES\n";
        else cout << "NO\n";

        rep(i, 2 * n + 1) bs.reset(i);
    }

    return 0;
}