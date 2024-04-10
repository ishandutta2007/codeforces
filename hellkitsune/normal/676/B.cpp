#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<LL, LL> PII;

int n, t;
PII a[15][15] = {};

void add(PII &x, PII y) {
    while (x.second < y.second) {
        x.first *= 2;
        x.second *= 2;
    }
    while (y.second < x.second) {
        y.first *= 2;
        y.second *= 2;
    }
    x.first += y.first;
    while (x.first % 2 == 0 && x.second % 2 == 0) {
        x.first >>= 1;
        x.second >>= 1;
    }
}

int main() {
    scanf("%d%d", &n, &t);
    a[0][0].first = t;
    REP(i, 15) REP(j, 15) a[i][j].second = 1;
    int ans = 0;
    REP(i, n) REP(j, i + 1) if (a[i][j].first >= a[i][j].second) {
        ++ans;
        a[i][j].first -= a[i][j].second;
        PII p = a[i][j];
        if (p.first % 2 == 0) {
            p.first /= 2;
        } else {
            p.second *= 2;
        }
        add(a[i + 1][j], p);
        add(a[i + 1][j + 1], p);
    }
    printf("%d\n", ans);
    return 0;
}