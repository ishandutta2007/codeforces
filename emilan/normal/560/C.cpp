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

int sq(int x) { return x * x; }

void solve() {
    vt<int> a(6);
    for (int &i : a) cin >> i;
    cout << (sq(a[0] + a[1] + a[2]) - sq(a[0]) - sq(a[2]) - sq(a[4]));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}