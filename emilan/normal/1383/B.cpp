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
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n;
        cin >> n;
        vi bits(31);
        rep(i, n) {
            int x;
            cin >> x;
            rep(j, 31) if (x >> j & 1) bits[j]++;
        }

        int win = 0;
        for (int i = 30; i >= 0; i--) {
            if (bits[i] & 1) {
                if (n & 1 && bits[i] >> 1 & 1) win = -1;
                else win = 1;
                break;
            }
        }

        if (win == 1) cout << "WIN";
        else if (win == 0) cout << "DRAW";
        else cout << "LOSE";
        cout << '\n';
    }

    return 0;
}