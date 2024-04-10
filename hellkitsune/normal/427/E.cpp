#include <cstdio>
#include <cmath>
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

int n, m, a[1000000], b[500001], bc = 1, c[500001], cc = 1;
LL ans = 1e18;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n)
        scanf("%d", a + i);
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    m = min(n - 1, m);
    int l = 0, r = n - 1;
    b[0] = a[0]; c[0] = a[n - 1]; bc = 1; cc = 1;
    while (true) {
        l += m;
        if (l < r) b[bc++] = a[l];
        r -= m;
        if (l < r) c[cc++] = a[r];
        if (l >= r) break;
    }
    ans = 0;
    for (int i = 0; i < bc; ++i)
        ans += b[bc - 1] - b[i];
    for (int i = 0; i < cc; ++i)
        ans += c[i] - b[bc - 1];
    cout << ans * 2 << endl;
    return 0;
}