#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int r[200005];
vector<int> g[200005];
int ord[200005];
int ans[200005];

inline bool cmp(const int &lhs, const int &rhs) {
    return r[lhs] < r[rhs];
}

int main() {
    scanf("%d%d", &n, &k);
    forn(i, n) {
        scanf("%d", r + i);
    }
    forn(i, k) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    forn(i, n) {
        ord[i] = i;
    }
    sort(ord, ord + n, cmp);
    int res = 0;
    int pre = -1;
    forn(ii, n) {
        int i = ord[ii];
        if (r[i] > pre) {
            pre = r[i];
            res = ii;
        }
        int sub = 0;
        for (int to : g[i]) {
            if (r[i] > r[to]) {
                ++sub;
            }
        }
        ans[i] = res - sub;
    }
    forn(i, n) {
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}