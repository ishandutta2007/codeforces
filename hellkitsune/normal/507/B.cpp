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

LL r, x, y, xx, yy;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> r >> x >> y >> xx >> yy;
    LL dist = (xx - x) * (xx - x) + (yy - y) * (yy - y);
    LL d = 2 * r;
    LL cur = 0, ans = 0;
    while (cur * cur < dist) {
        cur += d;
        ++ans;
    }
    cout << ans << '\n';
    return 0;
}