#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

int solve() {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;

    if (c == 'g') return 0;

    s += s;

    int ans = 0;
    int cur = -1;
    for (int i = 0; i < 2 * n; i++) {
        if (cur == -1 && s[i] == c) cur = 0;
        else if (s[i] == 'g') {
            ans = max(ans, cur);
            cur = -1;
        }

        if (cur != -1) cur++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << solve() << '\n';
    }
}