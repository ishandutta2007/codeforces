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
typedef long long LL;
typedef pair<int, int> PII;

int a[200001];
int n, k, x;
int l[200001], r[200002];

int main() {
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    l[0] = 0;
    for (int i = 1; i <= n; ++i) l[i] = l[i - 1] | a[i];
    r[n + 1] = 0;
    for (int i = n; i >= 1; --i) r[i] = r[i + 1] | a[i];
    LL mul = 1;
    REP(i, k) mul *= x;
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        LL cur = (LL)a[i] * mul;
        cur |= l[i - 1];
        cur |= r[i + 1];
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}