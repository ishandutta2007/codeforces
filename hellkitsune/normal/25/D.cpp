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
int c[1000];
vector<int> cp[1000];
vector<PII> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) c[i] = i, cp[i].pb(i);
    REP(i, n - 1) {
        int a, b;
        cin >> a >> b, --a, --b;
        if (c[a] == c[b])
            ans.pb(mp(a, b));
        else {
            int x = c[a], y = c[b];
            if (cp[y].size() > cp[x].size()) swap(x, y);
            for (int v : cp[y]) {
                c[v] = x;
                cp[x].pb(v);
            }
            cp[y].clear();
        }
    }
    int fi = -1, ind = 0;
    cout << (int)ans.size() << '\n';
    REP(i, n) if (!cp[i].empty()) {
        if (fi == -1) {
            fi = i;
        } else {
            cout << ans[ind].first + 1 << ' ' << ans[ind].second + 1 << ' ';
            cout << cp[fi][0] + 1 << ' ' << cp[i][0] + 1 << '\n';
            ++ind;
        }
    }
    return 0;
}