#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
const int INF = 1e9 + 7;

int l[MAXN], r[MAXN];
int tree[MAXN * 4];
vector <int> pos[MAXN];

void upd(int v, int tl, int tr, int p) {
    if (tl == tr) {
        ++tree[v];
        return;
    }
    int tm = (tl + tr) / 2;
    if (p <= tm) upd(v * 2 + 1, tl, tm, p);
    else upd(v * 2 + 2, tm + 1, tr, p);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return tree[v];
    int tm = (tl + tr) / 2;
    return get(v * 2 + 1, tl, tm, l, r) + get(v * 2 + 2, tm + 1, tr, l, r);
}

bool check(int n, int q, int a[]) {
    for (int i = 0; i < MAXN; ++i) l[i] = INF;    
    for (int i = 0; i < MAXN; ++i) r[i] = -1;
    for (int i = 0; i < MAXN; ++i) pos[i].clear();
    for (int i = 0; i < n; ++i) {
        l[a[i]] = min(l[a[i]], i);
        r[a[i]] = max(r[a[i]], i);
        pos[a[i]].push_back(i);
    }   
    if (pos[q].empty()) return 0;
    for (int i = q; i >= 1; --i) {
        if (pos[i].empty()) continue;
        int x = get(0, 0, n - 1, l[i], r[i]);
        int y = pos[i].size();
        int len = r[i] - l[i] + 1;
        if (x + y != len) {
            return 0;
        }
        for (int p : pos[i]) {
            upd(0, 0, n - 1, p);
        }
    }
    return 1;
}

int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    bool want = 1;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        want &= (a[i] != q);
        k += (a[i] == 0);
    }

    if (want) {
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                a[i] = q;
                break;
            }
        }
    }
    
    if (k == n) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) cout << q << ' ';
        cout << '\n';
        exit(0);
    }

    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i]) c = a[i];
        else a[i] = c;
    }
    c = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i]) c = a[i];
        else a[i] = c;
    }
    
    if (check(n, q, a)) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) cout << a[i] << ' ';
        cout << '\n';
    }
    else {
        cout << "NO\n";
    }

    return 0;
}