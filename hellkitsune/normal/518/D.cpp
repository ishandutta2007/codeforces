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

int n, t;
double p;
double d[2001] = {}, d2[2001];

int main() {
    cin >> n >> p >> t;
    d[0] = 1;
    REP(tt, t) {
        REP(i, n + 1) d2[i] = 0;
        REP(i, n) {
            d2[i] += (1 - p) * d[i];
            d2[i + 1] += p * d[i];
        }
        d2[n] += d[n];
        REP(i, n + 1) d[i] = d2[i];
    }
    double ans = 0;
    REP(i, n + 1) ans += i * d[i];
    cout << setprecision(12) << fixed << ans << endl;
    return 0;
}