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

int yx, yX, Yx, YX;
int y[100000], x[100000];
int n, m, c, h;
int best = 2e9 + 7, bestind;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> c;
    REP(i, c) cin >> y[i] >> x[i];
    yx = yX = Yx = YX = 0;
    for (int i = 1; i < c; ++i) {
        if (y[i] + x[i] > y[yx] + x[yx]) yx = i;
        if (y[i] - x[i] > y[yX] - x[yX]) yX = i;
        if (x[i] - y[i] > x[Yx] - y[Yx]) Yx = i;
        if (-x[i] - y[i] > -x[YX] - y[YX]) YX = i;
    }
    cin >> h;
    REP(i, h) {
        int Y, X;
        cin >> Y >> X;
        int cur = abs(Y - y[yx]) + abs(X - x[yx]);
        cur = max(cur, abs(Y - y[yX]) + abs(X - x[yX]));
        cur = max(cur, abs(Y - y[Yx]) + abs(X - x[Yx]));
        cur = max(cur, abs(Y - y[YX]) + abs(X - x[YX]));
        if (cur < best) {
            best = cur;
            bestind = i + 1;
        }
    }
    cout << best << '\n' << bestind << '\n';
    return 0;
}