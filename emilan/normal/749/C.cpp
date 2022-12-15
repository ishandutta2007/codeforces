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

    int v = 0;
    for (;;) {
        int cnt = count(all(s), 'D');
        if (!cnt || cnt == sz(s)) break;
        for (char &c : s) {
            if (c == 'D') {
                if (v > 0) c = 'X';
                v--;
            } else if (c == 'R') {
                if (v < 0) c = 'X';
                v++;
            }
        }

        s.erase(remove(all(s), 'X'), s.end());
    }

    if (count(all(s), 'D')) cout << 'D';
    else cout << 'R';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}