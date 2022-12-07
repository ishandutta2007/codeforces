#include <cstdio>
#include <cmath>
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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

map<PII, int> ma;
int n, p;
int x[300000], y[300000];
PII cnt[300000] = {};
int rev[300000];
vector<int> pa[300000];
LL ans = 0;

int main() {
    scanf("%d%d", &n, &p);
    REP(i, n)
        cnt[i].second = i;
    REP(i, n) {
        scanf("%d%d", x + i, y + i);
        --x[i]; --y[i];
        if (x[i] > y[i])
            swap(x[i], y[i]);
        ++cnt[x[i]].first;
        ++cnt[y[i]].first;
        if (++ma[mp(x[i], y[i])] == 1) {
            pa[x[i]].pb(y[i]);
            pa[y[i]].pb(x[i]);
        }
    }
    sort(cnt, cnt + n);
    REP(i, n)
        rev[cnt[i].second] = i;
    int r = n;
    REP(i, n - 1) {
        int pp = p - cnt[i].first;
        while (cnt[r - 1].first >= pp && r > i + 1)
            --r;
        if (r <= i)
            r = i + 1;
        if (r == n)
            continue;
        ans += n - r;
        REP(j, pa[cnt[i].second].size()) {
            int x = pa[cnt[i].second][j];
            if (rev[x] < r)
                continue;
            int z = ma[mp(min(cnt[i].second, x), max(cnt[i].second, x))];
            x = rev[x];
            if (cnt[x].first + cnt[i].first - z < p)
                --ans;
        }
    }
    cout << ans << endl;
    return 0;
}