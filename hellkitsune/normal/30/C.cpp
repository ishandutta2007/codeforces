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
int x[1000], y[1000], t[1000], nx[1000], ny[1000], nt[1000];
double p[1000], np[1000];
int ord[1000];
double d[1000];

bool cmp(const int &lhs, const int &rhs) {
    return t[lhs] < t[rhs];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> x[i] >> y[i] >> t[i] >> p[i];
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, n) nx[i] = x[ord[i]], ny[i] = y[ord[i]], nt[i] = t[ord[i]], np[i] = p[ord[i]];
    REP(i, n) x[i] = nx[i], y[i] = ny[i], t[i] = nt[i], p[i] = np[i];
    double ans = 0;
    REP(i, n) {
        d[i] = p[i];
        REP(j, i) if ((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]) <= (LL)(t[j] - t[i]) * (t[j] - t[i]))
            d[i] = max(d[i], p[i] + d[j]);
        ans = max(ans, d[i]);
    }
    cout << setprecision(15) << fixed << ans << '\n';
    return 0;
}