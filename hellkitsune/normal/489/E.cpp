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
double d[1001];
int pre[1001];
int x[1001], b[1001];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> l;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> b[i];
    double lo = 0, hi = 1000, mid;
    REP(times, 50) {
        mid = (lo + hi) / 2;
        d[0] = 0;
        for (int i = 1; i <= n; ++i) {
            d[i] = -1e30;
            pre[i] = -1;
            REP(j, i) {
                double dd = d[j] + b[i] * mid - sqrt(double(abs(l - abs(x[j] - x[i]))));
                if (dd > d[i]) {
                    d[i] = dd;
                    pre[i] = j;
                }
            }
        }
        if (d[n] >= 0) {
            ans.clear();
            int cur = n;
            while (cur > 0) {
                ans.pb(cur);
                cur = pre[cur];
            }
            hi = mid;
        } else {
            lo = mid;
        }
    }
    reverse(ans.begin(), ans.end());
    REP(i, ans.size()) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}