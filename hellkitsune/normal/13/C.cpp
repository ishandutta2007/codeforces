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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, a[5000];
map<int, int> ma;
set<int> se;
int r[5000];
int cnt = 0;
LL d[5000] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) se.insert(a[i]);
    foreach(e, se) {
        ma[*e] = cnt;
        r[cnt++] = *e;
    }
    REP(i, n) a[i] = ma[a[i]];
    se.clear();
    ma.clear();
    REP(i, n) {
        LL mn = 1e18;
        REP(j, cnt) {
            mn = min(mn, d[j]);
            d[j] = mn + abs(r[j] - r[a[i]]);
        }
    }
    LL ans = 1e18;
    REP(i, cnt) ans = min(ans, d[i]);
    cout << ans << endl;
    return 0;
}