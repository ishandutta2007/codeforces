#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int S = 447;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int add(int x, int y) {
    x+= y;
    return x >= mod ?x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y){
    return 1ll * x * y % mod;
}
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}
struct node{
    vector<vector<int> > d;
    void init(vector<int> a) {
        int mx = (a.empty()? 1: *max_element(a.begin(), a.end()));
        d = vector<vector<int> >(a.size() + 1, vector<int>(mx, 0));
        for (int i = 1; i <= a.size(); i ++) {
            d[i] = d[i - 1];
            d[i][a[i - 1] - 1] ++;
        }
    }
    int get(int l, int r) {
        int tot = d[0].size() - 1;
        while (tot >= 0 && !(d[r][tot] - d[l][tot])) tot --;
        return tot + 1;
    }
}f[86];
int n, m, cnt;
int a[N], d[N], v[N];
int g[N][86];

struct node1 {
    int son[2];
    int v;
}w[N * 100];
int tot_w;
int lst[N];
int ins(int l, int r, int  s, int ll, int v) {
    if (r < ll) return s;
    if (!s) w[s = ++tot_w].v = 1;
    if (l >= ll) {
        w[s].v = mul(w[s].v,v);
        return s;
    }
    w[s].son[0] = ins(l, (l + r) / 2, w[s].son[0], ll, v);
    w[s].son[1] = ins((l + r) / 2 + 1, r, w[s].son[1], ll, v);
    return s;
}
void ins(int l, int r, int s, int ll , int rr, int v ){
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr ) {
        ins(1, n, s, rr, v);
        return;
    }
    ins(l, (l + r) / 2, s + s, ll, rr, v);
    ins((l+ r) /2 + 1, r, s +s+1, ll, rr, v);
}
int get(int l, int r, int s, int ll) {
    int v = 1;
    while (s) {
        v = mul(v, w[s].v);
        if (l == r) return v;
        if ((l + r) / 2 >= ll) r = (l + r) / 2, s = w[s].son[0];
        else
            l = (l + r) / 2 + 1, s = w[s].son[1];
    }
    return v;
}
int get(int l, int r, int s, int ll, int rr) {
    int v = 1;
    while (1) {
        v = mul(v, get(1, n, s, rr));
        if (l == r) return v;
        if ((l + r) / 2 >= ll) r = (l + r) / 2, s += s;
        else
            l = (l+ r) / 2 + 1, s += s +1;
    }
}
int main() {
    for (int i = 2; i < N; i ++) {
        if (!a[i])
            d[a[i] = ++d[0]] = i;
        for (int j = 1; j <= a[i] && 1ll * d[j] * i < N; j ++)
            a[d[j] * i] = j;
    }
    cnt = 1;
    while (d[cnt + 1] <= S) cnt ++;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &v[i]);
    for (int i = 0; i < cnt; i ++) g[0][i] = 0;
    for (int i = 0 ; i < cnt;i  ++) {
        int x = d[i + 1];
        vector<int> a;
        for (int j = 1; j <= n;j++) {
            g[j][i] = g[j - 1][i];
            if (v[j] % x == 0) {
                int tot = 0;
                while (v[j] % x == 0) v[j] /= x, tot ++;
                a.push_back(tot);
                g[j][i] = a.size();
            }
        }
        f[i].init(a);
    }
    tot_w = n * 4;
    for (int i = 1;  i <= n * 4; i ++) w[i].v = 1;
    for (int i = 1 ; i <= n; i ++)
        if ( v[i] != 1) {
            ins(1, n, 1, lst[v[i]] + 1, i, v[i]);
            lst[v[i]] = i;
        }
    scanf("%d", &m);
    int ans = 0;
    while (m -- ) {
        int l, r;
        scanf("%d %d", &l, &r);
        l = (l + ans) % n + 1, r = (r + ans) % n + 1;
        if (l > r) swap(l, r);
        ans = 1;
        for (int i = 0; i < cnt; i ++)
        {
            ans = mul(ans, calc(d[i + 1], f[i].get(g[l - 1][i], g[r][i])));
        }
        ans = mul(ans, get(1, n, 1, l, r));
        printf("%d\n", ans);
    }
    return 0;
}