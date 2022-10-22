#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t << 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PL;

const int maxn = 4e5 + 5;
const int mod = 1e9 + 7;

struct TwoSat {
    vector<int> g[maxn * 2];
    int pre[maxn * 2],low[maxn * 2],scc[maxn * 2], ans[maxn];
    int dfs_t, scc_cnt, _n;
    stack<int> ST;

    void dfs(int u)
    {
        pre[u] = low[u] = ++dfs_t;
        ST.push(u);
        for(auto v:g[u]) {
            if(!pre[v]) {
                dfs(v);
                low[u] = min(low[u],low[v]);
            } else if(!scc[v]) {
                low[u] = min(low[u],pre[v]);
            }
        }
        if(low[u] == pre[u]) {
            scc_cnt++;
            while(!ST.empty()) {
                int x = ST.top();
                ST.pop();
                scc[x] = scc_cnt;
                if(x == u) break;
            }
        }
    }

    void add_edge(int u, int val1, int v, int val2) // 1  0
    {
        g[u << 1 | val1].push_back(v << 1 | val2);
		if (u != v) g[v << 1 | (val2 ^ 1)].push_back(u << 1 | (val1 ^ 1));
    }

    bool check()
    {
        for(int i = 0; i < _n * 2; i++) {
            if(!pre[i]) dfs(i);
        }

        //ii+1
        for(int i = 0; i < _n; i++) {
            if(scc[i << 1] == scc[i << 1 | 1]) return false;
            ans[i] = scc[i << 1] > scc[i << 1 | 1];
            //cout << i << " == " << ans[i] << endl;
        }
        return true;
    }

    void init(int n)
    {
        _n = n;
        dfs_t = scc_cnt = 0;
        fill(pre, pre + _n * 2, 0);
        fill(scc, scc + _n * 2, 0);
        for (int i = 0; i < _n * 2; i++) g[i].clear();
    }
} ts;

void solve()
{
    int n, m, k, op, a, b, x;
    cin >> n >> m >> k;

    ts.init(n * k);
    for (int i = 1; i < n; i++) { // A[i - 1] <= A[i]
        int offset0 = (i - 1) * k;
        int offset1 = i * k;
        for (int j = 0; j < k; j++) ts.add_edge(offset0 + j, 1, offset1 + j, 1);
    }

    for (int i = 0; i < n; i++) {
        int offset = i * k;
        ts.add_edge(offset, 0, offset, 1); // select >=1
        for (int j = 1; j < k; j++) ts.add_edge(offset + j, 1, offset + j - 1, 1); // >=j  -->  >=j-1
    }

    for (int i = 0; i < m; i++) {
        cin >> op >> a >> b;
        if (op == 1) { // A[a] != b
            int offset = (a - 1) * k;
            if (b < k) ts.add_edge(offset + b - 1, 1, offset + b, 1); // if >=b  -->  >=b+1
            else ts.add_edge(offset + b - 1, 1, offset + b - 1, 0); // no >=b
        } else if (op == 2) { // A[a] + A[b] <= x
            int offset0 = (a - 1) * k;
            int offset1 = (b - 1) * k;
            cin >> x;
            x -= 2;
            for (int j = 0; j < k; j++) {
                int r = x - j;
                if (r >= k - 1) continue;
                if (r < 0) {
                    ts.add_edge(offset0 + j, 1, offset0 + j, 0); // no >=j
                    ts.add_edge(offset1 + j, 1, offset1 + j, 0);
                } else {
                    ts.add_edge(offset0 + j, 1, offset1 + r + 1, 0); // >=j  -->  <=r
                    ts.add_edge(offset1 + j, 1, offset0 + r + 1, 0);
                }
            }
        } else if (op == 3) { // A[a] + A[b] >= x
            int offset0 = (a - 1) * k;
            int offset1 = (b - 1) * k;
            cin >> x;
            x -= 2;
            for (int j = 0; j < k - 1; j++) {
                int r = x - j;
                if (r < 0) continue;
                if (r > k - 1) {
                    ts.add_edge(offset0 + j, 1, offset0 + j + 1, 1); // must >j
                    ts.add_edge(offset1 + j, 1, offset1 + j + 1, 1);
                } else {
                    ts.add_edge(offset0 + j + 1, 0, offset1 + r, 1); // <=j  -->  >=r
                    ts.add_edge(offset1 + j + 1, 0, offset0 + r, 1);
                }
            }
        }
    }

    if (!ts.check()) {
        cout << -1 << endl;
        return;
    }

    vector<int> f(n, 0);
    for (int i = 0; i < n; i++) {
        int offset = i * k;
        for (int j = 0; j < k; j++) {
            if (ts.ans[offset + j]) f[i] = j + 1;
        }

        if (!f[i]) {
            cout << -1 << endl;
            return;
        }
    }

    for (auto e:f) cout << e << " ";
    cout << endl;
}

int main()
{
#ifdef FEIFEI
    //freopen("E:\\code\\input.txt", "r", stdin);
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