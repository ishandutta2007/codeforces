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

    int q;
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int z = 0, o = 0;
        bool ok = false;
        rep(i, n) {
            if (s[i] == '1') o++;
            else {
                if (k >= o) k -= o, z++;
                else {
                    ok = true;
                    cout << string(z, '0')
                         << string(o - k, '1') << '0'
                         << string(k, '1')
                         << string(s.begin() + i + 1, s.end());
                    break;
                }
            }
        }
        if (!ok) cout << string(z, '0') << string(o, '1');
        cout << '\n';
    }

    return 0;
}