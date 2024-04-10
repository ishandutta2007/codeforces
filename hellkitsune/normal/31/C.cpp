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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int l[5000], r[5000];
bool bad[5000][5000] = {};
int cnt = 0;
vector<int> ans;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", l + i, r + i);
    REP(i, n) for (int j = i + 1; j < n; ++j) {
        bad[i][j] = bad[j][i] = l[i] < r[j] && l[j] < r[i];
        if (bad[i][j]) ++cnt;
    }
    REP(i, n) {
        int cur = 0;
        REP(j, n) if (bad[i][j])
            ++cur;
        if (cur == cnt) ans.pb(i + 1);
    }
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}