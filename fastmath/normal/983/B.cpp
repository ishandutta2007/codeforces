#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5007;

int a[MAXN];
int dp[MAXN][MAXN];
int best[MAXN][MAXN];
int tree[MAXN * 4];

void build(int v, int tl, int tr, int r) {
    if (tl == tr) {
        tree[v] = best[r][tl];
        return;
    }

    int tm = (tl + tr) / 2;
    build(v * 2 + 1, tl, tm, r);
    build(v * 2 + 2, tm + 1, tr, r);
    tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}

int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return -1;
    if (l <= tl && tr <= r) return tree[v];
    int tm = (tl + tr) / 2;
    return max(get(v * 2 + 1, tl, tm, l, r), get(v * 2 + 2, tm + 1, tr, l, r));
}

struct Quer {
    int l, r, num;
};

bool comp(Quer a, Quer b) {
    return a.r < b.r;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) dp[i][i] = a[i];

    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            dp[l][r] = dp[l][r - 1] ^ dp[l + 1][r];
        }
    }

    for (int i = 0; i < MAXN; ++i) for (int j = 0; j < MAXN; ++j) best[i][j] = -1;

    best[0][0] = a[0];
    for (int r = 1; r < n; ++r) {
        for (int i = 0; i <= r; ++i) {
            best[r][i] = max(best[r - 1][i], dp[i][r]);
        }
    }

    int q;
    cin >> q;
    vector <int> ans(q);
    vector <Quer> b(q);
    for (int i = 0; i < q; ++i) {
        cin >> b[i].l >> b[i].r;
        --b[i].l;
        --b[i].r;
        b[i].num = i;
    }
    
    sort(b.begin(), b.end(), comp);

    int cr = -1;
    for (int i = 0; i < q; ++i) {
        if (cr < b[i].r) {
            cr = b[i].r;
            build(0, 0, n - 1, cr);
        }

        ans[b[i].num] = get(0, 0, n - 1, b[i].l, b[i].r);
    }

    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';

    return 0;
}