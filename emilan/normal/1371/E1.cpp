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

    int n, p;
    cin >> n >> p;
    vi a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    vi ans;
    for (int i = a.back() - n + 1; i < a.back(); i++) {
        int cur = 0;
        bool ok = true;
        for (int j = 0; j < n; j++) {
            while (cur != n && i + j >= a[cur]) cur++;
            if ((cur - j) % p == 0) ok = false;
        }

        if (ok) ans.pb(i);
    }

    cout << sz(ans) << '\n';
    for (int i : ans) cout << i << ' ';

    return 0;
}