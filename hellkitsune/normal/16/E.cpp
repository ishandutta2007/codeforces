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

int n;
double a[18][18];
double d[1 << 18] = {};
int s[18], ss;
double ans[18] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) REP(j, n) cin >> a[i][j];
    d[(1 << n) - 1] = 1;
    for (int mask = (1 << n) - 1; mask > 0; --mask) {
        ss = 0;
        REP(i, n) if (mask & (1 << i))
            s[ss++] = i;
        if (ss == 1) {
            ans[s[0]] = d[mask];
            continue;
        }
        double prob = 2.0 / (ss * (ss - 1));
        REP(i, ss - 1) for (int j = i + 1; j < ss; ++j) {
            d[mask ^ (1 << s[i])] += d[mask] * prob * a[s[j]][s[i]];
            d[mask ^ (1 << s[j])] += d[mask] * prob * a[s[i]][s[j]];
        }
    }
    REP(i, n) cout << setprecision(12) << fixed << ans[i] << ' ';
    cout << '\n';
    return 0;
}