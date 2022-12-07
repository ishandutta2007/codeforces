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

int m, n;
LL a[100000], b[100000];
LL ans = 2e18;
LL suma = 0, sumb = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    REP(i, m) cin >> a[i];
    REP(i, n) cin >> b[i];
    sort(a, a + m);
    sort(b, b + n);
    REP(i, m) suma += a[i];
    REP(i, n) sumb += b[i];
    REP(i, m) if (i == m - 1 || a[i] >= sumb) {
        ans = 0;
        REP(j, i) ans += a[j];
        ans += sumb * (m - i);
        break;
    }
    REP(i, n) if (i == n - 1 || b[i] >= suma) {
        LL cur = 0;
        REP(j, i) cur += b[j];
        cur += suma * (n - i);
        ans = min(ans, cur);
        break;
    }
    cout << ans << endl;
    return 0;
}