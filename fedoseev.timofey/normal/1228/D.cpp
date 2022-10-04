#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;

set <int> g[N];

bool con(int u, int v) {
    return g[u].count(v);
}

int type[N];
int sz[4];

void no() {
    cout << "-1\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].insert(v);
        g[v].insert(u);
    }
    vector <int> a;
    a.push_back(0);
    type[0] = 1;
    ++sz[type[0]];
    for (int i = 1; i < n; ++i) {
        if (!con(a[0], i)) {
            a.push_back(i);
            type[i] = 1;
            ++sz[type[i]];
        }
    }
    vector <int> b;
    for (int i = 0; i < n; ++i) {
        if (type[i] == 0) {
            b.push_back(i);
            type[i] = 2;
            ++sz[type[i]];
            break;
        }
    }
    if (b.empty()) {
        no();
    }
    for (int i = 0; i < n; ++i) {
        if (type[i] == 0 && !con(b[0], i)) {
            b.push_back(i);
            type[i] = 2;
            ++sz[type[i]];
        }
    }
    vector <int> c;
    for (int i = 0; i < n; ++i) {
        if (type[i] == 0) {
            c.push_back(i);
            type[i] = 3;
            ++sz[type[i]];
            break;
        }
    }
    if (c.empty()) {
        no();
    }
    for (int i = 0; i < n; ++i) {
        if (type[i] == 0 && !con(c[0], i)) {
            c.push_back(i);
            type[i] = 3;
            ++sz[type[i]];
        }
    }
    if (sz[1] + sz[2] + sz[3] != n) no();
    for (int i = 0; i < n; ++i) {
        for (int j : g[i]) {
            if (type[i] == type[j]) {
                no();
            }
        }
    }
    if (m != (ll)sz[1] * sz[2] + (ll)sz[2] * sz[3] + (ll)sz[3] * sz[1]) no();
    for (int i = 0; i < n; ++i) cout << type[i] << ' ';
}