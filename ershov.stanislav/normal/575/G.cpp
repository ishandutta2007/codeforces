#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#define rank _rank

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int MOD = 1e9 + 7;

const int N = 1e5 + 100;

vector<int> graph[N];
vector<int> len[N];
int n, m;
int dist[N];
vector<int> ondist[N];
int ndist[N];
int par[N];
int prdist[N];

vector<int> comp;
bool used[N];

void dfs(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    comp.pb(v);
    for (int j = 0; j < (int) graph[v].size(); j++) {
        if (len[v][j] == 0) {
            dfs(graph[v][j]);
        }
    }
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        graph[u].pb(v);
        graph[v].pb(u);
        len[u].pb(l);
        len[v].pb(l);
    }
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (auto i : graph[cur]) {
            if (dist[i] == INF) {
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        prdist[i] = dist[i];
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] < INF) ondist[dist[i]].pb(i);
    }
    ndist[0] = 0;
    for (int i = 1; i < n; i++) {
        vector<int> dists;
        for (auto j : ondist[i]) {
            int mn = INF;
            for (int kk = 0; kk < graph[j].size(); kk++) {
                int k = graph[j][kk];
                if (dist[k] == i - 1) {
                    mn = min(mn, len[j][kk] * 1000000 + ndist[k]);
                }
            }
            dists.pb(mn);
            ndist[j] = mn;
        }
        sort(all(dists));
        map<int, int> mp;
        for (int i = 0, cur = 0; i < dists.size(); i++) {
            if (i > 0 && dists[i] > dists[i - 1]) {
                cur++;
            }
            mp[dists[i]] = cur;
        }
        for (auto j : ondist[i]) {
            ndist[j] = mp[ndist[j]];
        }
    }

    dfs(n - 1);
    int mn = INF;
    for (auto i : comp) {
        mn = min(mn, dist[i]);
    }
    vector<int> v;
    for (auto i : comp) {
        if (dist[i] == mn) {
            v.pb(i);
        }
    }
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        par[i] = -1;
    }
    dist[n - 1] = 0;
    q.push(n - 1);
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (int ii = 0; ii < (int) graph[cur].size(); ii++) {
            int i = graph[cur][ii];
            if (len[cur][ii] != 0) {
                continue;
            }
            if (dist[i] == INF) {
                dist[i] = dist[cur] + 1;
                par[i] = cur;
                q.push(i);
            }
        }
    }
    pair<int, int> mnm = mp(INF, INF);
    for (auto i : v) {
        mnm = min(mnm, mp(ndist[i], dist[i]));
    }
    vector<int> ans;
    for (auto i : v) {
        if (mnm == mp(ndist[i], dist[i])) {
            for (int cur = i; ;) {
                ans.pb(cur);
                if (cur == 0) {
                    break;
                }
                pair<int, int> mn = mp(INF, INF);
                for (int jj = 0; jj < graph[cur].size(); jj++) {
                    int j = graph[cur][jj];
                    if (prdist[j] < prdist[cur]) mn = min(mn, mp(len[cur][jj] * 1000000 + ndist[j], j));
                }
                cur = mn.sc;
            }
            reverse(all(ans));
            for (int cur = par[i]; cur != -1; cur = par[cur]) {
                ans.pb(cur);
            }
            break;
        }
    }

    string str_ans;
    for (int i = 1; i < (int) ans.size(); i++) {
        for (int jj = 0; jj < graph[ans[i]].size(); jj++) {
            int j = graph[ans[i]][jj];
            if (j == ans[i - 1]) {
                str_ans.pb(len[ans[i]][jj] + '0');
            }
        }
    }
    int len = str_ans.length();
    while (len > 1 && str_ans[len - 1] == '0') {
        len--;
    }
    for (int i = 0; i * 2 < len; i++) {
        swap(str_ans[i], str_ans[len - 1 - i]);
    }
    for (int i = 0; i < len; i++) {
        printf("%c", str_ans[i]);
    }
    printf("\n%d\n", (int) ans.size());
    for (auto i : ans) {
        printf("%d ", i);
    }

    return 0;
}