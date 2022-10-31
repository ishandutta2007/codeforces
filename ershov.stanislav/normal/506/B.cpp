#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const int P = 1e9+7;
const ll lINF = 1e18;

using namespace std;

int n, m, used[111111], used2[111111], exists[111111], in[111111];
vector<int> org[111111], g[111111];
vector<vector<int>> components;
int cur;

void dfs1(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    components.back().pb(v);
    for (auto i : g[v]) {
        dfs1(i);
    }
}

void topsort(int v) {
    if (used2[v]) {
        return;
    }
    used2[v] = true;
    for (auto i : org[v]) {
        topsort(i);
    }
    in[v] = cur++;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        org[a].pb(b);
        g[a].pb(b);
        g[b].pb(a);
        exists[a] = exists[b] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (exists[i] && !used[i]) {
            components.pb(vector<int>());
            dfs1(i);
        }
    }
    int ans = 0;
    for (auto i : components) {
        for (auto j : i) {
            topsort(j);
        }
        bool flag = false;
        for (auto j : i) {
            for (auto nxt : org[j]) {
                if (in[nxt] > in[j]) {
                    flag = true;
                }
            }
        }
        ans += i.size();
        if (!flag) ans--;
    }
    cout << ans << endl;
    return 0;
}