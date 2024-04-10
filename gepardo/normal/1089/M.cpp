#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector< vector<int> > g(n);
    vector< vector<int> > gr(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int q; cin >> q;
            if (q == 1) {
                g[i].push_back(j);
                gr[j].push_back(i);
            }
        }
    }

    vector<char> used(n, false);
    vector<int> topSort;
    vector<int> comp(n, -1);
    int cmp = 0;

    function<void(int)> dfs = [&](int v) {
        if (used[v]) {
            return;
        }
        used[v] = true;
        for (int to : gr[v]) {
            dfs(to);
        }
        topSort.push_back(v);
    };
    for (int i = 0; i < n; ++i) {
        dfs(i);
    }

    reverse(begin(topSort), end(topSort));

    function<void(int)> dfs2 = [&](int v) {
        if (used[v]) {
            return;
        }
        used[v] = true;
        comp[v] = cmp;
        for (int to : g[v]) {
            dfs2(to);
        }
    };
    used.assign(n, false);
    for (int i: topSort) {
        if (!used[i]) {
            dfs2(i);
            ++cmp;
        }
    }

    static char res[200][200][200] = {};
    int z = 2*cmp + 1;
    int x = 3;
    int y = max(n, 2*cmp + 1);
    for (int i = 0; i < z; ++i) {
        for (int j = 0; j < x; ++j) {
            for (int k = 0; k < y; ++k) {
                res[i][j][k] = '#';
            }
        }
    }
    for (int i = 0; i < z; i += 2) {
        for (int j = 0; j < y; ++j) {
            res[i][0][j] = '.';
        }
    }
    for (int i = 0; i < y; i += 2) {
        for (int j = 0; j < z; ++j) {
            res[j][2][i] = '.';
        }
        if (i != 0) res[i-1][2][i] = '#';
    }

    static bool go[20][20] = {};
    for (int i = 0; i < n; ++i) {
        for (int j : g[i]) {
            if (comp[i] == comp[j]) {
                continue;
            }
            assert(comp[i] > comp[j]);
            go[comp[i]][comp[j]] = true;
        }
        go[comp[i]][comp[i]] = true;
    }

    vector<int> cs(cmp, 0);
    for (int i = 0; i < n; ++i) {
        int c = comp[i];
        res[c*2][0][cs[c]] = char('1' + i);
        ++cs[c];
    }

    for (int k = 0; k < cmp; ++k) {
        for (int i = 0; i < cmp; ++i) {
            for (int j = 0; j < cmp; ++j) {
                if (go[i][k] && go[k][j]) {
                    go[i][j] = true;
                }
            }
        }
    }

    for (int i = 0; i < cmp; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (go[i][j]) {
                res[i*2][1][j*2] = '.';
            }
        }
    }

    cout << y << " " << x << " " << z << endl;
    for (int i = z-1; i >= 0; --i) {
        for (int j = 0; j < x; ++j) {
            cout << res[i][j] << endl;
        }
        cout << endl;
    }


    return 0;
}