#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct twosat {

    int size;
    vector<vector<int>> adj;

    vector<bool> on, out;
    vector<int> low, depth, stack, comp;
    int index, cur;

    twosat(int s) : size(s), adj(2*s), out(s, 0) {}

    bool connect(int i) {

        // Tarjan's strongly connected components algorithm
        low[i] = depth[i] = ++index;
        stack.push_back(i);
        on[i] = 1;
        for (int j : adj[i]) {
            if (depth[j] == -1) {
                connect(j);
                low[i] = min(low[i], low[j]);
            } else if (on[j])
                low[i] = min(low[i], depth[j]);
        }

        // Aspvall, Plass & Tarjan algorithm
        if (low[i] == depth[i]) {
            int j = -1;
            while (i != j) {
                j = stack.back(); stack.pop_back();
                int k = (j+size)%(2*size);
                if (comp[k] == cur)
                    return true;
                if (comp[j] == -1 && comp[k] == -1)
                    out[j%size] = j >= size;
                comp[j] = cur;
            }
            cur++;
        }
        return false;
    }

    // returns {} if no solution, otherwise returns
    // a vector of bools indicating a solution.
    // runs in O(V+E), where V is the number of variables,
    // and E is the number of restrictions.
    vector<bool> solve() {

        depth.assign(2*size, -1);
        low.assign(2*size, -1);
        comp.assign(2*size, -1);
        on.assign(2*size, 0);
        stack.clear();
        index = cur = 0;

        for (int i = 0; i < 2*size; i++)
            if (depth[i] == -1 && connect(i))
                return {};
        return out;
    }

    // declare that (x is a) implies (y is b)
    inline void implies(int x, bool a, int y, bool b) {
        adj[x+(a ? size : 0)].push_back(y+(b ? size : 0));
        adj[y+(b ? 0 : size)].push_back(x+(a ? 0 : size));
    }

    // declare that x is true/false
    inline void set(int x, bool a) {
        adj[x+(a ? 0 : size)].push_back(x+(a ? size : 0));
    }
};

struct unionfind {

    vector<int> p, sz;

    unionfind(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x])
            x = p[x] = p[p[x]];
        return x;
    }

    void unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (a == b) return;
        p[b] = a;
        sz[a] += sz[b];
    }

    // returns true if a and b are in the same set.
    bool query(int a, int b) {
        return rep(a) == rep(b);
    }

    // returns the size of the set containing x
    int size(int x) {
        return sz[rep(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, a; cin >> n;
        vector<vector<pair<int, int>>> f(n);
        for (int j = 0; j < 2; j++)
            for (int i = 0; i < n; i++)
                cin >> a, f[--a].pb({j, i});
        bool v = 1;
        twosat s(n);
        unionfind uf(n);
        for (auto& x : f) {
            v = v && x.size() == 2;
            if (!v) break;
            if (x[0].first == x[1].first) {
                s.implies(x[0].second, 1, x[1].second, 0);
                s.implies(x[0].second, 0, x[1].second, 1);
            } else {
                s.implies(x[0].second, 0, x[1].second, 0);
                s.implies(x[0].second, 1, x[1].second, 1);
            }
            uf.unite(x[0].second, x[1].second);
        }
        auto u = s.solve();
        v = v && !u.empty();
        if (v) {
            vector<vector<int>> c(n);
            for (int i = 0; i < n; i++) 
                c[uf.rep(i)].pb(i);
            vector<int> out;
            for (auto& r : c) {
                vector<int> x, y;
                for (auto& i : r) {
                    if (u[i]) x.pb(i);
                    else y.pb(i);
                }
                if (x.size() > y.size()) swap(x, y);
                for (auto& i : x) out.pb(i);
            }
            cout << out.size() << "\n";
            for (auto& i : out) cout << i+1 << " ";
            cout << "\n";
        }
        else cout << "-1\n";
    }
}