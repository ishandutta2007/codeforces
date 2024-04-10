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

int n, m, k;
LL p[5000], s[5000];
LL d[5005] = {}, d2[5005];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    REP(i, n) cin >> p[i];
    s[0] = 0;
    REP(i, m) s[0] += p[i];
    for (int i = 1; i < n - m + 1; ++i)
        s[i] = s[i - 1] - p[i - 1] + p[i - 1 + m];
    REP(step, k) {
        REP(i, n + 1) d2[i] = 0;
        LL cur = 0;
        for (int i = 0; i < n - m + 1; ++i) {
            cur = max(cur, d[i]);
            d2[i + m] = cur + s[i];
        }
        REP(i, n + 1) d[i] = d2[i];
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, d[i]);
    cout << ans << endl;
    return 0;
}