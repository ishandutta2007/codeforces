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

int n, l;
int a[1000];

double ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> l;
    REP(i, n) cin >> a[i];
    sort(a, a + n);
    ans = max(a[0], l - a[n - 1]);
    REP(i, n - 1)
        ans = max(ans, (a[i + 1] - a[i]) * 0.5);
    cout << setprecision(15) << fixed << ans << '\n';
    return 0;
}