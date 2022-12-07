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

int n, k;
int res[300000], ord[300000];
int a[100000], b[100000], c[100000];
bool busy[300000] = {};
vector<int> ans, bu;

int main() {
    scanf("%d", &n);
    REP(i, 3 * n) scanf("%d", ord + i), --ord[i];
    REP(i, 3 * n) res[ord[i]] = i;
    REP(i, n) scanf("%d%d%d", a + i, b + i, c + i), --a[i], --b[i], --c[i];
    REP(i, n) {
        if (res[a[i]] > res[b[i]]) swap(a[i], b[i]);
        if (res[a[i]] > res[c[i]]) swap(a[i], c[i]);
        if (res[b[i]] > res[c[i]]) swap(b[i], c[i]);
    }
    scanf("%d", &k), --k;
    REP(i, n) if (a[i] == k) {
        REP(j, n) if (res[a[j]] < res[a[i]]) {
            busy[a[j]] = busy[b[j]] = busy[c[j]] = true;
        }
        REP(j, 3 * n) if (busy[j]) bu.pb(j);
        ans.pb(b[i]);
        ans.pb(c[i]);
        if (b[i] > c[i]) swap(ans[0], ans[1]);
        REP(j, 3 * n) if (!busy[j] && a[i] != j && b[i] != j && c[i] != j) {
            ans.pb(j);
        }
        int apos = 0, bpos = 0, asz = (int)ans.size(), bsz = (int)bu.size();
        while (apos < asz || bpos < bsz) {
            if (apos < asz && (bpos == bsz || ans[apos] < bu[bpos])) {
                printf("%d ", ans[apos++] + 1);
            } else {
                printf("%d ", bu[bpos++] + 1);
            }
        }
        printf("\n");
        return 0;
    }
    REP(i, 3 * n) if (i != k) printf("%d ", i + 1);
    printf("\n");
    return 0;
}