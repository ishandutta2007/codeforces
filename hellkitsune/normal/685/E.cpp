#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, q;
int from[200000], to[200000];
int l[200000], r[200000], s[200000], t[200000];
bool ans[200000];
vector<int> inds[200000];
int d[1000][1000];
const int INF = 1e9;

int main() {
    scanf("%d%d%d", &n, &m, &q);
    REP(i, m) {
        scanf("%d%d", from + i, to + i);
        --from[i];
        --to[i];
    }
    REP(i, q) {
        scanf("%d%d%d%d", l + i, r + i, s + i, t + i);
        --l[i];
        --r[i];
        --s[i];
        --t[i];
        inds[l[i]].pb(i);
    }
    REP(i, n) REP(j, n) d[i][j] = INF;
    for (int i = m - 1; i >= 0; --i) {
        int a = from[i];
        int b = to[i];
        REP(j, n) {
            d[a][j] = d[b][j] = min(d[a][j], d[b][j]);
        }
        d[a][b] = d[b][a] = i;
        for (int ind : inds[i]) {
            ans[ind] = d[s[ind]][t[ind]] <= r[ind];
        }
    }
    REP(i, q) if (ans[i]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}