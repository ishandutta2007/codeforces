#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

struct twosat {

    int size;
    vector<vector<int>> adj;

    vector<bool> on, out;
    vector<int> low, depth, stack, comp;
    int index, cur;

    twosat(int s) {
        size = s;
        adj.assign(2*size, {});
        out.assign(size, 0);
    }

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; fin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char c; fin >> c; a[i][j] = c == '1' ? 1 : 0;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char c; fin >> c; a[i][j] ^= c == '1' ? 1 : 0;
        }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        char c; fin >> c; b[i] = c == '1' ? 1 : 0;
    }
    twosat sat(2*n);

    for (auto& row : a) debug(row);
    debug(b);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (!b[i] && !b[j]) {
                if (a[i][j]) {
                    cout << "-1\n"; return 0;
                }
            } else if (b[i] && b[j]) {
                if (a[i][j]) {
                    sat.implies(i, 1, n+j, 0);
                    sat.implies(i, 0, n+j, 1);
                } else {
                    sat.implies(i, 1, n+j, 1);
                    sat.implies(i, 0, n+j, 0);
                }
            } else if (!b[i] && b[j]) {
                if (a[i][j])
                    sat.set(i, 1);
                else
                    sat.set(i, 0);
            } else if (b[i] && !b[j]) {
                if (a[i][j])
                    sat.set(n+j, 1);
                else
                    sat.set(n+j, 0);
            }
        }

    vector<bool> out = sat.solve();
    if (out.empty())
        cout << "-1\n";
    else {
        int s = 0;
        for (int i = 0; i < 2*n; i++)
            if (out[i]) s++;
        cout << s << "\n";
        for (int i = 0; i < n; i++)
            if (out[i]) cout << "row " << i << "\n";
        for (int i = 0; i < n; i++)
            if (out[i+n]) cout << "col " << i << "\n";
    }
}