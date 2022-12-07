#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int p[100000];
bool vis[100000] = {};
vector<int> cur;
vector<PII> ans;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", p + i), --p[i];
    REP(i, n) if (p[i] == i) {
        printf("YES\n");
        REP(j, n) if (j != i) {
            printf("%d %d\n", i + 1, j + 1);
        }
        return 0;
    }
    REP(i, n) if (p[p[i]] == i) {
        int x = i;
        int y = p[i];
        vis[x] = vis[y] = true;
        ans.pb(mp(x, y));
        REP(j, n) if (!vis[j]) {
            for (int x = j; !vis[x]; x = p[x]) {
                cur.pb(x);
                vis[x] = true;
            }
            if ((int)cur.size() % 2 == 1) {
                printf("NO\n");
                return 0;
            }
            REP(z, cur.size()) if (z & 1) {
                ans.pb(mp(x, cur[z]));
            } else {
                ans.pb(mp(y, cur[z]));
            }
            cur.clear();
        }
        printf("YES\n");
        REP(i, n - 1) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
        return 0;
    }
    printf("NO\n");
    return 0;
}