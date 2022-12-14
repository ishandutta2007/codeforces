#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define pb          push_back
#define eb          emplace_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    rep(i, n) {
        rep(j, n) {
            if (!i && !j || j & 1) cout << "0 ";
            else cout << (1ll << i + j - 1) << ' ';
        }
        cout << endl;
    }
    
    int q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        
        int i = 0, j = 0;
        cout << "1 1" << endl;
        rep(r, 2 * n - 2) {
            if (x >> r & 1) {
                if (j & 1) j++;
                else i++;
            } else {
                if (j & 1) i++;
                else j++;
            }
            cout << i + 1 << ' ' << j + 1 << endl;
        }
    }
}