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

set<char> sep{'_', '(', ')'};

void solve() {
    int n;
    string s;
    cin >> n >> s;

    s.insert(s.begin(), '_');
    s += '_';

    bool p = false;
    int len_out = 0, cur_len_out = 0, num_in = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (!p) {
            if (sep.count(s[i])) {
                len_out = max(cur_len_out, len_out);
                cur_len_out = 0;
            } else {
                cur_len_out++;
            }
        } else {
            if (sep.count(s[i - 1]) && !sep.count(s[i])) {
                num_in++;
            }
        }

        if (s[i] == '(') p = true;
        else if (s[i] == ')') p = false;
    }

    cout << len_out << ' ' << num_in;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}