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
int f[200];
LL ans = 1, mx = 0;
int d[200];

LL gcd(LL a, LL b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", f + i), --f[i];
    REP(i, n) {
        REP(j, n) d[j] = -1;
        d[i] = 0;
        int v = i;
        for (int dist = 1; ; ++dist) {
            v = f[v];
            if (d[v] == -1) {
                d[v] = dist;
            } else {
                ans = (ans / gcd(ans, dist - d[v])) * (dist - d[v]);
                mx = max(mx, (LL)d[v]);
                break;
            }
        }
    }
    LL inc = ans;
    while (ans < mx) ans += inc;
    cout << ans << endl;
    return 0;
}