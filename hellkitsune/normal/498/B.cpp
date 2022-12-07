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

double d[5001][5001] = {};
int pp[5001], t[5001];
int n, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> T;
    REP(i, n) cin >> pp[i] >> t[i];
    d[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        double p = 0.01 * pp[i - 1];
        double q = 1 - p;
        int cnt = t[i - 1];
        double mul2 = 1;
        REP(j, cnt - 1) mul2 *= q;
        double mul = mul2 * p;
        double cur = 0;
        for (int j = 1; j <= T; ++j) {
            cur = q * cur + p * d[i - 1][j - 1];
            if (cur < 1e-30) cur = 0;
            if (j >= cnt) {
                cur -= mul * d[i - 1][j - cnt];
                d[i][j] = d[i - 1][j - cnt] * mul2;
            }
            d[i][j] += cur;
            if (d[i][j] < 1e-30) d[i][j] = 0;
        }
    }
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        double mul = i;
        double q = (i == n) ? 1.0 : (1.0 - 0.01 * pp[i]);
        int cnt = (i == n) ? 100000 : t[i];
        for (int j = T; j > max(-1, T - cnt); --j) {
            ans += mul * d[i][j];
            mul *= q;
            if (mul < 1e-30) break;
        }
    }
    cout << setprecision(12) << fixed << ans << endl;
    return 0;
}