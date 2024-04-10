//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 3e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
//const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

vector<int> g[N];
pii e[N];
int deg[N];
int p[N];
int d[N];
bool used[N];
pii qr[N];
//vector<int> b[N];
//pii e[N];
//int cur[N];
//vector<int> cyc;
//vector<int> path[N];

void dfs1(int v, int par, int depth) {
    p[v] = par;
    d[v] = depth;
    used[v] = true;

    for(auto ed : g[v]) {
        int u = e[ed].f ^ e[ed].s ^ v;
        if(used[u])
            continue;
        dfs1(u, v, depth + 1);
    }
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        e[i] = {v, u};
        g[v].push_back(i);
        g[u].push_back(i);
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        deg[v]++;
        deg[u]++;

        qr[i] = {v, u};
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += deg[i] % 2;
    }

    if(cnt > 0) {
        cout << "NO" << endl << cnt / 2 << endl;
        return 0;
    }

    cout << "YES" << endl;

    dfs1(0, 0, 0);

    for(int i = 0; i < q; i++) {
        vector<int> a, b;
        int v = qr[i].f, u = qr[i].s;
        while(v != u) {
//            cout << v << ' ' << u << ' ' << d[v] << ' ' << d[u] << ' ' << p[v] << ' ' << p[u] << endl;
            if(d[v] >= d[u]) {
                a.push_back(v);
                v = p[v];
            } else {
                b.push_back(u);
                u = p[u];
            }
        }

        a.push_back(v);

        cout << a.size() + b.size() << '\n';
        for(int j = 0; j < a.size(); j++)
            cout << a[j] + 1 << ' ';
        for(int j = b.size() - 1; j >= 0; j--)
            cout << b[j] + 1 << ' ';
        cout << '\n';
    }
}