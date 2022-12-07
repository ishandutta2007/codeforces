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

int n, xx, yy;
int x[1000], y[1000];

set<PII> se;

int gcd(int x, int y) {
    while (y) x %= y, swap(x, y);
    return x;
}

int main() {
    scanf("%d%d%d", &n, &xx, &yy);
    REP(i, n) scanf("%d%d", x + i, y + i);
    REP(i, n) x[i] -= xx, y[i] -= yy;
    REP(i, n) {
        xx = x[i];
        yy = y[i];
        int g = gcd(abs(xx), abs(yy));
        xx /= g;
        yy /= g;
        if (xx < 0) xx = -xx, yy = -yy;
        else if (xx == 0 && yy < 0) xx = -xx, yy = -yy;
        se.insert(mp(xx, yy));
    }
    cout << (int)se.size() << endl;
    return 0;
}