#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1007;

vector <int> g[N];
int h[N];
int tin[N];
int tout[N];
int pr[N];

int timer;

void dfs(int u = 0, int p = -1) {
    pr[u] = p;
    h[u] = (p == -1 ? 0 : h[p] + 1);
    tin[u] = timer++;
    for (auto v : g[u]) {
        if (v != p) dfs(v, u);
    }
    tout[u] = timer++;
}

bool anc(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int ask(char c, int u) {
    cout << c << ' ' << u + 1 << endl;
    int x;
    cin >> x;
    return x - 1;
}

void solve() {
    timer = 0;
    for (int i = 0; i < N; ++i) g[i].clear();
    int n;
    cin >> n;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs();
    int k1;
    cin >> k1;
    set <int> a;
    for (int i = 0; i < k1; ++i) {
        int x;
        cin >> x;
        --x;
        a.insert(x);
    }
    int k2;
    cin >> k2;
    set <int> b;
    for (int i = 0; i < k2; ++i) {
        int x;
        cin >> x;
        --x;
        b.insert(x);
    }
    int w = ask('B', *b.begin());
    if (a.count(w)) {
        cout << "C " << w + 1 << endl;
        return; 
    }   
    int rt = *a.begin();
    for (auto x : a) {
        if (h[rt] > h[x]) rt = x;
    }
    assert(rt != -1);
    if (anc(rt, w)) {
        while (!a.count(w)) {
            w = pr[w];
        }
        int wh = ask('A', w);
        if (b.count(wh)) {
            cout << "C " << w + 1 << endl;
            return;
        }
        else {
            cout << "C " << -1 << endl;
            return;
        }
    }
    else {
        int wh = ask('A', rt);
        if (b.count(wh)) {
            cout << "C " << rt + 1 << endl;
            return;
        }
        else {
            cout << "C " << -1 << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}