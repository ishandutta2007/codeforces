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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int init_wins = count(all(s), 'W');
    if (init_wins + k >= n) return void(cout << 2 * n - 1 << '\n');

    vt<int> l(n);
    bool first_win = false;
    int cur_len = 0;
    for (char c : s) {
        if (c == 'W') {
            if (!first_win) first_win = true;
            else l[cur_len]++;
            cur_len = 0;
        } else if (first_win) cur_len++;
    }

    int score = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            score++;
            if (i && s[i - 1] == 'W') score++;
        }
    }

    for (int i = 1; i < n; i++) {
        int full = min(l[i], k / i);
        k -= full * i;
        score += full + full * i * 2;
    }

    score += k * 2;
    if (init_wins == 0 && score) score--;
    cout << score << '\n';
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