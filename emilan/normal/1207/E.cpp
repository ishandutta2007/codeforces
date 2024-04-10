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
    cout << '?';
    for (int i = 1; i <= 100; i++) {
        cout << ' ' << 128 * i;
    }
    cout << endl;
    int q1;
    cin >> q1;

    cout << '?';
    for (int i = 1; i <= 100; i++) {
        cout << ' ' << i;
    }
    cout << endl;
    int q2;
    cin >> q2;

    cout << "! " << (q1 & 0x7F | q2 & 0x3F80) << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}