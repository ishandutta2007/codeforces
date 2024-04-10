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
    int n, b, a;
    cin >> n >> b >> a;
    vt<int> s(n);
    for (int &x : s) cin >> x;

    int c = a;
    for (int i = 0; i < n; i++) {
        if (!b && !c) return void(cout << i);

        if (s[i] && b && c != a) b--, c++;
        else if (c) c--;
        else b--;
    }

    cout << n;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}