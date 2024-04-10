#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

inline LL p3(LL x) {
    return x * x * x;
}

pair<int, LL> solve(LL x) {
    if (x < 8) {
        return mp(x, x);
    }
    int rt = pow(x, 1.0 / 3);
    while (p3(rt) > x) {
        --rt;
    }
    while (p3(rt + 1) <= x) {
        ++rt;
    }
    pair<int, LL> res = solve(x - p3(rt));
    ++res.first;
    res.second += p3(rt);
    if (rt > 1) {
        --rt;
        pair<int, LL> res2 = solve(min(x, p3(rt + 1) - 1) - p3(rt));
        ++res2.first;
        res2.second += p3(rt);
        res = max(res, res2);
    }
    return res;
}

int main() {
    LL mx;
    cin >> mx;
    pair<int, LL> res = solve(mx);
    cout << res.first << ' ' << res.second << endl;
    return 0;
}