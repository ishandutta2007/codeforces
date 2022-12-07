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

int n, m, k;
bool f[100000] = {}, used[100000];
vector<int> g[100000];
int cnt[100000];
queue<int> q;
vector<int> ans;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, k) {
        int x;
        scanf("%d", &x), --x;
        f[x] = true;
    }
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    REP(i, n) if (!f[i]) {
        ans.pb(i + 1);
        break;
    }
    double lo = 0, hi = 1, mid;
    REP(it, 100) {
        mid = (lo + hi) / 2;
        REP(i, n) if (!f[i]) {
            cnt[i] = 0;
            for (int to : g[i]) if (!f[to]) {
                ++cnt[i];
            }
            used[i] = cnt[i] / (double)g[i].size() >= mid;
            if (!used[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) {
                --cnt[to];
                if (used[to] && cnt[to] / (double)g[to].size() < mid) {
                    q.push(to);
                    used[to] = false;
                }
            }
        }
        bool ok = false;
        REP(i, n) if (used[i]) {
            ok = true;
            break;
        }
        if (ok) {
            lo = mid;
            ans.clear();
            REP(i, n) if (used[i]) {
                ans.pb(i + 1);
            }
        } else {
            hi = mid;
        }
    }
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}