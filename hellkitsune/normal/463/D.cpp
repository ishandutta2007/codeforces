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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int a[5][1000], r[5][1000], rr[1000];
int d[1000];
int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    REP(i, k) REP(j, n) cin >> a[i][j], --a[i][j];
    REP(i, n) rr[a[0][i]] = i;
    REP(i, k) REP(j, n) a[i][j] = rr[a[i][j]];
    REP(i, k) REP(j, n) r[i][a[i][j]] = j;
    d[0] = 1;
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        d[i] = 1;
        REP(j, i) {
            bool flag = true;
            for (int t = 1; t < k; ++t) if (r[t][j] > r[t][i]) {
                flag = false;
                break;
            }
            if (!flag) continue;
            d[i] = max(d[i], d[j] + 1);
        }
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}