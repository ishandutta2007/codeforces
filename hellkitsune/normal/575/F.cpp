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

int n, x;
int from[5000], to[5000];
vector<int> pos;
LL d[10005], nd[10005];
int sz;
const LL INF = 1e15;

inline int ind(int x) {
    return lower_bound(pos.begin(), pos.end(), x) - pos.begin();
}

int main() {
    scanf("%d%d", &n, &x);
    REP(i, n) scanf("%d%d", from + i, to + i);
    pos.pb(x);
    REP(i, n) pos.pb(from[i]), pos.pb(to[i]);
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    sz = (int)pos.size();
    REP(i, sz) d[i] = INF;
    d[ind(x)] = 0;
    REP(j, n) {
        REP(i, sz) nd[i] = INF;
        LL tmp = 2 * INF;
        REP(i, sz) {
            tmp = min(tmp, d[i] - pos[i]);
            nd[i] = min(nd[i], tmp + pos[i]);
        }
        tmp = 2 * INF;
        for (int i = sz - 1; i >= 0; --i) {
            tmp = min(tmp, d[i] + pos[i]);
            nd[i] = min(nd[i], tmp - pos[i]);
        }
        REP(i, sz) {
            if (pos[i] < from[j]) {
                nd[i] += from[j] - pos[i];
            } else if (pos[i] > to[j]) {
                nd[i] += pos[i] - to[j];
            }
        }
        REP(i, sz) d[i] = nd[i];
    }
    LL ans = INF;
    REP(i, sz) ans = min(ans, d[i]);
    cout << ans << endl;
    return 0;
}