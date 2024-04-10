#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        //cerr << testNum << endl;
        solve(true);
        //cerr << testNum - 1 << endl;
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

void precalc() {
}

//#define int li
//const int mod = 1000000007;

const int maxN = 100500, logMaxN = 17;
int p[logMaxN][maxN];

int n;
vector<vector<int>> e;
vector<int> in, out;
int inTimer;
vector<int> f, male;
vector<int> vert;

void dfs(int v, int par = -1) {
    if (par != -1)
        p[0][v] = par;

    in[v] = inTimer++;
    vert.push_back(v);

    for (int u: e[v])
        if (u != par) {
            dfs(u, v);
        }

    out[v] = inTimer++;
    vert.push_back(v);
}

bool isPc(int p, int c) {
    return in[c] >= in[p] && out[c] <= out[p];
}

int lca(int u, int v) {
    if (isPc(u, v)) return u;
    if (isPc(v, u)) return v;

    for (int log = logMaxN - 1; log >= 0; log--)
        if (!isPc(p[log][u], v))
            u = p[log][u];

    return p[0][u];
}

const int BLOCK = 450;

li cur_ans;

struct fcnt {
    int nm, nf;
};

vector<fcnt> cnt;
vector<char> taken;

void mod_vertex(int v) {
    fcnt& x = cnt[f[v]];

    cur_ans -= x.nm * (li)x.nf;
    if (taken[v]) {
        if (male[v]) x.nm--; else x.nf--;
        taken[v] = false;
    }
    else {
        if (male[v]) x.nm++; else x.nf++;
        taken[v] = true;
    }
    cur_ans += x.nm * (li)x.nf;
}

void mod_pos(int pos) {
    mod_vertex(vert[pos]);
}

struct query {
    int l, r, root;
    int index;

    pair<int, int> get() const { return make_pair(l / BLOCK, r); }

    bool operator<(const query& q) const { return get() < q.get(); }

    li get_ans() {
        bool rollback = false;
        if (root != -1 && !taken[root]) {
            mod_vertex(root);
            rollback = true;
        }

        li answer = cur_ans;

        if (rollback) {
            mod_vertex(root);
        }

        return answer;
    }
};

void solve(bool read) {
    inTimer = 0;

    cin >> n;
    f.resize(n);
    male.resize(n);
    in.resize(n);
    out.resize(n);

    for (int i = 0; i < n; i++) cin >> male[i];
    for (int i = 0; i < n; i++) cin >> f[i];

    vector<int> f_key = f;
    sort(all(f_key));
    f_key.erase(unique(all(f_key)), f_key.end());

    for (int& x: f)
        x = lower_bound(all(f_key), x) - f_key.begin();

    cnt.resize(f_key.size());

    e.resize(n);
    taken.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(0);

    for (int log = 1; log < logMaxN; log++)
        for (int v = 0; v < n; v++)
            p[log][v] = p[log - 1][p[log - 1][v]];

    int q;
    cin >> q;

    vector<query> queries(q);

    for (int qi = 0; qi < q; qi++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        queries[qi].root = -1;
        queries[qi].index = qi;

        if (!isPc(u, v) && !isPc(v, u)) {
            if (!(out[v] < in[u])) swap(v, u);
            assert(out[v] <= in[u]);
            queries[qi].l = out[v];
            queries[qi].r = in[u];
            queries[qi].root = lca(u, v);
        }
        else if (isPc(u, v)) {
            queries[qi].l = in[u];
            queries[qi].r = in[v];
        }
        else {
            queries[qi].l = in[v];
            queries[qi].r = in[u];
        }
    }

    sort(all(queries));

#if 0
    for (int i = 0; i < 2 * n; i++)
        cout << vert[i] + 1 << " ";
    cout << "\n";
    cout.flush();

    for (auto it: queries)
        printf("query %d..%d index %d\n", it.l + 1, it.r + 1, it.index + 1);
#endif

    vector<li> answer(q);

    int l = 0, r = -1;
    for (query& q: queries) {
        while (r < q.r) {
            r++;
            mod_pos(r);
        }

        while (l < q.l) {
            mod_pos(l);
            l++;
        }

        while (l > q.l) {
            l--;
            mod_pos(l);
        }

        while (r > q.r) {
            mod_pos(r);
            r--;
        }

        answer[q.index] = q.get_ans();
    }

    for (int i = 0; i < q; i++)
        cout << answer[i] << "\n";
}