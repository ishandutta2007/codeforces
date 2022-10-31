#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define y1 my1

using namespace std;

const int M = 1e7 + 100;
const int N = 800;

char s[M];
int n, cntv = 1;
int nxt[M][2], suff[M], par[M], chr[M], fast[M];
int lens[N], starts[N];
int es[M], last[N];
int graph1[N][N];
vector<int> graph[N];
int p[N], hasp[N], used[N], bad[N];

int add() {
    int len = strlen(s);
    int cur = 0;
    for (int i = 0; i < len; i++) {
        int to = nxt[cur][s[i] - 'a'];
        if (!to) {
            to = cntv++;
            par[to] = cur;
            chr[to] = s[i] - 'a';
            nxt[cur][s[i] - 'a'] = to;
        }
        cur = to;
    }
    return cur;
}

void aho() {
    queue<int> q;
    q.push(0);
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (int it = 0; it < 2; it++) {
            if (nxt[cur][it]) {
                q.push(nxt[cur][it]);
            }
        }
        if (cur) {
            if (par[cur]) {
                suff[cur] = nxt[suff[par[cur]]][chr[cur]];
                if (fast[cur] == -1) {
                    fast[cur] = fast[suff[cur]];
                }
            }
            for (int it = 0; it < 2; it++) {
                if (!nxt[cur][it]) {
                    nxt[cur][it] = nxt[suff[cur]][it];
                }
            }
        }
    }
}

bool dfs(int v) {
    if (used[v]) {
        return false;
    } else {
        used[v] = true;
        for (auto i : graph[v]) {
            if (p[i] == -1 || dfs(p[i])) {
                p[i] = v;
                return true;
            }
        }
        return false;
    }
}

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    memset(fast, -1, sizeof(fast));
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int cur = add();
        fast[cur] = cur;
        es[cur] = i;
        last[i] = cur;
    }
    aho();
    for (int i = 0; i < n; i++) {
        for (int cur = last[i]; cur != 0; cur = par[cur]) {
            int lng = 0;
            if (cur == last[i]) {
                lng = fast[suff[cur]];
            } else {
                lng = fast[cur];
            }
            while (lng != -1 && !graph1[es[lng]][i]) {
                graph1[es[lng]][i] = 1;
                lng = fast[lng];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph1[i][j]) {
                graph[i].pb(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        p[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        memset(used, 0, sizeof(used));
        if (dfs(i)) {
            hasp[i] = 1;
        }
    }
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++) {
        if (!hasp[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (p[i] != -1) {
            if (used[p[i]]) {
                bad[i] = true;
            } else {
                bad[p[i]] = true;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!bad[i]) {
            ans.pb(i);
        }
    }
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); i++) {
        printf("%d%c", ans[i] + 1, " \n"[i == sz(ans) - 1]);
    }
    return 0;
}