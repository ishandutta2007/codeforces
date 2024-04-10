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

int n, k;
double d[1000], d2[1000];
int a[33];
double ans = 0;
const double EPS = 1e-30;
double tran[1000][1000];
vector<pair<int, double> > tv[1000];

void solve() {
    double di = 2.0 / (n * (n + 1));
    int N = n * n;
    REP(i, N) REP(j, N) tran[i][j] = 0;
    REP(i, N) {
        int x = i / n;
        int y = i % n;
        REP(l, n) for (int r = l; r < n; ++r) {
            int xx = x, yy = y;
            if (xx >= l && xx <= r) xx = r + l - xx;
            if (yy >= l && yy <= r) yy = r + l - yy;
            tran[i][xx * n + yy] += di;
        }
    }
    REP(i, N) REP(j, N) if (tran[i][j] > EPS)
        tv[i].pb(mp(j, tran[i][j]));
    REP(times, k) {
        REP(i, N) d2[i] = 0;
        REP(i, N) if (d[i] > EPS) REP(j, tv[i].size())
            d2[tv[i][j].first] += d[i] * tv[i][j].second;
        REP(i, N) d[i] = d2[i];
        REP(i, N) if (d[i] < EPS) d[i] = 0;
    }
    REP(i, n) REP(j, i) ans += d[i * n + j];
    REP(i, N) tv[i].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    ans = 0;
    REP(i, n * n) d[i] = 0;
    REP(i, n) for (int j = i + 1; j < n; ++j) if (a[i] < a[j])
        d[i * n + j] += 1;
    else
        d[j * n + i] += 1;
    solve();
    cout << setprecision(15) << fixed << ans << endl;
    return 0;
}