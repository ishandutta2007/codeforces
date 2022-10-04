#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2007;

char a[N][N];
int p[N];

int n, m;

int get(int x) {
    return (x == p[x] ? x : p[x] = get(p[x]));
}

void join(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) p[a] = b;
}

vector <int> g[N];
int used[N];

void dfs(int u) {
    used[u] = 1;
    for (auto v : g[u]) {
        if (!used[v]) {
            dfs(v);
        }
        else if (used[v] == 1) {
            cout << "No\n";
            exit(0);
        }
    }
    used[u] = 2;
}

vector <int> t;
int val[N];

void jhfs(int u) {
    used[u] = 1;
    for (auto v : g[u]) {
        if (!used[v]) {
            jhfs(v);
        }
        val[u] = max(val[u], val[v] + 1);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    for (int i = 0; i < N; ++i) p[i] = i;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < N; ++i) p[i] = i;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '=') join(i, j + n);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = get(i);
            int y = get(j + n);
            if (a[i][j] != '=' && x == y) {
                cout << "No\n";
                exit(0);
            }
            if (a[i][j] != '=') {
                if (a[i][j] == '<') {
                    g[y].push_back(x);        
                }
                else {
                    g[x].push_back(y);
                }
            }
        }
    }
    for (int i = 0; i < n + m; ++i) if (!used[i]) dfs(i);
    for (int i = 0; i < n + m; ++i) used[i] = 0;
    for (int i = 0; i < n + m; ++i) if (!used[i]) jhfs(i);
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        cout << val[get(i)] + 1 << ' ';
    }
    cout << '\n';
    for (int i = n; i < n + m; ++i) {
        cout << val[get(i)] + 1 << ' ';
    }
}