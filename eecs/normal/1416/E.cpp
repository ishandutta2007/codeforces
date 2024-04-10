#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000010, INF = 0x3f3f3f3f;
int T, n, a[maxn], f[maxn];
ll k[maxn], b[maxn], L[maxn], R[maxn];
vector<ll> V;

void chk(int &x, int y) {
    if (x > y) x = y;
}

namespace SEG {
#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
struct node { int v, cov, tag; } t[maxn << 3];

void build(int k, int l, int r) {
    t[k].v = t[k].cov = t[k].tag = INF;
    if (l < r) build(ls, l, mid), build(rs, mid + 1, r);
}

void push1(int k, int v) { t[k].v = t[k].cov = v, t[k].tag = INF; }
void push2(int k, int v) { chk(t[k].v, v), t[k].cov ^ INF ? chk(t[k].cov, v) : chk(t[k].tag, v); }

void pushdown(int k) {
    if (t[k].cov ^ INF) push1(ls, t[k].cov), push1(rs, t[k].cov), t[k].cov = INF;
    else if (t[k].tag ^ INF) push2(ls, t[k].tag), push2(rs, t[k].tag), t[k].tag = INF;
}

void del(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) { push1(k, INF - 1); return; }
    pushdown(k);
    if (mid >= ql) del(ls, l, mid, ql, qr);
    if (mid < qr) del(rs, mid + 1, r, ql, qr);
    t[k].v = min(t[ls].v, t[rs].v);
}

void upd(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { push2(k, v); return; }
    pushdown(k);
    if (mid >= ql) upd(ls, l, mid, ql, qr, v);
    if (mid < qr) upd(rs, mid + 1, r, ql, qr, v);
    t[k].v = min(t[ls].v, t[rs].v);
}

void dec(int k, int l, int r, int p) {
    if (l == r) { t[k].v--; return; }
    pushdown(k);
    mid >= p ? dec(ls, l, mid, p) : dec(rs, mid + 1, r, p);
    t[k].v = min(t[ls].v, t[rs].v);
}
}  // namespace SEG

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), a[i] -= 2;
        }
        V.clear();
        for (int i = 1, l = 1, r = 2; i <= n; i++, l += 2, r += 2) {
            if (i == 1) k[l] = 1;
            else k[l] = k[l - 1], b[l] = b[l - 1];
            k[r] = -k[l], b[r] = a[i] - b[l];
            if (k[l] > 0) L[i] = -b[l], R[i] = b[r];
            else L[i] = -b[r], R[i] = b[l];
            V.push_back(L[i]), V.push_back(R[i] + 1);
            if (!(a[i] & 1)) {
                ll m = (L[i] + R[i]) >> 1;
                V.push_back(m), V.push_back(m + 1);
            }
        }
        sort(V.begin(), V.end());
        V.resize(unique(V.begin(), V.end()) - V.begin());
        SEG::build(1, 0, V.size() - 1);
        for (int i = 1; i <= n; i++) {
            int l = lower_bound(V.begin(), V.end(), L[i]) - V.begin();
            int r = upper_bound(V.begin(), V.end(), R[i]) - V.begin();
            if (l) SEG::del(1, 0, V.size() - 1, 0, l - 1);
            SEG::del(1, 0, V.size() - 1, r, V.size() - 1);
            SEG::upd(1, 0, V.size() - 1, l, r - 1, f[i - 1] - (i - 1));
            if (!(a[i] & 1)) SEG::dec(1, 0, V.size() - 1, lower_bound(V.begin(),
                V.end(), (L[i] + R[i]) >> 1) - V.begin());
            f[i] = i + 1 + SEG::t[1].v;
        }
        printf("%d\n", f[n]);
    }
    return 0;
}