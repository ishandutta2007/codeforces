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

int n, m;
int a[105], b[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    cin >> m;
    REP(i, m) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int ai = 0, bi = 0, ans = 0;
    while (ai < n && bi < m) {
        while (ai < n && a[ai] < b[bi] - 1) ++ai;
        if (ai == n) break;
        while (bi < m && b[bi] < a[ai] - 1) ++bi;
        if (bi == m) break;
        if (abs(a[ai] - b[bi]) <= 1) {
            ++ai;
            ++bi;
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}