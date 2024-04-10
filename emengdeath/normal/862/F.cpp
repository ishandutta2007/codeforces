#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
const int S = 80;
const int N = 1e5 + 10;
struct node{
    int lv, rv, mx, sum;
}f[N * 4], d;
struct ques{
    int x, y, z;
    string s;
    int id;
    int v[2];
    int len;
}q[N];
int g[N * 4];
int n, m;
int v[N];
int gd;
long long ans[N];
int len[N], vv[N], lenn[N];
string s[N];
int w[N], L[N], R[N], dw[N];
int getlcs(int i) {
    int x = 0;
    while (x < len[i] && x < len[i + 1] && s[i][x] == s[i + 1][x]) x ++;
    return x;
}
int I;
void combine(node&a, node b, node c) {
    a.sum = b.sum + c.sum;
    if (b.lv == b.sum)
        a.lv = b.lv + c.lv;
    else
        a.lv = b.lv;
    if (c.rv == c.sum)
        a.rv = c.rv + b.rv;
    else
        a.rv = c.rv;
    a.mx = max(b.mx, max(c.mx, b.rv + c.lv));
}
void build(int l, int r , int s) {
    if (l == r) {
        f[s].lv = f[s].rv = f[s].mx = (v[l] > I), f[s].sum = 1;
        g[s] = len[l];
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s + 1);
    combine(f[s], f[s + s], f[s+s+1]);
    g[s] = max(g[s + s], g[s+s+1]);
}
void change(int l, int r, int s, int ll, int rr) {
    if (r < ll || rr < l) return;
    if (l == r) {
        g[s] = len[l];
        f[s].lv = f[s].rv = f[s].mx = (v[l] > I), f[s].sum = 1;
        return;
    }
    change(l, (l + r) / 2, s + s, ll, rr);
    change((l + r) / 2 + 1, r, s + s + 1, ll, rr);
    combine(f[s], f[s + s], f[s+s+1]);
    g[s] = max(g[s + s], g[s+s+1]);
}
void get(int l, int r, int s, int ll, int rr) {
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        if (l == ll) {
            d = f[s];
        } else {
            combine(d, d, f[s]);
        }
        gd = max(gd, g[s]);
        return;
    }
    get(l, (l + r) / 2, s +  s, ll, rr);
    get((l + r) / 2 + 1, r, s + s + 1, ll, rr);
}
void buildw() {
    dw[0] = 0;
    for (int i = 1; i <= w[0]; i ++)
    {
        if (i > 1 && w[i] != w[i - 1] + 1) dw[0] =0, L[i] = w[i];
        else {
            L[i] = w[i];
            while (dw[0] && v[w[dw[dw[0]]]] >= v[w[i]]) {
                L[i] = L[dw[dw[0]]];
                dw[0] --;
            }
        }
        dw[++dw[0]] = i;
    }
    dw[0] = 0;
    for (int i = w[0]; i >= 1; i --) {
        if (i < w[0] && w[i] != w[i + 1] - 1) dw[0] = 0, R[i] = w[i];
        else {
            R[i] = w[i];
            while (dw[0] && v[w[dw[dw[0]]]] >= v[w[i]]) {
                R[i] = R[dw[dw[0]]];
                dw[0] --;
            }
        }
        dw[++dw[0]] = i;
    }
}
void add(int x) {
    for (int i = 1; i <= w[0]; i ++)
        if (w[i] > x) {
            for (int j = w[0]; j >= i; j --)
                w[j + 1] = w[j];
            w[i] = x;
            w[0] ++;
            break;
        }
    if (w[w[0]] < x) w[++w[0]] = x;
}
void del(int x) {
    for (int i = 1; i <= w[0]; i ++)
        if (w[i] == x) {
            for (int j = i; j < w[0]; j ++)
                w[j] = w[j + 1];
            w[0] --;
            break;
        }
}
int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i], lenn[i] = len[i] = s[i].length();
    }
    for (int i = 1; i < n; i++) {
        v[i] = getlcs(i);
        if (v[i] > S)w[++w[0]] = i;
        vv[i] = v[i];
    }
    int tot = 0;
    buildw();
    for (int i = 1; i <= m; i ++) {
        cin>>q[i].x >> q[i].y;
        if (q[i].x == 1)
            cin>>q[i].z, q[i].id = ++tot;
        else
            cin>>q[i].s;
    }
    for (I = 0; I < S; I ++) {
        for (int i = 1; i <= n; i ++)
            v[i] = vv[i], len[i] = lenn[i];
        build(1, n, 1);
        for (int j = 1; j <= m; j ++){
            int x = q[j].x, y = q[j].y;
            if (x == 1) {
                int z = q[j].z;
                if (y == z) {
                    ans[q[j].id] = max(ans[q[j].id], 1ll * len[y]);
                    //printf("%d\n", len[y]);
                    continue;
                }
                gd = len[z];
                get(1, n, 1, y, z - 1);
                if (!I) {
                    ans[q[j].id] = max(ans[q[j].id], 1ll * gd);
                    buildw();
                    for (int i = 1; i <= w[0]; i ++)
                        ans[q[j].id] = max(ans[q[j].id], 1ll * (min(z - 1, R[i]) - max(y,  L[i]) + 2) * v[w[i]]);
                }
                if (d.mx)
                ans[q[j].id] = max(ans[q[j].id], 1ll * (I + 1) * (d.mx + 1));
            } else {
                if (!I) {
                    if (y != n && v[y] > S)
                        del(y);
                    if (y != 1 && v[y - 1] > S)
                        del(y - 1);
                }
                if (!I) {
                    s[y] = q[j].s;
                    len[y] = s[y].length();
                    q[j].len = len[y];
                } else
                    len[y] = q[j].len;
                if (y != 1) {
                    if (!I) {
                        q[j].v[0] = v[y - 1] = getlcs(y - 1);
                    } else
                        v[y - 1] = q[j].v[0];
                    if (!I&&v[y - 1] > S)
                        add(y - 1);
                }
                if (y != n) {
                    if (!I) {
                        q[j].v[1] = v[y] = getlcs(y);
                    } else
                        v[y] = q[j].v[1];
                    if (!I&&v[y] > S)
                        add(y);
                }
                if (!I)
                    buildw();
                change(1, n, 1, y - 1, y);
            }
        }
    }
    for (int i = 1; i <= tot; i ++)
        printf("%lld\n", ans[i]);
    return 0;
}