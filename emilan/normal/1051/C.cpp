#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vi a(n), f(101);
    int cnt1 = 0, cnt3 = 0;
    rep(i, n) {
        cin >> a[i];
        f[a[i]]++;
        if (f[a[i]] == 1) cnt1++;
        else if (f[a[i]] == 2) cnt1--;
        else if (f[a[i]] == 3) cnt3++;
    }

    if (~cnt1 & 1 || cnt3) {
        cout << "YES\n";
        int rem = cnt1 / 2, h = cnt1 & 1;
        rep(i, n) {
            if (h && f[a[i]] > 2) h--, cout << 'B';
            else if (rem && f[a[i]] == 1) rem--, cout << 'B';
            else cout << 'A';
        }
    } else cout << "NO";
}