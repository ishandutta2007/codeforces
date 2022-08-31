#include <bits/stdc++.h>
using namespace std;
struct node {
    int ls, rs;
} t[400010 * 20 * 4];
int tot;
inline void add(int &x, int l, int r, int pos) {
    if(x == 0) x = ++tot;
    if(l == r) return;
    int mid = l + r >> 1;
    if(pos <= mid) add(t[x].ls, l, mid, pos);
    else add(t[x].rs, mid + 1, r, pos);
}
inline int query(int x, int l, int r, int L, int R) {
    if(l > R || L > r || x == 0) return 0;
    if(L <= l && r <= R) return 1;
    int mid = l + r >> 1;
    return query(t[x].ls, l, mid, L, R) | query(t[x].rs, mid + 1, r, L, R);
}
inline int merge(int a, int b) {
    if(!a || !b) return a | b;
    int ans = ++tot;
    t[ans].ls = merge(t[a].ls, t[b].ls);
    t[ans].rs = merge(t[a].rs, t[b].rs);
    return ans;
}
struct data {
    int son[26], parent, rt, len, pos;
    inline int& operator [] (int x) {
        return son[x];
    }
} a[400010];
int cnt = 1, last = 1;
inline int add(int c, int id) {
    int p = last, np = last = ++cnt;
    a[np].pos = id;
    a[np].len = a[p].len + 1;
    for(; p && a[p][c] == 0; p = a[p].parent) a[p][c] = np;
    if(p == 0) a[np].parent = 1;
    else {
        int q = a[p][c];
        if(a[q].len == a[p].len + 1) a[np].parent = q;
        else {
            int nq = ++cnt;
            a[nq].pos = id;
            a[nq] = a[q];
            a[nq].len = a[p].len + 1;
            a[np].parent = a[q].parent = nq;
            for(; a[p][c] == q; p = a[p].parent) a[p][c] = nq;
        }
    }
    return last;
}
int buc[800010], id[800010], dp[800010], top[800010], n;
char s[400010];
int main() {
    scanf("%d%s", &n, s + 1);
    for(int i = 1; i <= n; i++) add(a[add(s[i] - 'a', i)].rt, 1, n, i);
    for(int i = 1; i <= cnt; i++) buc[a[i].len]++;
    for(int i = 1; i <= n; i++) buc[i] += buc[i - 1];
    for(int i = 1; i <= cnt; i++) id[buc[a[i].len]--] = i;
    for(int i = cnt; i > 1; i--) a[a[id[i]].parent].rt = merge(a[a[id[i]].parent].rt, a[id[i]].rt);
    int ans = 0;
    for(int i = 2; i <= cnt; i++) {
        int now = id[i], u = top[a[now].parent];
        if(a[now].parent == 1) dp[now] = 1, top[now] = now;
        else if(query(a[u].rt, 1, n, a[now].pos - a[now].len + a[u].len, a[now].pos - 1)) top[now] = now, dp[now] = dp[a[now].parent] + 1;
        else top[now] = u, dp[now] = dp[a[now].parent];
        ans = max(ans, dp[now]);
    }
    return cout << ans << endl, 0;
}