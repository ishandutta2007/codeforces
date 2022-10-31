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

#define sz(s) int((s).size())
#define all(s) (s).begin(), (s).end()

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

const int N = 1111;

int n, m, dist[N];
vector<pair<int, int> > edges;
vector<int> graph[N];
vector<vector<int> > comps;
bool used[N];

void dfs(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    comps.back().pb(v);
    for (auto i : graph[v]) {
        dfs(i);
    }
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edges.eb(a, b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            comps.pb(vector<int> ());
            dfs(i);
//            for (auto k : comps.back()) {
//                cout << k << ' ';
//            }
//            cout << endl;
        }
    }

    int ans = -1;

    bool flag2 = true;

    for (int ii = 0; ii < (int) comps.size(); ii++) {
        int mx = -1;

        for (auto i : comps[ii]) {
            queue<int> q;
            for (int i = 1; i <= n; i++) {
                dist[i] = INF;
            }
            dist[i] = 0;
            q.push(i);
            while (q.size()) {
                int cur = q.front();
                q.pop();
                for (auto j : graph[cur]) {
                    if (dist[j] == INF) {
                        dist[j] = dist[cur] + 1;
                        q.push(j);
                    }
                }
            }
//            cout << i << endl;
//            for (int i = 1; i <= n; i++) {
//                cout << dist[i] << ' ';
//            }
//            cout << endl;
            bool flag = true;
            for (auto & i : edges) {
                if (dist[i.fs] == dist[i.sc] && dist[i.fs] != INF) {
                    flag = false;
                    break;
                }
            }
//            cout << flag << endl;
            if (flag) {
                for (int i = 1; i <= n; i++) {
                    if (dist[i] != INF) mx = max(mx, dist[i]);
                }
            }
        }
        if (mx == -1) {
            flag2 = false;
        } else {
            ans = ans + mx;
        }
    }
    if (flag2) cout << ans + 1 << endl;
    else cout << -1 << endl;
    return 0;
}