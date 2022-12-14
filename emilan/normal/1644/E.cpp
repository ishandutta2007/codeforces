#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define REP1(i, n)  for (int i = 1; (i) <= (n); (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

ll solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    if (s[0] == 'R') {
        for (char &c : s) c = c == 'D' ? 'R' : 'D';
    }

    ll x = 0, y = 0;
    ll a = -1, b = -1;
    int t = 0;
    REP(i, SZ(s)) {
        if (s[i] == 'D') x++;
        else y++;

        if (i < SZ(s) - 1 && s[i] != s[i + 1]) {
            t++;
            if (t == 2) a = x, b = y;
        }
    }

    if (t >= 1) {
        if (t == 1) a = x, b = y;
        return SZ(s) + 1
            + (y + 1) * (n - x - 1)
            + (n - a) * (n - y - 1);
    } else {
        return n;
    }
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