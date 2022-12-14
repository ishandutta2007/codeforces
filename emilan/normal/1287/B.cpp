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

    int n, k;
    cin >> n >> k;
    vector<string> v(n);
    map<string, int> m;
    rep(i, n) {
        cin >> v[i];
        m[v[i]]++;
    }

    ll cnt = 0;
    rep(i, n) {
        m[v[i]]--;

        for (int j = i + 1; j < n; j++) {
            m[v[j]]--;

            string s;
            rep(r, k) {
                if (v[i][r] == v[j][r]) s.pb(v[i][r]);
                else if (v[i][r] != 'S' && v[j][r] != 'S') s.pb('S');
                else if (v[i][r] != 'E' && v[j][r] != 'E') s.pb('E');
                else if (v[i][r] != 'T' && v[j][r] != 'T') s.pb('T');
            }
            
            if (m.count(s)) cnt += m[s];
            m[v[j]]++;
        }
    }

    cout << cnt / 2;

    return 0;
}