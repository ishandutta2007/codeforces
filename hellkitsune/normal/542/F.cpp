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

int n, t;
int a[1000], p[1000];
int ans = 0;
int d[1024] = {};
bool used[1000] = {};

multiset<int, greater<int> > se;

int main() {
    scanf("%d%d", &n, &t);
    REP(i, n) scanf("%d%d", a + i, p + i);
    for (int lev = 1000; lev >= 0; --lev) {
        int mx = 1024;
        if (lev <= 10) mx = 1 << lev;
        REP(i, n) if (!used[i] && a[i] + lev <= t)
            se.insert(p[i]), used[i] = true;
        REP(i, mx) if (d[i] != 0) se.insert(d[i]);
        REP(i, mx) {
            if (se.empty()) d[i] = 0;
            else d[i] = *se.begin(), se.erase(se.begin());
        }
        if (lev > 0) {
            sort(d, d + mx);
            REP(i, mx / 2) d[i] = d[2 * i] + d[2 * i + 1];
            for (int i = mx / 2; i < mx; ++i) d[i] = 0;
        }
    }
    printf("%d\n", d[0]);
    return 0;
}