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

    vt<int> right(n, -1), left(n, -1);
    int last = 0;
    for (int i = 0; i < n * 2; i++) {
        if (s[i % n] == '<') {
            for (int j = last; j <= i; j++) {
                right[j % n] = i % n;
            }
            last = i + 1;
        }
    }

    last = n * 2;
    for (int i = n * 2; i; i--) {
        if (s[(i - 1) % n] == '>') {
            for (int j = last; j >= i; j--) {
                left[j % n] = i % n;
            }
            last = i - 1;
        }
    }

    int ans = n;
    for (int i = 0; i < n; i++) {
        if (s[(i + n - 1) % n] != '-'
                && s[i] != '-'
                && ~left[i] && ~right[i]) {
            ans--;
        }
    }

    cout << ans << '\n';
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