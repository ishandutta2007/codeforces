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

int n, q;
vector<int> d[200000];
bool pr[50000];
bool isOdd[500001];
vector<int> p, t;
LL ans = 0;
bool onShelf[200000] = {};
int cnt = 0;
int f[500001] = {};

int main() {
    REP(i, 50000) pr[i] = true;
    for (int i = 2; i < 2000; ++i) if (pr[i]) {
        for (int j = i * i; j < 50000; j += i)
            pr[j] = false;
    }
    for (int i = 2; i < 50000; ++i) if (pr[i])
        p.pb(i);
    isOdd[1] = false;
    for (int i = 2; i <= 500000; ++i) for (int x : p) {
        if (x * x > i) {
            isOdd[i] = true;
            break;
        }
        if (i % x == 0) {
            isOdd[i] = !isOdd[i / x];
            break;
        }
    }
    scanf("%d%d", &n, &q);
    REP(i, n) {
        int y;
        scanf("%d", &y);
        for (int x : p) {
            if (x * x > y) break;
            if (y % x == 0) {
                y /= x;
                while (y % x == 0)
                    y /= x;
                t.pb(x);
            }
        }
        if (y > 1) t.pb(y);
        int sz = (int)t.size();
        if (sz == 0) continue;
        d[i].pb(t[0]);
        for (int j = 1; j < sz; ++j) {
            int mx = (int)d[i].size();
            d[i].pb(t[j]);
            REP(k, mx) d[i].pb(d[i][k] * t[j]);
        }
        t.clear();
    }
    REP(i, q) {
        int ind;
        scanf("%d", &ind), --ind;
        if (onShelf[ind]) {
            --cnt;
            ans -= cnt;
            for (int x : d[ind]) {
                --f[x];
                if (isOdd[x]) ans += f[x];
                else ans -= f[x];
            }
        } else {
            ans += cnt;
            for (int x : d[ind]) {
                if (isOdd[x]) ans -= f[x];
                else ans += f[x];
                ++f[x];
            }
            ++cnt;
        }
        onShelf[ind] = !onShelf[ind];
        printf("%I64d\n", ans);
    }
    return 0;
}