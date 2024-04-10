
#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int maxn = 2e5 + 5;
const int mod = 998244353;

int add(int x,int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

int mul(int a,int b) {
    LL r = 1LL * a * b;
    return r - r / mod * mod;
}

int powt(int a,int b) {
    int r = 1;
    while(b) {
        if(b & 1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

int s[maxn];
int t[maxn];
int f[maxn], p[maxn], inv[maxn];
int g[maxn << 2];

void build(int t, int l, int r)
{
    if (l == r) {
        g[t] = f[l];
        return;
    }
    int mid = (l + r) >> 1;
    build (t << 1, l, mid);
    build(t << 1 | 1, mid + 1, r);
    g[t] = add(g[t << 1], g[t << 1 | 1]);
}

void update(int t, int l, int r, int v)
{
    if (l == r) {
        g[t] = f[l];
        return;
    }
    int mid = (l + r) >> 1;
    if (v <= mid) update (t << 1, l, mid, v);
    else update(t << 1 | 1, mid + 1, r, v);
    g[t] = add(g[t << 1], g[t << 1 | 1]);
}

int query(int t, int l, int r, int v)
{
    if (r <= v) {
        return g[t];
    }
    int mid = (l + r) >> 1;
    if (v <= mid) return query(t << 1, l, mid, v);
    else return add(query(t << 1, l, mid, v), query(t << 1 | 1, mid + 1, r, v));
}

int main() {
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < m; i++) cin >> t[i];

    p[0] = p[1] = 1;
    for (int i = 2; i < maxn; i++) p[i] = mul(p[i - 1], i);
    inv[maxn - 1] = powt(p[maxn - 1], mod - 2);
    for (int i = maxn - 1; i > 0; i--) inv[i - 1] = mul(inv[i], i);


    for (int i = 0; i < n; i++) f[s[i]]++;
    int val = 1, ans = 0;
    for (int i = 1; i <= 200000; i++) {
        val = mul(val, inv[f[i]]);
    }

    build(1, 1, 200000);
    for (int i = 0; i < m; i++) {
        if (i == n) {
            ans = add(ans, 1);
            break;
        }

        int x = 0;
        if (t[i] > 1) x = query(1, 1, 200000, t[i] - 1);
        ans = add(ans, mul(mul(val, x), p[n - i - 1]));

        //cout <<i <<""<<x<<" "<<ans<<endl;

        if (f[t[i]] > 0) {
            val = mul(val, f[t[i]]);
            f[t[i]]--;
            update(1, 1, 200000, t[i]);
        } else break;
    }

    cout << ans << endl;

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}