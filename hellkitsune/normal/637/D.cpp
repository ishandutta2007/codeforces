#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, s, d;
int a[200005], pre[200005];
const int INF = 2e9 + 111;
vector<int> p;
bool bad[200005] = {};

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &s, &d);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    a[0] = -1;
    REP(i, n) bad[i] = a[i] + 1 + s >= a[i + 1];
    if (bad[0]) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    p.pb(0);
    for (int i = 0; i < n; ) {
        int from = a[i + 1] - 1;
        p.pb(from);
        int ni = -1;
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] + 1 - from > d) break;
            if (!bad[j]) ni = j;
        }
        if (ni == -1) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        i = ni;
        p.pb(a[i] + 1);
    }
    REP(i, (int)p.size() - 1) {
        if (i & 1) {
            assert(p[i + 1] - p[i] <= d);
            printf("JUMP %d\n", p[i + 1] - p[i]);
        } else {
            assert(p[i + 1] - p[i] >= s);
            printf("RUN %d\n", p[i + 1] - p[i]);
        }
    }
    if (p.back() < m) {
        printf("RUN %d\n", m - p.back());
    }
    return 0;
}