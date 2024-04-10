#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read);

#define int li

ostream& dbgPrintContainer(ostream& os, const auto& container, const char* brackets = "[]") {
    os << brackets[0] << " ";
    for (auto& elem : container) {
        os << elem << " ";
    }
    os << brackets[1];
    return os;
}

ostream& operator<<(ostream& os, const pair<auto, auto>& p) {
    return os << "(" << p.first << " " << p.second << ")";
}

ostream& operator<<(ostream& os, const vector<auto>& v) { return dbgPrintContainer(os, v, "[]"); }
ostream& operator<<(ostream& os, const set<auto>& v) { return dbgPrintContainer(os, v, "{}"); }
ostream& operator<<(ostream& os, const map<auto, auto>& v) { return dbgPrintContainer(os, v, "{}"); }

signed main() {
    auto t0 = clock();
    cout << fixed << setprecision(12);

#ifdef YA
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    solve(true);

#if 0
    while (true) {
        solve(false);
    }
#endif

#ifdef YA
    cerr << endl << endl << fixed << setprecision(5) << (clock() - t0) / (double)CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

struct dsu_t {
    int n = 0;
    vector<int> p;

    dsu_t(int n): n(n), p(n) {
        iota(all(p), 0);
    }

    int get(int i) {
        return i == p[i] ? i : (p[i] = get(p[i]));
    }

    bool unite(int i, int j) {
        i = get(i);
        j = get(j);

        if (i == j) {
            return false;
        }

        p[i] = j;
        return true;
    }
};

vector<vector<int>> e;

const int INF = 1e9 + 100;

const int logMaxN = 20;
const int maxN = 500500;
int par[logMaxN][maxN];
int relax[logMaxN][maxN];
vector<int> inTime, outTime;
int timer = 0;

void dfs(int v, int p = -1) {
    par[0][v] = p == -1 ? v : p;
    inTime[v] = timer++;

    for (int u: e[v]) {
        if (u == p) {
            continue;
        }

        dfs(u, v);
    }

    outTime[v] = timer++;
}

bool isPc(int p, int c) {
    return inTime[c] >= inTime[p] && outTime[c] <= outTime[p];
}

void addEdge(int u, int v) {
    e[u].push_back(v);
    e[v].push_back(u);

    //cout << "add edge " << u + 1 << " " << v + 1 << endl;
}

void xlca(int U, int V, int w) {
    //cout << "xlca " << U + 1 << " " << V + 1 << " " << w << endl;

    auto walkUp = [&](int v, int u) {
        if (isPc(v, u)) {
            //cout << v + 1 << " is pc with " << u + 1 << endl;
            return;
        }

        for (int log = logMaxN - 1; log >= 0; --log) {
            if (!isPc(par[log][v], u)) {
                relax[log][v] = min(relax[log][v], w);
                //cout << "relax " << log << " " << v << " with " << w << endl;
                v = par[log][v];
            }
        }

        assert(!isPc(v, u));
        relax[0][v] = min(relax[0][v], w);
        //cout << "relax " << 0 << " " << v << " with " << w << endl;
        v = par[0][v];
        assert(isPc(v, u));
    };

    walkUp(U, V);
    walkUp(V, U);
}

void solve(bool __attribute__((unused)) read) {
    int n, k, m;
    cin >> n >> k >> m;

    dsu_t dsu(n);

    e.resize(n);
    inTime.assign(n, 0);
    outTime.assign(n, 0);

    vector<pair<int, int>> kEdges;

    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        assert(dsu.unite(u, v));
        addEdge(u, v);
        kEdges.emplace_back(u, v);
    }

    struct edge {
        int u = 0, v = 0, w = 0;
    };

    vector<edge> offEdges;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        if (!dsu.unite(u, v)) {
            offEdges.push_back(edge{u, v, w});
        } else {
            addEdge(u, v);
        }
    }

    dfs(0);

    for (int log = 0; log < logMaxN; ++log) {
        for (int v = 0; v < n; ++v) {
            relax[log][v] = INF;
        }
    }

    for (int log = 1; log < logMaxN; ++log) {
        for (int v = 0; v < n; ++v) {
            par[log][v] = par[log - 1][par[log - 1][v]];
        }
    }

    for (auto& e : offEdges) {
        xlca(e.u, e.v, e.w);
    }

    auto doRelax = [](int& a, int b) {
        a = min(a, b);
    };

    for (int log = logMaxN - 2; log >= 0; --log) {
        for (int v = 0; v < n; ++v) {
            doRelax(relax[log][v], relax[log + 1][v]);
            doRelax(relax[log][par[log][v]], relax[log + 1][v]);
        }
    }

    li answer = 0;

    bool ansIsInf = false;

    for (auto it : kEdges) {
        int u = it.first;
        int v = it.second;

        if (u != par[0][v]) {
            swap(u, v);
        }
        assert(u == par[0][v]);

        if (relax[0][v] == INF) {
            ansIsInf = true;
        } else {
            answer += relax[0][v];
        }
    }

    if (ansIsInf) {
        cout << -1 << endl;
        return;
    }

    cout << answer << endl;
}