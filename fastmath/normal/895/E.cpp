#include <bits/stdc++.h>

using namespace std;
#define int long long

typedef long double ld;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;

ld tree[MAXN * 4], a[MAXN], add[MAXN * 4], fact[MAXN * 4];

void build(int v, int tl, int tr){
    add[v] = 0;
    fact[v] = 1;

    if (tl == tr) {
        tree[v] = a[tl];
        return;
    }

    int m = (tl + tr) / 2;
    build(v * 2 + 1, tl, m);
    build(v * 2 + 2, m + 1, tr);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

void push(int v, int tl, int tr, int m){
    fact[v * 2 + 1] *= fact[v];
    add[v * 2 + 1] *= fact[v];
    tree[v * 2 + 1] *= fact[v];

    fact[v * 2 + 2] *= fact[v];
    add[v * 2 + 2] *= fact[v];
    tree[v * 2 + 2] *= fact[v];

    add[v * 2 + 1] += add[v];
    tree[v * 2 + 1] += add[v] * (m - tl + 1);

    add[v * 2 + 2] += add[v];
    tree[v * 2 + 2] += add[v] * (tr - m);

    add[v] = 0;
    fact[v] = 1;
}

void upd1(int v, int tl, int tr, int l, int r, ld val){
    if (tl > r || l > tr) return;
    if (tl >= l && tr <= r){
        add[v] += val;
        tree[v] += val * (tr - tl + 1);
        return;
    }
    int m = (tl + tr) / 2;
    push(v, tl, tr, m);
    upd1(v * 2 + 1, tl, m, l, r, val);
    upd1(v * 2 + 2, m + 1, tr, l, r, val);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

void upd2(int v, int tl, int tr, int l, int r, ld val){
    if (tl > r || l > tr) return;
    if (tl >= l && tr <= r){
        add[v] *= val;
        fact[v] *= val;
        tree[v] *= val;
        return;
    }
    int m = (tl + tr) / 2;
    push(v, tl, tr, m);
    upd2(v * 2 + 1, tl, m, l, r, val);
    upd2(v * 2 + 2, m + 1, tr, l, r, val);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

ld get(int v, int tl, int tr, int l, int r){
    if (tl > r || l > tr) return 0;
    if (tl >= l && tr <= r) return tree[v];
    int m = (tl + tr) / 2;
    push(v, tl, tr, m);
    return get(v * 2 + 1, tl, m, l, r) + get(v * 2 + 2, m + 1, tr, l, r);
}

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(10);
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) cin >> a[i];
    build(0, 0, n - 1);

    for (int i = 0; i < q; ++i){
        int t;
        cin >> t;
        if (t == 1){
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;

            --l1;
            --l2;
            --r1;
            --r2;

            ld len1 = r1 - l1 + 1;
            ld len2 = r2 - l2 + 1;

            ld sr1 = get(0, 0, n - 1, l1, r1) / len1;
            ld sr2 = get(0, 0, n - 1, l2, r2) / len2;

            upd2(0, 0, n - 1, l1, r1, (len1 - 1) / len1);
            upd2(0, 0, n - 1, l2, r2, (len2 - 1) / len2);

            upd1(0, 0, n - 1, l1, r1, sr2 / len1);
            upd1(0, 0, n - 1, l2, r2, sr1 / len2);

        }
        else{
            int l, r;
            cin >> l >> r;
            cout << get(0, 0, n - 1, l - 1, r - 1) << '\n';
        }
    }

    return 0;
}