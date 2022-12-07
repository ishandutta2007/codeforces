#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;

struct PII {
    int first, second;
    char c;
    PII(int first, int second, char c) : first(first), second(second), c(c) {}
    PII() {}
};

int x[3], y[3];
char a[333][333];
vector<PII> v;

int main() {
    REP(i, 3) scanf("%d%d", x + i, y + i);
    int s = 0;
    REP(i, 3) s += x[i] * y[i];
    int sq = 0;
    while (sq * sq < s) ++sq;
    if (sq * sq != s) {
        printf("-1\n");
        return 0;
    }
    REP(i, 3) v.pb(PII(x[i], y[i], 'A' + i));
    int n, m;
    n = m = sq;
    int times = 0;
    while (times < 3) {
        bool bad = true;
        for (PII &x : v) if (x.c != 'D' && (x.first == n || x.second == n)) {
            if (x.first != n) swap(x.first, x.second);
            REP(i, n) for (int j = m - x.second; j < m; ++j) {
                a[i][j] = x.c;
            }
            m -= x.second;
            bad = false;
            ++times;
            x.c = 'D';
        } else if (x.c != 'D' && (x.first == m || x.second == m)) {
            if (x.first != m) swap(x.first, x.second);
            for (int i = n - x.second; i < n; ++i) REP(j, m) {
                a[i][j] = x.c;
            }
            n -= x.second;
            bad = false;
            ++times;
            x.c = 'D';
        }
        if (bad) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", sq);
    REP(i, sq) {
        a[i][sq] = '\0';
        printf("%s\n", a[i]);
    }
    return 0;
}