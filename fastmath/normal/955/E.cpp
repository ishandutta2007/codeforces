#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
#define int long long

const int INF = 1e9 + 7;
const int MAXN = 2e5 + 7;

int a[MAXN], l[MAXN], r[MAXN];

int tree1[MAXN * 4], tree2[MAXN * 4];

void build1(int v, int tl, int tr) {
    if (tl == tr) {
        if (l[tl] <= r[tl]) tree1[v] = r[tl];
        else tree1[v] = -INF;
        return;
    }          

    int tm = (tl + tr) / 2;
    build1(v * 2 + 1, tl, tm);
    build1(v * 2 + 2, tm + 1, tr);
    tree1[v] = max(tree1[v * 2 + 1], tree1[v * 2 + 2]);
}

void build2(int v, int tl, int tr) {
    if (tl == tr) {
        if (l[tl] <= r[tl]) tree2[v] = l[tl];
        else tree2[v] = INF;
        return;
    }

    int tm = (tl + tr) / 2;
    build2(v * 2 + 1, tl, tm);
    build2(v * 2 + 2, tm + 1, tr);
    tree2[v] = min(tree2[v * 2 + 1], tree2[v * 2 + 2]);
}

int get1(int v, int tl, int tr, int l, int r, int x) {
    if (tree1[v] < x) return -1;
    if (tr < l || r < tl) return -1;

    if (tl == tr) return tl;
     
    int tm = (tl + tr) / 2;
    int lres = get1(v * 2 + 1, tl, tm, l, r, x);
    if (lres != -1) return lres;
    else return get1(v * 2 + 2, tm + 1, tr, l, r, x);
}

int get2(int v, int tl, int tr, int l, int r, int x) {
    if (x < tree2[v]) return -1;
    if (tr < l || r < tl) return -1;

    if (tl == tr) return tl;

    int tm = (tl + tr) / 2;
    int lres = get2(v * 2 + 1, tl, tm, l, r, x);
    if (lres != -1) return lres;
    else return get2(v * 2 + 2, tm + 1, tr, l, r, x); 
}

int tree3[MAXN * 4], tree4[MAXN * 4];

void build3(int v, int tl, int tr) {
    if (tl == tr) {
        tree3[v] = a[tl] - tl;
        return;
    }

    int tm = (tl + tr) / 2;
    build3(v * 2 + 1, tl, tm);
    build3(v * 2 + 2, tm + 1, tr);
    tree3[v] = min(tree3[v * 2 + 1], tree3[v * 2 + 2]);
}

void build4(int v, int tl, int tr) {
    if (tl == tr) {
        tree4[v] = a[tl] + tl;
        return;
    }

    int tm = (tl + tr) / 2;
    build4(v * 2 + 1, tl, tm);
    build4(v * 2 + 2, tm + 1, tr);
    tree4[v] = min(tree4[v * 2 + 1], tree4[v * 2 + 2]);
}

int get3(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return INF;
    if (l <= tl && tr <= r) return tree3[v];
    int tm = (tl + tr) / 2;
    return min(get3(v * 2 + 1, tl, tm, l, r), get3(v * 2 + 2, tm + 1, tr, l, r));
}

int get4(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return INF;
    if (l <= tl && tr <= r) return tree4[v];
    int tm = (tl + tr) / 2;
    return min(get4(v * 2 + 1, tl, tm, l, r), get4(v * 2 + 2, tm + 1, tr, l, r));
}

signed main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        l[i] = a[i];
        r[i] = 2 * i - a[i];
    }

    bool lose = true;
    for (int i = 0; i < n; ++i) {
        lose &= (r[i] < l[i]);
    }
    
    if (lose) {
        cout << "-1\n";
        return 0;
    }

    build1(0, 0, n - 1);
    build2(0, 0, n - 1);
    build3(0, 0, n - 1);
    build4(0, 0, n - 1);

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        int j = -1;
        j = get1(0, 0, n - 1, 0, i, i);
        if (j == -1) j = get2(0, 0, n - 1, i, n - 1, i);
        if (j == -1) continue;
        if (j == 0) return 1;
    
        int x = get3(0, 0, n - 1, 0, min(i, j - 1)) + i;
        int y = INF;
        if (i < j) y = get4(0, 0, n - 1, i, j - 1) - i;
        
        int t = abs(i - j) + a[j];
        if (j < i) t = min(t, get3(0, 0, n - 1, j + 1, i) + i);
        t = min(t, get4(0, 0, n - 1, max(j + 1, i), n - 1) - i);
        
        ans = min(ans, max(min(x, y), t));
    }

    cout << ans << '\n';
    return 0;
}