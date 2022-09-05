#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, q, L, a[maxn], tmp[5], ans[5], cand[maxn << 2][5], mark[maxn];
vector<int> V[maxn];

int get(int x, int l, int r) {
    return upper_bound(V[x].begin(), V[x].end(), r) - lower_bound(V[x].begin(), V[x].end(), l);
}

int calc(int l, int r, int k = 5) {
    return (r - l + 1) / k;
}

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void build(int k, int l, int r) {
    if (l == r) { cand[k][0] = a[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    int tot = 0;
    for (int i : cand[ls]) {
        if (!mark[i] && get(i, l, r) > calc(l, r)) {
            cand[k][tot++] = i, mark[i] = 1;
        }
    }
    for (int i : cand[rs]) {
        if (!mark[i] && get(i, l, r) > calc(l, r)) {
            cand[k][tot++] = i, mark[i] = 1;
        }
    }
    for (int i : cand[k]) mark[i] = 0;
}

void query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) {
        int tot = 0;
        for (int i : ans) {
            if (!mark[i] && get(i, L, r) > calc(L, r)) {
                tmp[tot++] = i, mark[i] = 1;
            }
        }
        for (int i : cand[k]) {
            if (!mark[i] && get(i, L, r) > calc(L, r)) {
                tmp[tot++] = i, mark[i] = 1;
            }
        }
        memset(ans, 0, sizeof(ans));
        copy(tmp, tmp + tot, ans);
        for (int i : ans) mark[i] = 0;
        return;
    }
    if (mid >= ql) query(ls, l, mid, ql, qr);
    if (mid < qr) query(rs, mid + 1, r, ql, qr);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), V[a[i]].push_back(i);
    }
    build(1, 1, n);
    while (q--) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        memset(ans, 0, sizeof(ans));
        L = l, query(1, 1, n, l, r);
        int mn = INT_MAX;
        for (int i : ans) {
            if (get(i, l, r) > calc(l, r, k)) mn = min(mn, i);
        }
        printf("%d\n", mn == INT_MAX ? -1 : mn);
    }
    return 0;
}