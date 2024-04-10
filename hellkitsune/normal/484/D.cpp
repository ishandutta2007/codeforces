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

LL mx, mn;
int n, a[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    mx = a[0], mn = -a[0];
    LL best = 0;
    REP(i, n) {
        LL cur = max(mx - a[i], mn + a[i]);
        best = max(best, cur);
        if (i < n - 1) {
            mx = max(mx, best + a[i + 1]);
            mn = max(mn, best - a[i + 1]);
        }
    }
    cout << best << '\n';
    return 0;
}