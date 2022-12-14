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

    int r = sz(s) / n;
    auto die = [&]() {
        for (int i = 0; i < r + 1; i++) {
            cout << '1' << string(n - 1, '0');
        }
        exit(0);
    };

    if (sz(s) % n) die();

    string t = s.substr(0, n), u;
    for (int i = 0; i < r - 1; i++) u += t;

    if (s.substr(n) < u) cout << u + t;
    else {
        t.back()++;
        for (int i = sz(t) - 1; i && t[i] > '9'; i--) {
            t[i] = '0';
            t[i - 1]++;
        }

        if (t[0] > '9') die();
        else {
            for (int i = 0; i < r; i++) {
                cout << t;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}