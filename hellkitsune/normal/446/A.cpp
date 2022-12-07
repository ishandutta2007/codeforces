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
int a[100000], l[100000], r[100000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    l[0] = 0;
    for (int i = 1; i < n; ++i) if (a[i] <= a[i - 1]) {
        l[i] = i;
    } else {
        l[i] = l[i - 1];
    }
    r[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) if (a[i] >= a[i + 1]) {
        r[i] = i;
    } else {
        r[i] = r[i + 1];
    }
    int ans = 0;
    REP(i, n) ans = max(ans, i - l[i] + 1);
    if (ans < n) ++ans;
    for (int i = 1; i < n - 1; ++i) if (a[i - 1] + 1 < a[i + 1]) {
        ans = max(ans, r[i + 1] - l[i - 1] + 1);
    }
    cout << ans << endl;
    return 0;
}