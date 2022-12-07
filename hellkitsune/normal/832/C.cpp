#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, s;
int x[100000], v[100000], t[100000];
int a[1000001], b[1000001];

bool solve(double mx) {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    forn(i, n) {
        int lo = -1, hi = 1000000, mid;
        int dist = (t[i] == 1 ? x[i] : 1000000 - x[i]);
        if (v[i] * mx >= dist) {
            if (t[i] == 1) {
                ++a[0];
                --a[1000000];
            } else {
                ++b[0];
                --b[1000000];
            }
            continue;
        }
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            double can = v[i] * mx + s * max(0.0, mx - (double)mid / (s - v[i]));
            if (can >= dist) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        if (lo >= 0) {
            if (t[i] == 1) {
                ++a[x[i]];
                --a[min(1000000, x[i] + lo + 1)];
            } else {
                ++b[max(0, x[i] - lo)];
                --b[x[i] + 1];
            }
        }
    }
    int ra = 0;
    int rb = 0;
    forn(i, 1000000) {
        ra += a[i];
        rb += b[i];
        if (ra > 0 && rb > 0) {
            return true;
        }
    }
    return false;
}

int main() {
    if (0) {
        mt19937 mt(123);
        n = 100000;
        s = 12;
        forn(i, n) {
            x[i] = mt() % 800000 + 100000;
            v[i] = mt() % 9 + 1;
            t[i] = mt() % 2 + 1;
        }
    } else {
        scanf("%d%d", &n, &s);
        forn(i, n) scanf("%d%d%d", x + i, v + i, t + i);
    }
    double lo = 0, hi = 1e6, mid;
    forn(i, 50) {
        mid = 0.5 * (lo + hi);
        if (solve(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%.12f\n", 0.5 * (lo + hi));
    return 0;
}