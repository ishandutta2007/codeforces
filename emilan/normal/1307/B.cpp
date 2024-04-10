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
    int n, x;
    cin >> n >> x;
    vt<int> a(n);
    for (int &z : a) cin >> z;
    int d = *max_element(all(a));

    if (count(all(a), x)) cout << 1;
    else if (d * 2 >= x) cout << 2;
    else cout << (x + d - 1) / d;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}