#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

typedef long double ld;

const double PI = atan2l(0, -1);
const ld eps = 1e-7;
const int maxn = 50000;

int x[maxn], y[maxn], r[maxn];

ld norm(ld x) {
    while (x < 0) x += 2 * PI;
    while (x > 2 * PI + eps) x -= 2 * PI;
    return x;
}

bool comp(const pair<ld, int> &p1, const pair<ld, int> &p2) {
    if (fabs(p1.first - p2.first) > eps) return p1.first < p2.first;
    return p1.second > p2.second;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, D;
    scanf("%d%d", &N, &D);
    forn(i, N) scanf("%d%d%d", &x[i], &y[i], &r[i]);
    vector<pair<ld, int> > evs;
    forn(i, N) {
        ld dd = sqrt(1.0 * x[i] * x[i] + y[i] * y[i]);
        int k = int(floor((dd - r[i]) / D));
        for (int j = k; ; ++j) {
            ld kd = j * D;
            if (kd < dd - r[i] - eps) continue;
            if (kd > dd + r[i] + eps) break;
            ld alpha = acosl((kd * kd + dd * dd - r[i] * r[i]) / (2 * kd * dd));
            if (alpha != alpha) alpha = 0;
            ld beta = atan2l(1.0 * y[i], 1.0 * x[i]);
            ld l = norm(beta - alpha), r = norm(beta + alpha);
            if (l < r + eps) {
                evs.pb(mp(l, 1));
                evs.pb(mp(r, -1));
            } else {
                evs.pb(mp(l, 1));
                evs.pb(mp(2 * PI, -1));
                evs.pb(mp(0, 1));
                evs.pb(mp(r, -1));
            }
//            cerr << i << ' ' << j << ' ' << l << ' ' << r << '\n';
        }
    }
    sort(all(evs), comp);
//    forn(i, evs.size()) cerr << evs[i].first << ' ' << evs[i].second << '\n';
    int b = 0;
    int ans = 0;
    forn(i, evs.size()) {
        b += evs[i].second;
        ans = max(ans, b);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}