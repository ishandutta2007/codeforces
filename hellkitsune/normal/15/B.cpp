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

LL t, n, m, x, y, xx, yy;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> t;
    REP(test, t) {
        cin >> n >> m >> x >> y >> xx >> yy;
        x = xx - x;
        y = yy - y;
        if (x < 0) x = -x;
        if (y < 0) y = -y;
        x = n - x;
        y = m - y;
        xx = max(0ll, 2 * x - n);
        yy = max(0ll, 2 * y - m);
        cout << n * m - 2 * x * y + xx * yy << '\n';
    }
    return 0;
}