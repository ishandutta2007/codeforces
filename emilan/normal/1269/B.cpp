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

    int n, m;
    cin >> n >> m;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    sort(all(b));

    set<int> s;
    rep(i, n) s.insert((b[i] - a[0] + m) % m);

    for (int i : s) {
        vi t(a);
        rep(j, n) t[j] = (t[j] + i) % m;
        sort(all(t));
        if (t == b) {
            cout << i;
            return 0;
        }
    }

    return 0;
}