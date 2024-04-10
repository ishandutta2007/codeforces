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
    int n;
    string s;
    cin >> n >> s;

    string t;
    for (char c : s) {
        if (c & 1) t += c;
    }

    if (sz(t) & 1) t.pop_back();

    if (t.empty()) cout << -1;
    else cout << t;
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