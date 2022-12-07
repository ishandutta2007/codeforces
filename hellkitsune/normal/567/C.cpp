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

vector<int> se;
map<int, int> ma;
int sz;
vector<int> pos[200000];
int n, k;
int a[200000];
const int MX = 1e9;

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) {
        scanf("%d", a + i);
        se.pb(a[i]);
    }
    sort(se.begin(), se.end());
    se.erase(unique(se.begin(), se.end()), se.end());
    sz = (int)se.size();
    REP(i, sz) ma[se[i]] = i;
    REP(i, n) a[i] = ma[a[i]];
    REP(i, n) pos[a[i]].pb(i);
    LL ans = 0;
    REP(i, n) {
        int x = se[a[i]];
        if (x % k == 0 && (abs((LL)x * k) <= MX)) {
            int pr = x / k;
            int nx = x * k;
            auto it = ma.find(pr);
            if (it == ma.end()) continue;
            pr = it->second;
            it = ma.find(nx);
            if (it == ma.end()) continue;
            nx = it->second;
            int cntL = lower_bound(pos[pr].begin(), pos[pr].end(), i) - pos[pr].begin();
            int cntR = lower_bound(pos[nx].begin(), pos[nx].end(), i + 1) - pos[nx].begin();
            cntR = (int)pos[nx].size() - cntR;
            ans += (LL)cntL * cntR;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}