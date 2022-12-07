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

int r, s, p, tot;
double d[101][101] = {}, nd[101][101];
const double EPS = 1e-20;
double pr = 0, ps = 0, pp = 0;

int main() {
    cin >> r >> s >> p;
    tot = r + s + p;
    d[r][s] = 1;
    for (; tot >= 1; --tot) {
        REP(i, r + 1) REP(j, s + 1) nd[i][j] = 0;
        for (int i = 0; i <= r; ++i) for (int j = 0; j <= s; ++j) if (d[i][j] > EPS) {
            int k = tot - i - j;
            int c = i * j + j * k + k * i;
            int ni = i, nj = j, nk = k, z = (i == 0) + (j == 0) + (k == 0);
            if (i && j) {
                if (--nj == 0) ++z;
                double prob = (i * j) * d[i][j] / c;
                if (z == 2) pr += prob;
                else nd[i][nj] += prob;
                if (++nj == 1) --z;
            }
            if (j && k) {
                if (--nk == 0) ++z;
                double prob = (j * k) * d[i][j] / c;
                if (z == 2) ps += prob;
                else nd[i][j] += prob;
                if (++nk == 1) --z;
            }
            if (k && i) {
                if (--ni == 0) ++z;
                double prob = (k * i) * d[i][j] / c;
                if (z == 2) pp += prob;
                else nd[ni][j] += prob;
                if (++ni == 1) --z;
            }
        }
        REP(i, r + 1) REP(j, s + 1) {
            d[i][j] = nd[i][j];
            if (d[i][j] <= EPS) d[i][j] = 0;
        }
    }
    printf("%.12f %.12f %.12f\n", pr, ps, pp);
    return 0;
}