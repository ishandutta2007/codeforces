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

const int inf = 1 << 30;

void solve() {
    int n, q;
    cin >> n >> q;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    vt<int> st(n), en(n);
    int p = -1, pp = -1, num = 0;
    for (int i = 0; i < n; i++) {
        if (~pp && a[pp] > a[p] && a[p] < a[i]) {
            num++;

            for (int j = p; j < i; j++) {
                st[j] = num;
            }
        }

        st[i] = en[i] = num;

        if (!~p || a[i] != a[p]) {
            pp = p;
            p = i;
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if (st[l] < en[r]) cout << "No\n";
        else cout << "Yes\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}