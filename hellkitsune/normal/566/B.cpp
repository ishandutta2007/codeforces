#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[30000][4], b[30000][4], ind[30000][4];
int pos[30000] = {};
bool used[30000][4] = {};
int cnt[30000];
int ord[30001];
vector<int> ans;

int main() {
    scanf("%d", &n);
    REP(i, 4 * n) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z), --x, --y, --z;
        a[x][pos[x]] = y;
        b[x][pos[x]] = z;
        ind[x][pos[x]] = i;
        ++pos[x];
    }
    REP(i, n) cnt[i] = 4;
    while ((int)ans.size() < 4 * n) {
        REP(i, n) ord[i] = i;
        random_shuffle(ord, ord + n);
        for (int ii = 0, i = ord[0]; ii < n; i = ord[++ii]) REP(j, 4) if (!used[i][j]) {
            if (cnt[a[i][j]] + 1 + (a[i][j] == b[i][j]) - (a[i][j] == i) > 9) continue;
            if (cnt[b[i][j]] + 1 - (b[i][j] == i) > 9) continue;
            used[i][j] = true;
            --cnt[i];
            ++cnt[a[i][j]];
            ++cnt[b[i][j]];
            ans.pb(ind[i][j] + 1);
        }
    }
    printf("YES\n");
    REP(i, 4 * n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}