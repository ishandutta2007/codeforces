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

int a[2], b[2];

void solve() {
    string s;
    cin >> s;

    ll odd = 0, even = 0;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == 'a') {
            a[i & 1]++;

            odd += a[i & 1];
            even += a[i & 1 ^ 1];
        }
        else {
            b[i & 1]++;

            odd += b[i & 1];
            even += b[i & 1 ^ 1];
        }
    }

    cout << even << ' ' << odd;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}