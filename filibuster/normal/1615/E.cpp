#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

vector<int> g[N];
int p[N], d[N];

vector<int> ord;
int lf[N], rg[N];

void dfs(int v, int par, int depth) {
    p[v] = par;
    d[v] = depth;

    lf[v] = ord.size();
    ord.push_back(v);

    for(auto u : g[v]) {
        if(u == par)
            continue;

        dfs(u, v, depth + 1);
    }

    rg[v] = ord.size();
}

int a[N];
int ind[N * 4], add[N * 4], mx[N * 4];

void build(int v, int l, int r) {
    if(r - l == 1) {
        mx[v] = a[l];
        ind[v] = l;
        add[v] = 0;
        return;
    }

    int m = (l + r) / 2;

    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);

    if(mx[v * 2 + 1] > mx[v * 2 + 2]) {
        mx[v] = mx[v * 2 + 1];
        ind[v] = ind[v * 2 + 1];
    } else {
        mx[v] = mx[v * 2 + 2];
        ind[v] = ind[v * 2 + 2];
    }
}

void push(int v) {
    int v1 = v * 2 + 1, v2 = v * 2 + 2;
    mx[v1] += add[v];
    add[v1] += add[v];

    mx[v2] += add[v];
    add[v2] += add[v];

    add[v] = 0;
}

void update(int v, int l, int r, int ql, int qr, int x) {
    if(l >= qr || r <= ql)
        return;

    if(ql <= l && r <= qr) {
        add[v] += x;
        mx[v] += x;
        return;
    }

    push(v);

    int m = (l + r) / 2;

    update(v * 2 + 1, l, m, ql, qr, x);
    update(v * 2 + 2, m, r, ql, qr, x);

    if(mx[v * 2 + 1] > mx[v * 2 + 2]) {
        mx[v] = mx[v * 2 + 1];
        ind[v] = ind[v * 2 + 1];
    } else {
        mx[v] = mx[v * 2 + 2];
        ind[v] = ind[v * 2 + 2];
    }
}

bool used[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, 0, 0);

    for(int i = 0; i < n; i++) {
        a[i] = d[ord[i]];
    }

//    for(int i = 0; i < n; i++)
//        cout << ord[i] << ' ';
//    cout << endl;
//    for(int i = 0; i < n; i++)
//        cout << a[i] << ' ';
//    cout << endl;

    build(0, 0, n);

    int r = 0, x = 0;
    for(int i = 0; i < k; i++) {
        if(mx[0] < 0) {
            li ans = 0;
            for(int j = i; j <= k; j++) {
                ans = max(ans, j * 1ll * (n - j));
            }
            cout << ans << endl;
            return 0;
        }

//        cout << mx[0] << ' ' << ind[0] << endl;
        x += mx[0];
        r++;

        int v = ord[ind[0]];

//        cout << "lf rg " << lf[v] << ' ' << rg[v] << endl;

//        update(0, 0, n, lf[v], rg[v], -1);

        do {
//            cout << "upd " << v << ' ' << lf[v] << ' ' << rg[v] << endl;
            update(0, 0, n, lf[v], rg[v], -1);
            used[v] = true;
            v = p[v];
        } while(!used[v]);
//        update()
    }

//    cout << x << ' ' << r << endl;

    li ans = INF64;
    for(int i = 0; i <= n - x - r; i++) {
        ans = min(ans, (n - r - i) * 1ll * (r - i));
//        cout << i << ' ' << ans << endl;
    }

    cout << ans << endl;
}