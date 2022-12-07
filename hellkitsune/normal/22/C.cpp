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

int n, m, v;
vector<PII> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> v;
    if (m < n - 1) {
        cout << "-1\n";
        return 0;
    }
    --m;
    REP(i, n - 1) if (m) for (int j = i + 1; j < n - 1; ++j) if (m) {
        ans.pb(mp(i, j));
        --m;
    }
    if (m > 0) {
        cout << "-1\n";
        return 0;
    }
    ans.pb(mp(0, n - 1));
    REP(i, ans.size()) if (ans[i].first == 0) ans[i].first = v;
    else if (ans[i].first >= v) ++ans[i].first;
    REP(i, ans.size()) if (ans[i].second == 0) ans[i].second = v;
    else if (ans[i].second >= v) ++ans[i].second;
    REP(i, ans.size())
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    return 0;
}