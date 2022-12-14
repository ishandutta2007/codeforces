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

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    map<int, int> r;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r[a[i]] = i;
    }

    vt<bool> trap(n);
    for (int i = 0; i < n; i++) {
        for (int j = r[a[i]]; j > i && !trap[j]; j--) {
            trap[j] = true;
        }
    }

    int ans = 1;
    int e = count(all(trap), false) - 1;
    for (int i = 0; i < e; i++) ans = ans * 2 % mod;
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}