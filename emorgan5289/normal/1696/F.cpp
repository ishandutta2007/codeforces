#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

struct dsu {

    vector<int> p, sz;

    dsu(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    // returns true if a and b are in the same set, and then unites them.
    bool unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (sz[a] < sz[b]) swap(a, b);
        if (a != b) p[b] = a, sz[a] += sz[b];
        return a == b;
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

const int N = 101;
int n, eq[N][N][N]; // eq[x][y][z] means d(x, y) == d(x, z)
int dist[N][N];

// check a candidate tree in O(n^3)
bool check(vector<array<int, 2>> e) {

    if (e.size() != n-1)
        return false;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = i == j ? 0 : inf;

    for (auto& [x, y] : e)
        dist[x][y] = dist[y][x] = 1;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist[i][j] == inf)
                return false;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                if (eq[k][i][j] && dist[k][i] != dist[k][j])
                    return false;
                if (!eq[k][i][j] && dist[k][i] == dist[k][j])
                    return false;
            }

    return true;
}

vector<array<int, 2>> tmp_e;
int v[N];

void dfs(int i, int j) {
    v[j] = 1;
    for (int k = 0; k < n; k++)
        if (k != i && eq[j][k][i] && !v[k]) {
            tmp_e.pb({j, k});
            dfs(j, k);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-1-i; j++) {
                string s; cin >> s;
                for (int k = 0; k < n; k++) {
                    eq[k][i][i+j+1] = eq[k][i+j+1][i] = s[k] == '1';
                }
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                eq[i][j][j] = 1;

        bool ok = 0;
        for (int r = 1; r < n; r++) {
            // assume edge {0, r}
            tmp_e.clear();
            tmp_e.pb({0, r});
            fill(v, v+n, 0);
            v[0] = v[r] = 1;
            dfs(0, r);
            dfs(r, 0);
            if (check(tmp_e)) {
                cout << "Yes\n";
                for (auto& [x, y] : tmp_e)
                    cout << x+1 << " " << y+1 << "\n";
                ok = 1;
                break;
            }
        }

        if (!ok) {
            cout << "No\n";
        }
    }
}