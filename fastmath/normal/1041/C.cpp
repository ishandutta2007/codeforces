#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

bool tree[MAXN * 4];

void build(int v, int tl, int tr) {
    tree[v] = 1;
    if (tl == tr) return;
    int tm = (tl + tr) / 2;
    build(v * 2 + 1, tl, tm);
    build(v * 2 + 2, tm + 1, tr);
}

void del(int v, int tl, int tr, int p) {
    if (tl == tr) {
        tree[v] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    if (p <= tm) del(v * 2 + 1, tl, tm, p);
    else del(v * 2 + 2, tm + 1, tr, p);
    tree[v] = tree[v * 2 + 1] | tree[v * 2 + 2];
}

int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return -1;
    if (!tree[v]) return -1;
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    int t = get(v * 2 + 1, tl, tm, l, r);
    if (t != -1) return t;
    else return get(v * 2 + 2, tm + 1, tr, l, r);
}

int a[MAXN], b[MAXN];
int ans[MAXN];

int per[MAXN];
bool comp(int i, int j) {
    return a[i] < a[j];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, d;
    cin >> n >> m >> d;
    ++d;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) per[i] = i;
    sort(per, per + n, comp);
    for (int i = 0; i < n; ++i) b[i] = a[per[i]];

    build(0, 0, n - 1);

    int curr = 0;
    while (tree[0]) {
        ++curr;
        int u = get(0, 0, n - 1, 0, n - 1);
        ans[per[u]] = curr;
        //cout << u << ' ' << per[u] << '\n';
        del(0, 0, n - 1, u);
        while (1) {
            auto p = lower_bound(b, b + n, b[u] + d) - b;
            //cout << curr << ' ' << u << ' ' << p - b << '\n';
            if (p == n) break;
            p = get(0, 0, n - 1, p, n - 1);
            if (p == -1) break;
            ans[per[p]] = curr;
            //cout << p - b << ' ' << per[p - b] << '\n';
            del(0, 0, n - 1, p);
            u = p;
        }
    }

    cout << curr << '\n';
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}