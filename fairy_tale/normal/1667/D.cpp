#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int mod = 998244353;
const int maxn = 2e5 + 5;

vector<int> g[maxn], h[maxn];
int d[maxn];
P edge[maxn];
bool flag;

void merge(vector<int> &l, vector<int> &r)
{
    int L = l.size();
    int R = r.size();

    for (int i = 0, j = 0; i < L && j < R;) {
        if (L - i == R - j) {
            h[r[j]].push_back(l[i]);
            d[l[i]]++;
            //cout << r[j] << " --> " << l[i] << endl;
            j++;
        } else {
            h[l[i]].push_back(r[j]);
            d[r[j]]++;
            //cout << l[i] << " --> " << r[j] << endl;
            i++;
        }
    }
}

int dfs(int u, int fa, int idx)
{
    int sz = 1, ret;
    vector<int> l, r;

    for (auto e:g[u]) {
        int v = edge[e].fi ^ edge[e].se ^ u;
        if (v == fa) continue;
        sz++;
        ret = dfs(v, u, e);
        if (ret == 1) l.push_back(e);
        else r.push_back(e);
    }

    if (fa != 0) {
        if (r.size() < l.size()) r.push_back(idx), ret = -1;
        else l.push_back(idx), ret = 1;
    }
    if (l.size() != r.size() && l.size() != r.size() + 1) flag = false;

    merge(l, r);
    return ret;
}

void solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) h[i].clear();
    for (int i = 1; i <= n; i++) d[i] = 0;

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        edge[i] = P(u, v);
        g[u].push_back(i);
        g[v].push_back(i);
    }

    flag = true;
    dfs(1, 0, 0);
    if (flag == false) {
        cout << "NO" << endl;
        return;
    } else cout << "YES" << endl;

    queue<int> q;
    for (int i = 1; i < n; i++) {
        if (d[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        u = q.front();
        q.pop();
        cout << edge[u].fi << " " << edge[u].se << endl;
        for (auto v:h[u]) {
            if (--d[v] == 0) q.push(v);
        }
    }
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}