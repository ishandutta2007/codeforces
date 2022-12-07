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

int v, vv, t, d;
int a[100];

int main() {
    cin >> v >> vv >> t >> d;
    int cur = v;
    REP(i, t) {
        a[i] = cur;
        cur += d;
    }
    cur = vv;
    for (int i = t - 1; i >= 0; --i) {
        a[i] = min(a[i], cur);
        cur += d;
    }
    int ans = 0;
    REP(i, t) ans += a[i];
    cout << ans << endl;
    return 0;
}