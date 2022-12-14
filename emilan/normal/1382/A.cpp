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
        set<int> a;
        rep(i, n) {
            int x;
            cin >> x;
            a.insert(x);
        }

        int ans = 0;
        rep(i, m) {
            int x;
            cin >> x;
            if (!ans && a.count(x)) ans = x;
        }

        if (ans) cout << "YES\n1 " << ans << '\n';
        else cout << "NO\n";
    }

    return 0;
}