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
int t[2001], c[2001];
LL _d[4005], _d2[4005], *d, *d2;
const LL INF = 1e18;
LL ans = INF;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> t[i] >> c[i];
    d = _d + 2002, d2 = _d2 + 2002;
    for (int i = -n; i <= n; ++i) d[i] = INF;
    d[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = -n; j <= n; ++j) {
            d2[j] = INF;
            if (j - t[i] >= -n) d2[j] = min(d2[j], d[j - t[i]] + c[i]);
            if (j + 1 <= n) d2[j] = min(d2[j], d[j + 1]);
        }
        for (int j = max(n - t[i], -n); j < n; ++j)
            d2[n] = min(d2[n], d[j] + c[i]);
        for (int j = -n; j <= n; ++j) {
            d[j] = d2[j];
        }
        for (int j = n - i; j <= n; ++j)
            ans = min(ans, d[j]);
    }
    cout << ans << endl;
    return 0;
}