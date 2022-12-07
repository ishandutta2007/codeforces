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

double a, v, l, d, w;

void solve(double a, double v, double l, double v0, double t0) {
    double s = (v - v0) * (v - v0) / (2 * a) + v0 * (v - v0) / a;
    if (s > l) {
        double le = 0, ri = 1e9, m;
        REP(i, 200) {
            m = (le + ri) / 2;
            if (a / 2 * m * m + v0 * m < l)
                le = m;
            else
                ri = m;
        }
        cout << setprecision(12) << fixed << t0 + m << endl;
    } else {
        t0 += (v - v0) / a;
        l -= s;
        cout << setprecision(12) << fixed << t0 + l / v << endl;
    }
}

int main() {
    cin >> a >> v >> l >> d >> w;
    if (v <= w) {
        solve(a, v, l, 0, 0);
        return 0;
    }
    double t = sqrt(2 * d / a);
    if (t * a <= w) {
        solve(a, v, l, 0, 0);
    } else {
        double s = v * v / (2 * a) + (v - w) * (v - w) / (2 * a) + w * (v - w) / a;
        if (s > d) {
            double le = w, ri = v, m;
            REP(i, 200) {
                m = (le + ri) / 2;
                s = m * m / (2 * a) + (m - w) * (m - w) / (2 * a) + w * (m - w) / a;
                if (s < d)
                    le = m;
                else
                    ri = m;
            }
            solve(a, v, l - d, w, (2 * m - w) / a);
        } else {
            solve(a, v, l - d, w, (2 * v - w) / a + (d - s) / v);
        }
    }
    return 0;
}