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

int n, a[100002];
int l[100002], r[100002];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    l[0] = 0;
    for (int i = 1; i <= n; ++i) {
        l[i] = l[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        l[i] = max(l[i - 1], -l[i] * 2);
    }
    r[n + 1] = 0;
    for (int i = n; i >= 1; --i) {
        r[i] = r[i + 1] + a[i];
    }
    for (int i = n; i >= 1; --i) {
        r[i] = max(r[i + 1], -r[i] * 2);
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) sum += a[i];
    int ans = sum;
    REP(i, n + 1) {
        ans = max(ans, sum + l[i] + r[i + 1]);
    }
    cout << ans << endl;
    return 0;
}