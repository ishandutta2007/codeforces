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
double t;
double x[10], v[10], m[10];
const double EPS = 1e-9;
bool f[10][10] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    REP(i, n) cin >> x[i] >> v[i] >> m[i];
    while (true) {
        double bestT = 1e9;
        int bi = 0, bj = 0;
        REP(ii, n) for (int jj = ii + 1; jj < n; ++jj) if (abs(x[ii] - x[jj]) > EPS)
            f[ii][jj] = false;
        REP(ii, n) for (int jj = ii + 1; jj < n; ++jj) if (!f[ii][jj]) {
            int i = ii, j = jj;
            if (x[i] > x[j]) swap(i, j);
            if (v[i] < v[j] + EPS) continue;
            if ((x[j] - x[i]) / (v[i] - v[j]) < bestT) {
                bestT = (x[j] - x[i]) / (v[i] - v[j]);
                bi = ii, bj = jj;
            }
        }
        if (bestT >= t) {
            REP(i, n) x[i] += v[i] * t;
            break;
        }
        f[bi][bj] = true;
        REP(i, n) x[i] += v[i] * bestT;
        t -= bestT;
        double nv = ((m[bi] - m[bj]) * v[bi] + 2 * m[bj] * v[bj]) / (m[bi] + m[bj]);
        v[bj] = ((m[bj] - m[bi]) * v[bj] + 2 * m[bi] * v[bi]) / (m[bi] + m[bj]);
        v[bi] = nv;
    }
    REP(i, n) cout << setprecision(12) << fixed << x[i] << endl;
    return 0;
}