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

int n, m, s, e;
int a[100000], b[100000];
vector<int> pos[100000];
int d[100001], nd[100001];

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &e);
    REP(i, n) scanf("%d", a + i), --a[i];
    REP(i, m) scanf("%d", b + i), --b[i];
    REP(i, m) pos[b[i]].pb(i);
    REP(i, n + 1) d[i] = m;
    d[0] = 0;
    int ans = 0;
    while (true) {
        int mn = m;
        REP(i, n + 1) nd[i] = m;
        bool ok = false;
        REP(i, n) {
            mn = min(mn, d[i]);
            if (mn == m) continue;
            auto it = lower_bound(pos[a[i]].begin(), pos[a[i]].end(), mn);
            if (it != pos[a[i]].end()) {
                nd[i + 1] = *it + 1;
                if (e * (ans + 1) + i + *it + 2 <= s) {
                    ok = true;
                }
            }
        }
        if (ok) ++ans;
        else break;
        REP(i, n + 1) d[i] = nd[i];
    }
    printf("%d\n", ans);
    return 0;
}