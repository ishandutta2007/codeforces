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
int l[5], r[5], rr[5];
double d[10005], e[10005];
double f[10005];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> l[i] >> r[i];
    double pp = 1;
    REP(i, n) pp /= r[i] - l[i] + 1;
    double ans = 0;
    REP(i, n) {
        for (int j = 1; j <= 10000; ++j) {
            double p = pp;
            REP(k, n) if (k != i) {
                int cur = min(r[k], j) - l[k] + 1;
                if (cur < 0) cur = 0;
                p *= cur;
            }
            d[j] = p;
        }
        d[0] = 0;
        f[0] = 0;
        for (int j = 1; j <= 10000; ++j)
            f[j] = (d[j] - d[j - 1]) * j;
        for (int j = 2; j <= 10000; ++j)
            f[j] += f[j - 1];
        for (int j = 1; j <= 10000; ++j) {
            double p = pp;
            REP(k, n) if (k != i) {
                int cur = min(r[k], (k < i) ? (j - 1) : j) - l[k] + 1;
                if (cur < 0) cur = 0;
                p *= cur;
            }
            e[j] = p;
        }
        e[0] = 0;
        for (int j = l[i]; j <= r[i]; ++j) {
            ans += f[j - 1];
            ans += (e[j] - d[j - 1]) * j;
        }
    }
    cout << setprecision(15) << fixed << ans << endl;
    return 0;
}