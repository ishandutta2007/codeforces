#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

int n, p, q;
PDD a[100000];

inline bool cmp(const PDD &lhs, const PDD &rhs) {
    return lhs.first > rhs.first;
}

double solve(int ind, double len) {
    double pp = max(0.0, 1 - len * a[ind].first);
    double qq = max(0.0, 1 - len * a[ind].second);
    int lo = 0, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (pp * a[mid].second > qq * a[mid].first) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    double len2 = 1e20;
    for (int i = max(0, lo - 1); i <= min(n - 1, lo); ++i) {
        len2 = min(len2, max(pp / a[i].first, qq / a[i].second));
    }
    return len + len2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &p, &q);
    REP(i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i].first = (double)x / p;
        a[i].second = (double)y / q;
    }
    sort(a, a + n, cmp);
    int cnt = 1;
    for (int i = 1; i < n; ++i) if (a[i].second > a[cnt - 1].second) {
        a[cnt] = a[i];
        ++cnt;
    }
    n = cnt;
    double ans = 1e20;
    REP(i, n) ans = min(ans, max(1.0 / a[i].first, 1.0 / a[i].second));
    REP(i, n) {
        double lo = 0, hi = max(1.0 / a[i].first, 1.0 / a[i].second);
        REP(times, 70) {
            double m1 = (2 * lo + hi) / 3;
            double m2 = (lo + 2 * hi) / 3;
            if (solve(i, m1) < solve(i, m2)) {
                hi = m2;
            } else {
                lo = m1;
            }
        }
        ans = min(ans, solve(i, lo));
    }
    printf("%.12f\n", ans);
    return 0;
}