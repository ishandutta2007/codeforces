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

LL m;
LL d[65][65];
int k;
LL cur, z, s;

int god(int i, int j) {
    if (j > i)
        return d[i][j] = 0;
    if (j == 0)
        return d[i][j] = 1;
    return d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
}

void go(int h, int k) {
    if (k <= 0) {
        if (k == 0) cur += s;
        return;
    }
    if (h < 0)
        return;
    if ((1ll << h) & z) {
        cur += s * d[h][k];
        go(h - 1, k - 1);
    } else {
        go(h - 1, k);
    }
}

int main() {
    cin >> m >> k;
    LL l = 1, r = 1e18, mid;
    REP(i, 64) REP(j, 64) {
        god(i, j);
    }
    while (l < r) {
        mid = (l + r) >> 1;
        cur = 0;
        z = mid << 1;
        s = 1;
        go(63, k);
        z = mid;
        s = -1;
        go(63, k);
        if (cur < m)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l << endl;
    return 0;
}