#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL m;

LL solve(LL n) {
    LL res = 0;
    for (LL k = 2; ; ++k) {
        LL x = k * k * k;
        if (x > n) break;
        res += n / x;
    }
    return res;
}

int main() {
    cin >> m;
    LL lo = 1, hi = 1e18, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (solve(mid) < m) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    if (solve(lo) != m) {
        cout << -1 << endl;
    } else {
        cout << lo << endl;
    }
    return 0;
}