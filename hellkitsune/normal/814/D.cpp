#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const double PI = acosl(-1);

int n;
int x[1000], y[1000], r[1000];
int p[1000];
vector<int> g[1000];
LL ans = 0;

LL dist2(int x, int y) {
    return (LL)x * x + (LL)y * y;
}

void dfs(int v, int mul) {
    ans += mul * dist2(r[v], 0);
    for (int to : g[v]) {
        dfs(to, -mul);
    }
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d%d%d", x + i, y + i, r + i);
    forn(i, n) {
        int par = -1;
        forn(j, n) if (j != i) {
            if (r[i] < r[j] && dist2(x[j] - x[i], y[j] - y[i]) <= dist2(r[j] - r[i], 0)) {
                if (par == -1 || r[j] < r[par]) {
                    par = j;
                }
            }
        }
        if (par == -1) {
            ans += dist2(r[i], 0);
        }
        p[i] = par;
        g[par].pb(i);
    }
    forn(i, n) if (p[i] == -1) {
        for (int to : g[i]) {
            dfs(to, 1);
        }
    }
    printf("%.15f\n", (double)ans * PI);
    return 0;
}