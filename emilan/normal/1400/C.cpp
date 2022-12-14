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
    string s;
    int x;
    cin >> s >> x;

    string w(sz(s), '1');
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '0') {
            if (i + x < sz(s)) w[i + x] = '0';
            if (i - x >= 0) w[i - x] = '0';
        }
    }

    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '1') {
            bool ok = false;
            if (i + x < sz(s) && w[i + x] == '1') ok = true;
            if (i - x >= 0 && w[i - x] == '1') ok = true;
            if (!ok) return void(cout << "-1\n");
        }
    }

    cout << w << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}