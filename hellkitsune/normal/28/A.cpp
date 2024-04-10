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
int x[502], y[502];
vector<int> s[200001];
int pos[200001];
int ans[502];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, n) cin >> x[i] >> y[i];
    x[n] = x[0], y[n] = y[0];
    x[n + 1] = x[1], y[n + 1] = y[1];
    REP(i, m) {
        int tmp;
        cin >> tmp;
        s[tmp].pb(i + 1);
    }
    REP(i, n) ans[i] = -1;
    bool flag = true;
    REP(i, 200000) pos[i] = 0;
    for (int i = 1; i < n; i += 2) {
        int len = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]) + abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
        if (len > 200000 || pos[len] == (int)s[len].size()) {
            flag = false;
            break;
        }
        ans[i] = s[len][pos[len]++];
    }
    if (flag) {
        cout << "YES\n";
        REP(i, n) cout << ans[i] << ' ';
        cout << "\n";
        return 0;
    }
    REP(i, n + 1) ans[i] = -1;
    flag = true;
    REP(i, 200000) pos[i] = 0;
    for (int i = 2; i <= n; i += 2) {
        int len = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]) + abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
        if (len > 200000 || pos[len] == (int)s[len].size()) {
            flag = false;
            break;
        }
        ans[i] = s[len][pos[len]++];
    }
    if (flag) {
        ans[0] = ans[n];
        cout << "YES\n";
        REP(i, n) cout << ans[i] << ' ';
        cout << "\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}