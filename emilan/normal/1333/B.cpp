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

#define die return void(cout << "NO\n")

void solve() {
    int n;
    cin >> n;
    vt<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    bool plus = false, minus = false;
    for (int i = 0; i < n; i++) {
        if (!plus && a[i] < b[i]) die;
        if (!minus && a[i] > b[i]) die;

        if (a[i] == 1) plus = true;
        else if (a[i] == -1) minus = true;
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}