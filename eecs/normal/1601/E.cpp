#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 300010;
int n, q, K, a[maxn], b[maxn], st[20][maxn], lg[maxn];
ll ans[maxn], sum[maxn << 2], tag[maxn << 2];
vector<array<int, 3>> Q[maxn];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void apply(int k, int l, int r, ll v) {
    sum[k] += (r - l + 1) * v, tag[k] += v;
}

void pushdown(int k, int l, int r) {
    apply(ls, l, mid, tag[k]), apply(rs, mid + 1, r, tag[k]), tag[k] = 0;
}

void add(int k, int l, int r, int ql, int qr, ll v) {
    if (l >= ql && r <= qr) { apply(k, l, r, v); return; }
    if (tag[k]) pushdown(k, l, r);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    sum[k] = sum[ls] + sum[rs];
}

ll query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return sum[k];
    if (tag[k]) pushdown(k, l, r);
    ll s = 0;
    if (mid >= ql) s = query(ls, l, mid, ql, qr);
    if (mid < qr) s += query(rs, mid + 1, r, ql, qr);
    return s;
}

int main() {
    scanf("%d %d %d", &n, &q, &K);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]), st[0][i] = a[i];
    }
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int k = 1; 1 << k <= n; k++) {
        for (int i = 0; i + (1 << k) <= n; i++) {
            st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }
    auto qmin = [&](int l, int r) {
        int k = lg[r - l + 1];
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    };
    for (int i = 0, l, r; i < q; i++) {
        scanf("%d %d", &l, &r), l--, r--;
        r = l + (r - l) / K * K;
        Q[l % K].push_back({l, r, i});
    }
    for (int i = 0; i < K; i++) {
        vector<int> st = {((n - 1) / K + 1) * K};
        sort(Q[i].begin(), Q[i].end(), greater<array<int, 3>>());
        for (int j = (n - 1) / K * K + i, k = 0; j >= 0; j -= K) {
            if (j >= n) continue;
            while (st.size() > 1 && b[st.back()] > a[j]) {
                add(1, 0, (n - 1) / K, st.back() / K, st[st.size() - 2] / K - 1, -b[st.back()]);
                st.pop_back();
            }
            add(1, 0, (n - 1) / K, j / K, st.back() / K - 1, a[j]);
            for (; k < Q[i].size() && Q[i][k][0] == j; k++) {
                ans[Q[i][k][2]] = query(1, 0, (n - 1) / K, j / K, Q[i][k][1] / K);
            }
            add(1, 0, (n - 1) / K, j / K, st.back() / K - 1, -a[j]);
            if (!j) continue;
            b[j] = qmin(j - K + 1, j);
            while (st.size() > 1 && b[st.back()] > b[j]) {
                add(1, 0, (n - 1) / K, st.back() / K, st[st.size() - 2] / K - 1, -b[st.back()]);
                st.pop_back();
            }
            add(1, 0, (n - 1) / K, j / K, st.back() / K - 1, b[j]), st.push_back(j);
        }
        for (int i = 1; i < st.size(); i++) {
            add(1, 0, (n - 1) / K, st[i] / K, st[i - 1] / K - 1, -b[st[i]]);
        }
    }
    for (int i = 0; i < q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}