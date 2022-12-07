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

int n, f[100001];
int used[100001] = {};
vector<PII> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> f[i], used[f[i]] = 1;
    int bad = 1;
    int pre = -1, ind = 1, fi;
    REP(i, n) {
        if (pre == -1 || used[f[pre]] == 2) {
            while (ind <= n && used[ind] >= bad) {
                ++ind;
                if (ind == n + 1) {
                    ind = 1;
                    ++bad;
                }
            }
            if (pre != -1) ans.pb(mp(pre, ind));
            else fi = ind;
            pre = ind;
            used[pre] = 2;
        } else {
            pre = f[pre];
            used[pre] = 2;
        }
    }
    if (f[pre] != fi) ans.pb(mp(pre, fi));
    cout << (int)ans.size() << '\n';
    REP(i, ans.size())
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    return 0;
}