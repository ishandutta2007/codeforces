#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL s;

LL tot = 0, ans = 0;

LL d[15][15][40000];

LL solve(int a, int b, LL s) {
    if (s < 0) {
        return 0;
    }
    if (s == 0) {
        return 1;
    }
    if ((2ll << a) - a + (2ll << b) - b - 4 < s) {
        return 0;
    }
    if (a == 0) {
        return 0;
    }
    bool ok = (a < 15 && b < 15 && s < 40000);
    if (ok && d[a][b][s] != -1) {
        return d[a][b][s];
    }
    if (a == b) {
        LL res = solve(a - 1, b - 1, s) + 2ll * solve(a - 1, b - 1, s - (1ll << a) + 1) + solve(a - 1, b - 1, s - (2ll << a) + 2);
        if (ok) d[a][b][s] = res;
        return res;
    }
    LL res = solve(a - 1, b, s - (1ll << a) + 1) + solve(a - 1, b, s);
    if (ok) d[a][b][s] = res;
    return res;
}

LL calc(LL x, int h) {
    LL res = x;
    forn(i, h) {
        x >>= 1;
        res += x;
    }
    return res;
}

int main() {
    memset(d, -1, sizeof d);
    //freopen("input.txt", "r", stdin);
    cin >> s;
    for (int i = 1; i <= 55; ++i) {
        for (int j = 1; j <= 55; ++j) {
            LL x = 2 * ((1ll << i) + (1ll << j) - 2) + 1;
            LL mn = (1ll << j) - 1;
            LL mx = mn + (1ll << i) - i + (1ll << j) - j - 2;
            mn = s - mn;
            mx = s - mx;
            swap(mn, mx);
            mn = max(mn, x);
            if (mx < x) {
                continue;
            }
            mx /= x;
            mn = (mn + x - 1) / x;
            tot += max(0ll, mx - mn + 1);
            for (LL a = mn; a <= mx; ++a) {
                LL b = s - a * x - (1ll << j) + 1;
                ans += solve(max(i - 1, j - 1), min(i - 1, j - 1), b);
                cerr << i << ' ' << j << ' ' << a << ": " << ans << endl;
            }
        }
    }
    cerr << ans << endl;
    //cerr << tot << endl;
    forn(h, 55) {
        LL lo = (1ll << h), hi = s, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            LL x = calc(mid, h);
            if (x >= s) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (calc(lo, h) == s) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}