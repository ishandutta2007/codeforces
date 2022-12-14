#include <bits/stdc++.h>

using namespace std;

#define vt vector
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    char a[9];
    for (int i = 0; i < 9; i++) cin >> a[i];

    for (int i = 0; i < 9; i++) {
        if (a[i] != a[8 - i]) return void(cout << "NO");
    }

    cout << "YES";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}