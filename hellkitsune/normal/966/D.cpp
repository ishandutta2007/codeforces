#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> g[300000];
int dist[300000], pre[300000], cm[300000], cnt = 0;
vector<int> cv[300000];
queue<int> q;
vector<int> ans;
bool mark[300000];
vector<int> marked;

void dfs(int v) {
    cm[v] = cnt;
    cv[cnt].pb(v);
    for (int to : g[v]) if (to != 0 && cm[to] == -1) {
        dfs(to);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    memset(dist, -1, sizeof dist);
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) if (dist[to] == -1) {
            dist[to] = dist[v] + 1;
            pre[to] = v;
            q.push(to);
        }
    }
    int len = 12341234;
    if (dist[n - 1] != -1) {
        len = dist[n - 1];
        for (int v = n - 1; v != 0; v = pre[v]) {
            ans.pb(v);
        }
        ans.pb(0);
        reverse(ans.begin(), ans.end());
    }

    forn(i, n) if (dist[i] == 2 && len > 4) {
        len = 4;
        ans.clear();
        ans.pb(n - 1);
        ans.pb(0);
        for (int v = i; v != 0; v = pre[v]) {
            ans.pb(v);
        }
        ans.pb(0);
        reverse(ans.begin(), ans.end());
    }

    if (len > 5) {
        memset(cm, -1, sizeof cm);
        forn(i, n) if (dist[i] == 1 && cm[i] == -1) {
            dfs(i);
            ++cnt;
        }
        int found = -1;
        forn(i, cnt) {
            for (int u : cv[i]) {
                if ((int)g[u].size() != (int)cv[i].size()) {
                    found = u;
                    break;
                }
            }
            if (found != -1) {
                break;
            }
        }
        if (found != -1) {
            mark[0] = true;
            mark[found] = true;
            for (int to : g[found]) if (to != 0) {
                mark[to] = true;
                marked.pb(to);
            }
            for (int v : marked) {
                for (int to : g[v]) if (!mark[to]) {
                    ans.pb(0);
                    ans.pb(found);
                    ans.pb(v);
                    ans.pb(to);
                    ans.pb(found);
                    ans.pb(n - 1);
                    len = 5;
                    break;
                }
                if (len == 5) {
                    break;
                }
            }
        }
    }

    if (len == 12341234) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", len);
    for (int v : ans) {
        printf("%d ", v + 1);
    }
    puts("");
    return 0;
}