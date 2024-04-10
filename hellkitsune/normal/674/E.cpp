#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MX = 41;

int q;
int par[500005];
double a[500005][MX + 1] = {};
int n = 1;

void solve(int v) {
    int u = par[v];
    double old[MX + 1], nold[MX + 1];

    REP(i, MX + 1) old[i] = a[u][i];
    a[u][1] *= 0.5;

    v = u;
    for (int i = 2; i < MX + 1; ++i) {
        if (v == 0) break;
        u = par[v];
        REP(j, MX + 1) nold[j] = a[u][j];
        for (int j = MX; j > 0; --j) {
            a[u][j] *= (0.5 + 0.5 * a[v][j - 1]) / (0.5 + 0.5 * old[j - 1]);
        }
        memcpy(old, nold, sizeof old);
        v = u;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &q);
    a[0][0] = 0;
    for (int i = 1; i <= MX; ++i) a[0][i] = 1;
    REP(times, q) {
        int qt, v;
        scanf("%d%d", &qt, &v), --v;
        if (qt == 1) {
            par[n] = v;
            solve(n);
            a[n][0] = 0;
            for (int i = 1; i <= MX; ++i) a[n][i] = 1;
            ++n;
        } else {
            double ans = 0;
            double pre = 0;
            for (int i = MX; i >= 1; --i) {
                ans += (1 - a[v][i] - pre) * i;
                pre = 1 - a[v][i];
            }
            printf("%.12f\n", ans);
        }
    }
    return 0;
}