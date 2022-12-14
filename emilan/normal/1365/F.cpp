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

void solve(int tc) {
    int n;
    cin >> n;
    vt<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    if (n & 1 && a[n / 2] != b[n / 2]) return void(cout << "no\n");

    vt<pii> pa(n / 2), pb(n / 2);
    for (int i = 0; i < n / 2; i++) {
        pa[i] = {min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1])};
        pb[i] = {min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1])};
    }
    sort(all(pa));
    sort(all(pb));

    if (pa == pb) cout << "yes\n";
    else cout << "no\n";
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}