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

int n, k;
int m, a[100005];
int cnt = 0, ans = 0;

int main() {
    scanf("%d%d", &n, &k);
    REP(i, k) {
        scanf("%d", &m);
        REP(j, m) scanf("%d", a + j);
        int pos = 0;
        while (pos < m - 1 && a[pos] + 1 == a[pos + 1]) {
            ++pos;
        }
        if (a[0] != 1) pos = 0;
        ans += 2 * (m - 1 - pos);
    }
    ans += k - 1;
    cout << ans << endl;
    return 0;
}