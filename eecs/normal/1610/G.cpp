#include <bits/stdc++.h>
using namespace std;

const int maxn = 600010, P = 1000000007;
int n, pre[maxn], nxt[maxn], lst[maxn], len[maxn];
int tot, rt[maxn], pw[maxn];
string s;
struct node { int l, r, s; } t[maxn * 10];

void red(int &x) {
    x += x >> 31 & P;
}

#define mid ((l + r) >> 1)
void modify(int &k1, int k2, int l, int r, int p, int v) {
    t[k1 = ++tot] = t[k2], red(t[k1].s += v - P);
    if (l == r) return;
    if (mid >= p) modify(t[k1].l, t[k2].l, l, mid, p, v);
    else modify(t[k1].r, t[k2].r, mid + 1, r, p, v);
}

int query(int k, int l, int r, int ql, int qr) {
    if (!k || l >= ql && r <= qr) return t[k].s;
    int s = 0;
    if (mid >= ql) s = query(t[k].l, l, mid, ql, qr);
    if (mid < qr) red(s += query(t[k].r, mid + 1, r, ql, qr) - P);
    return s;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s, n = s.size();
    for (int i = 0; i < n; i++) {
        pre[i] = (i ? pre[i - 1] : n) + (s[i] == '(' ? 1 : -1);
    }
    memset(lst, -1, sizeof(lst));
    for (int i = n - 1; ~i; i--) {
        nxt[i] = lst[i ? pre[i - 1] : n], lst[pre[i]] = i;
    }
    for (int i = pw[0] = 1; i <= n; i++) {
        pw[i] = 10007LL * pw[i - 1] % P;
    }
    vector<int> st = {n - 1};
    for (int i = n - 1; ~i; i--) {
        int val = i ? pre[i - 1] : n;
        while (!st.empty() && pre[st.back()] >= val) st.pop_back();
        len[i] = len[i + 1] + 1;
        modify(rt[i], rt[i + 1], 0, n, n - len[i], 1LL * (s[i] == ')') * pw[n - len[i]] % P);
        if (~nxt[i] && (st.empty() || st.back() > nxt[i])) {
            int j = nxt[i] + 1;
            int l = 1, r = min(len[i], len[j]) - 1, p = 0;
            while (l <= r) {
                int x = query(rt[i], 0, n, 0, n - len[i] + mid - 1);
                int y = query(rt[j], 0, n, 0, n - len[j] + mid - 1);
                if (len[i] >= len[j] && y == 1LL * x * pw[len[i] - len[j]] % P ||
                    len[i] < len[j] && x == 1LL * y * pw[len[j] - len[i]] % P) l = (p = mid) + 1;
                else r = mid - 1;
            }
            int x = query(rt[i], 0, n, n - len[i] + p, n - len[i] + p) > 0;
            int y = query(rt[j], 0, n, n - len[j] + p, n - len[j] + p) > 0;
            if (x > y || x == y && len[i] > len[j]) rt[i] = rt[j], len[i] = len[j];
        }
        if (i) st.push_back(i - 1);
    }
    for (int i = n - len[0]; i < n; i++) {
        cout << (query(rt[0], 0, n, i, i) ? ')' : '(');
    }
    return 0;
}