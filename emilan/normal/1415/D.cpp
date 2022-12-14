#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    for (int i = 2; i < n; i++) {
        if (__lg(a[i - 2]) == __lg(a[i - 1])
                && __lg(a[i - 1]) == __lg(a[i])) {
            return void(cout << 1);
        }
    }

    int ans = n;
    for (int l = 0; l < n; l++) {
        for (int m = l + 1; m < n; m++) {
            for (int r = m + 1; r <= n; r++) {
                int xum1 = accumulate(
                    a.begin() + l,
                    a.begin() + m,
                    0,
                    bit_xor<int>()
                );
                int xum2 = accumulate(
                    a.begin() + m,
                    a.begin() + r,
                    0,
                    bit_xor<int>()
                );

                if (xum1 > xum2) {
                    ans = min(r - l - 2, ans);
                }
            }
        }
    }

    cout << (ans == n ? -1 : ans);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}