#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000010;
int n, popcnt[maxn], lb[maxn], rb[maxn];
int tp1, st1[maxn], tp2, st2[maxn];
int s1[maxn << 2], s2[maxn << 2], tag1[maxn << 2], tag2[maxn << 2], sum[maxn << 2];
bool mark[maxn];
ll ans, a[maxn];
array<int, 4> M[maxn * 4];

char _buf[100000], *_op(_buf), *_ed(_buf);
#define gc (_op == _ed && (_ed = (_op = _buf) + fread(_buf, 1, 100000, stdin), _op == _ed) ? EOF : *_op++)

ll read() {
    ll x = 0; char ch = gc;
    while (ch < '0' || ch > '9') ch = gc;
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = gc;
    return x;
}

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void apply(int k, int l, int r, int v1, int v2) {
    sum[k] += v1 * s2[k] + v2 * s1[k] + v1 * v2 * (r - l + 1);
    s1[k] += v1 * (r - l + 1), tag1[k] += v1;
    s2[k] += v2 * (r - l + 1), tag2[k] += v2;
}

void pushdown(int k, int l, int r) {
    apply(ls, l, mid, tag1[k], tag2[k]);
    apply(rs, mid + 1, r, tag1[k], tag2[k]), tag1[k] = tag2[k] = 0;
}

void add(int k, int l, int r, int ql, int qr, int v1, int v2) {
    if (l >= ql && r <= qr) { apply(k, l, r, v1, v2); return; }
    if (tag1[k] || tag2[k]) pushdown(k, l, r);
    if (mid >= ql) add(ls, l, mid, ql, qr, v1, v2);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v1, v2);
    s1[k] = s1[ls] + s1[rs], s2[k] = s2[ls] + s2[rs], sum[k] = sum[ls] + sum[rs];
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        popcnt[i] = __builtin_popcountll(a[i]);
    }
    st1[tp1 = 1] = st2[tp2 = 1] = 0;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        lb[i] = tot + 1;
        while (tp1 > 1 && a[st1[tp1]] > a[i]) {
            M[++tot] = {st1[tp1 - 1] + 1, st1[tp1], -1, 0}, tp1--;
        }
        while (tp2 > 1 && a[st2[tp2]] < a[i]) {
            M[++tot] = {st2[tp2 - 1] + 1, st2[tp2], 0, -1}, tp2--;
        }
        M[++tot] = {st1[tp1] + 1, i, 1, 0};
        M[++tot] = {st2[tp2] + 1, i, 0, 1}, rb[i] = tot;
        st1[++tp1] = st2[++tp2] = i, ans += sum[1];
    }
    lb[n + 1] = tot + 1;
    while (tp1 > 1) {
        M[++tot] = {st1[tp1 - 1] + 1, st1[tp1], -1, 0}, tp1--;
    }
    while (tp2 > 1) {
        M[++tot] = {st2[tp2 - 1] + 1, st2[tp2], 0, -1}, tp2--;
    }
    rb[n + 1] = tot;
    for (int k = 0; k <= 60; k++) {
        for (int i = 1; i <= n; i++) {
            mark[i] = k == popcnt[i];
        }
        for (int i = 1; i <= n + 1; i++) {
            for (int j = lb[i]; j <= rb[i]; j++) {
                auto &p = M[j];
                if (mark[p[1]]) add(1, 1, n, p[0], p[1], p[2], p[3]);
            }
            ans += sum[1];
        }
    }
    printf("%lld\n", ans);
    return 0;
}