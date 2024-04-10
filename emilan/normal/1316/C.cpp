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
    int n, m, p;
    cin >> n >> m >> p;
    vt<int> a(n), b(m);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;

    int i = 0, j = 0;
    for (; a[i] % p == 0; i++);
    for (; b[j] % p == 0; j++);

    cout << i + j << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}