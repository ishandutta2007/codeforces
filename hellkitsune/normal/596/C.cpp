#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int Z = 100002, ALL = 200005;
int n;
vector<PII> a[ALL];
vector<int> b[ALL];
map<PII, int> ma;
PII ans[100000];

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[y - x + Z].pb(mp(x, y));
    }
    REP(i, n) {
        int z;
        scanf("%d", &z);
        b[z + Z].pb(i);
    }
    REP(i, ALL) if (a[i].size() != b[i].size()) {
        printf("NO\n");
        return 0;
    }
    REP(i, ALL) sort(a[i].begin(), a[i].end());
    REP(i, ALL) REP(j, a[i].size()) {
        ma[mp(a[i][j].first, a[i][j].second)] = b[i][j];
    }
    REP(i, 100001) REP(j, 100001) {
        auto it = ma.find(mp(i, j));
        if (it == ma.end()) break;
        if (i && ma[mp(i - 1, j)] > it->second) {
            printf("NO\n");
            return 0;
        }
        if (j && ma[mp(i, j - 1)] > it->second) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    REP(i, ALL) REP(j, a[i].size()) {
        ans[b[i][j]] = a[i][j];
    }
    REP(i, n) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}