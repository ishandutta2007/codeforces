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

int n, x[500001], v[500001];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> x[i] >> v[i];
    v[n++] = 1;
    double lo = 0, hi = 1e10 + 10, mid;
    REP(times, 100) {
        mid = (lo + hi) / 2;
        int l = 0, r = 0;
        bool flag = false;
        REP(i, n) if (v[i] < 0) {
            if (l > 0) ++r;
        } else {
            if (r > 0) {
                int rind = i - r;
                int lind = rind - l;
                double tl = -1e27, tr = 1e27;
                for (int j = lind; j < rind; ++j)
                    tl = max(tl, x[j] + mid * v[j]);
                for (int j = rind; j < i; ++j)
                    tr = min(tr, x[j] + mid * v[j]);
                if (tl >= tr) {
                    flag = true;
                    break;
                }
                l = 1;
                r = 0;
            } else {
                ++l;
            }
        }
        if (flag) hi = mid;
        else lo = mid;
    }
    if (hi > 1e10) cout << -1 << endl;
    else cout << setprecision(15) << fixed << hi << endl;
    return 0;
}