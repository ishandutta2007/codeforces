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
LL a[300], b[300], c[300];
LL x, y, xx, yy;
LL mnx, mny, mxx, mxy;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> x >> y >> xx >> yy;
    cin >> n;
    REP(i, n) cin >> a[i] >> b[i] >> c[i], c[i] = -c[i];
    LL A = y - yy;
    LL B = xx - x;
    LL C = A * x + B * y;
    int ans = 0;
    mnx = min(x, xx), mxx = max(x, xx);
    mny = min(y, yy), mxy = max(y, yy);
    for (int i = 0; i < n; ++i) {
        LL det = A * b[i] - B * a[i];
        if (det == 0) continue;
        LL tx = C * b[i] - B * c[i];
        LL ty = A * c[i] - C * a[i];
        if (det < 0) {
            tx *= -1;
            ty *= -1;
            det *= -1;
        }
        if (tx >= mnx * det && tx <= mxx * det && ty >= mny * det && ty <= mxy * det)
            ++ans;
    }
    cout << ans << endl;
    return 0;
}