#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> g[100];
vector<int> vv;

int from[100], to[100];
double ans[100];
set<int> se;

void dfs(int v, int par) {
    vv.pb(v);
    for (int to : g[v]) if (to != par) {
        dfs(to, v);
    }
}

int main() {
    scanf("%d", &n);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        if (from > to) swap(from, to);
        ::from[i] = from;
        ::to[i] = to;
        g[from].pb(to);
        g[to].pb(from);
    }
    forn(i, n) if ((int)g[i].size() > 1) {
        double dif = 2.0 / g[i].size();
        double cur = 0;
        forn(j, n - 1) if (from[j] == i) {
            vv.clear();
            dfs(to[j], i);
            cur += dif;
            if (cur >= 2.0) cur -= 2.0;
            double delta = (ans[j] - cur);
            forn(k, n - 1) if (find(vv.begin(), vv.end(), from[k]) != vv.end() || find(vv.begin(), vv.end(), to[k]) != vv.end()) {
                ans[k] += delta;
                while (ans[k] < 0) ans[k] += 2.0;
                while (ans[k] >= 2.0) ans[k] -= 2.0;
            }
        } else if (to[j] == i) {
            vv.clear();
            dfs(from[j], i);
            cur += dif;
            if (cur >= 2.0) cur -= 2.0;
            double delta = (ans[j] + 1.0 - cur);
            forn(k, n - 1) if (find(vv.begin(), vv.end(), from[k]) != vv.end() || find(vv.begin(), vv.end(), to[k]) != vv.end()) {
                ans[k] += delta;
                while (ans[k] < 0) ans[k] += 2.0;
                while (ans[k] >= 2.0) ans[k] -= 2.0;
            }
        }
    }
    printf("%d\n", n - 1);
    forn(i, n - 1) {
        if (ans[i] > 1.0) {
            ans[i] -= 1.0;
            swap(from[i], to[i]);
        }
        printf("%d %d %d %d %.15f\n", 1, i + 1, from[i] + 1, to[i] + 1, ans[i]);
    }
    return 0;
}