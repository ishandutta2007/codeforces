#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;

map <int, int> p;
map <int, int> sz;
map <int, map <int, int>> xr;

int get(int u) {
    int pr = u;
    if (p.count(u)) pr = p[u];
    if (pr == u) return pr;
    return p[u] = get(p[u]);
}

void merge(int a, int b, int w) {
    int u = a;
    int v = b;
    a = get(a);
    b = get(b);
    if (sz[a] == 0) sz[a] = 1;
    if (sz[b] == 0) sz[b] = 1;
    w ^= xr[a][u];
    w ^= xr[b][v];
    if (a != b) {
        if (sz[a] > sz[b]) swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
        for (auto p : xr[a]) {
            xr[b][p.first] = p.second ^ w;
        }
        xr[a].clear();
    }
}

int answer(int a, int b) {
    //cout << get(a) << ' ' << get(b) << endl;
    int rt = get(a);
    if (get(b) != rt) return -1;
    return xr[rt][a] ^ xr[rt][b];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int q;
    cin >> q;
    int last = 0;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l ^= last;
            r ^= last;
            x ^= last;
            if (l > r) swap(l, r);
            merge(l, r + 1, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            l ^= last;
            r ^= last;
            if (l > r) swap(l, r);
            int ans = answer(l, r + 1);
            last = abs(ans);
            cout << ans << endl;
        }
    }
}