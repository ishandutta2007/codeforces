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
int a[300000], l[300000], r[300000];
int sum[300001];
vector<int> q[1000001][3];
int cnt[1000001];

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    sum[0] = 0;
    REP(i, n) sum[i + 1] = (sum[i] + a[i]) % k;
    REP(i, n + 1) q[i][1].pb(sum[i]);
    REP(i, n) {
        l[i] = i;
        while (l[i] > 0 && a[l[i] - 1] < a[i]) l[i] = l[l[i] - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        r[i] = i;
        while (r[i] < n - 1 && a[r[i] + 1] <= a[i]) r[i] = r[r[i] + 1];
    }
    REP(i, n) a[i] %= k;
    LL ans = 0;
    REP(i, n) {
        if (i - l[i] < r[i] - i) {
            for (int from = l[i]; from <= i; ++from) {
                int targ = sum[from] + a[i];
                if (targ >= k) targ -= k;
                q[i + 1][0].pb(targ);
                q[r[i] + 1][2].pb(targ);
            }
        } else {
            for (int from = i; from <= r[i]; ++from) {
                int targ = sum[from + 1] - a[i];
                if (targ < 0) targ += k;
                q[l[i]][0].pb(targ);
                q[i][2].pb(targ);
            }
        }
    }
    REP(i, n + 1) {
        for (int x : q[i][0]) ++cnt[x];
        for (int x : q[i][1]) ans += cnt[x];
        for (int x : q[i][2]) --cnt[x];
    }
    cout << ans - n << endl;
    return 0;
}