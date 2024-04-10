#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vt<int> a(n), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    for (int i = 0; i < 1 << 9; i++) {
        bool ok1 = true;
        for (int &j : a) {
            bool ok2 = false;
            for (int &k : b) {
                if ((j & k & ~i) == 0) ok2 = true;
            }
            if (!ok2) ok1 = false;
        }

        if (ok1) return cout << i, 0;
    }
}