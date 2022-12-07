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

LL a[20];
int n, m;
string s[50];
double ans = 0, cur;
double p[1 << 20];
int l[1 << 20];
LL ma[1 << 20];
int pc[1 << 20];
int upd[1 << 20][20], updc[1 << 20] = {};

const double EPS = 1e-18;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> s[i];
    m = (int)s[0].length();
    REP(i, 1 << m) {
        l[i] = 0;
        REP(j, m) if (i & (1 << j)) {
            l[i] = j;
            break;
        }
    }
    REP(i, 1 << m) pc[i] = __builtin_popcount(i);
    REP(i, 1 << m) REP(j, m) if ((i & (1 << j)) == 0)
        upd[i][updc[i]++] = (i | (1 << j));
    REP(i, n) {
        cur = 0;
        REP(j, m) a[j] = 0;
        REP(j, m) REP(k, n) if (s[i][j] == s[k][j])
            a[j] |= 1ll << k;
        REP(j, 1 << m) p[j] = 0;
        p[0] = 1;
        REP(j, 1 << m) if (p[j] > EPS) {
            LL mask;
            if (j) {
                mask = ma[j ^ (1 << l[j])] & a[l[j]];
            } else
                mask = ((1ll << n) - 1) ^ (1ll << i);
            if (mask == 0) {
                cur += p[j] * pc[j];
            } else {
                double dp = p[j] / (m - pc[j]);
                for (int k = 0; k < updc[j]; ++k) {
                    p[upd[j][k]] += dp;
                }
            }
            ma[j] = mask;
        }
        ans += cur / n;
    }
    cout << setprecision(12) << fixed << ans << endl;
    return 0;
}