#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;
const int INF = 1e18 + 7;

int d, n, m;

struct Kek {
    int pos, cost;
};

Kek a[MAXN];

void read() {
    cin >> d >> n >> m;
    ++m;
    for (int i = 1; i < m; ++i) cin >> a[i].pos >> a[i].cost;
    a[m].pos = d; a[m].cost = INF;
    ++m;
    a[0].pos = a[0].cost = 0;
}

pair <int, int> tree[MAXN<<2];

void build(int v, int tl, int tr) {
    if (tl == tr) { tree[v] = {a[tl].cost, tl}; return; }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm); build(v * 2 + 2, tm + 1, tr);
    tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}

pair <int, int> get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return {INF, INF};
    if (l <= tl && tr <= r) return tree[v];
    int tm = (tl + tr) >> 1;
    return min(get(v * 2 + 1, tl, tm, l, r), get(v * 2 + 2, tm + 1, tr, l, r));
}   

int get(int l, int r, int have, int want) {
    if (l == r) {
        return (want - have) * a[l].cost;
    }

    auto tmp = get(0, 0, m - 1, l, r); int p = tmp.second;
    
    if (want + (a[r].pos - a[l].pos) <= have) {
        return 0;
    }   
    else if (a[p].pos - a[l].pos <= have) {
        int ost = have - (a[p].pos - a[l].pos);
        int w = min(n, want + (a[r].pos - a[p].pos));
        return (w - ost) * a[p].cost + get(p + 1, r, w - (a[p + 1].pos - a[p].pos), want);
    }   
    else {
        int w = min(n, want + (a[r].pos - a[p].pos));
        return get(l, p - 1, have, a[p].pos - a[p - 1].pos) + w * a[p].cost + get(p + 1, r, w - (a[p + 1].pos - a[p].pos), want);        
    }
}   

bool comp(Kek a, Kek b) {
    return a.pos < b.pos;
}

int ans = -1;
void solve() {
    sort(a, a + m, comp);
    for (int i = 0; i < m - 1; ++i) {
        if (n < a[i + 1].pos - a[i].pos) {
            cout << "-1\n";
            exit(0);
        }
    }
    build(0, 0, m - 1);
    ans = get(0, m - 1, 0, 0);
}

void print() {
    cout << ans << '\n';
}   

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}