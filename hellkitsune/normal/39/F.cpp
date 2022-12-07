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

int n, m, k;
int d[100], pos[100];
int best = 1001;
vector<int> ans;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, m) scanf("%d", d + i);
    REP(i, k) scanf("%d", pos + i);
    REP(i, m) {
        int di = d[i];
        int cnt = 0;
        REP(j, k) if (pos[j] % di == 0) {
            ++cnt;
        }
        if (cnt < best) {
            best = cnt;
            ans.clear();
        }
        if (cnt == best) {
            ans.pb(i + 1);
        }
    }
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}