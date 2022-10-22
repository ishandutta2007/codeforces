#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int maxn = 2e5 + 5;
const int mod = 998244353;

int add(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

int mul(int a, int b) {
    LL r = 1LL * a * b;
    return r - r / mod * mod;
}

int powt(int a, int b) {
    int r = 1;
    while(b) {
        if(b & 1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

int a[maxn], nxt[maxn], pre[maxn];
int l[maxn], r[maxn];
int fa[maxn];

void solve()
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i <= n + 1; i++) l[i] = i;
    for (int i = 0; i <= n + 1; i++) r[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        l[y] = min(l[y], x);
        r[x] = max(r[x], y);
    }

    for (int i = n; i > 0; i--) l[i] = min(l[i], l[i + 1]);
    for (int i = 1; i <= n; i++) r[i] = max(r[i], r[i - 1]);

    map<int, int> q;
    for (int i = 1; i <= n; i++) {
        if (q.find(a[i]) != q.end()) {
            pre[i] = q[a[i]];
            nxt[pre[i]] = i;
        } else  pre[i] = -5;
        q[a[i]] = i;
    }
    for (auto e:q) nxt[e.se] = n + 5;

    for (int i = 1; i <= n; i++) fa[i] = 0;
    for (int i = n; i > 0; i--) {
        if (nxt[i] <= r[i]) {
            fa[i] = nxt[i];
            if (fa[fa[i]]) fa[i] = fa[fa[i]];
        }
    }

    y = 0;
    for (int i = n; i > y; i--) {
        if (pre[i] >= l[i]) y = max(y, pre[i]);
    }

    int ans = y;
    for (int i = 1; i <= n; i++) {
        if (fa[i]) {
            if (fa[i] > r[i]) y = max(y, pre[fa[i]]);
            else y = max(y, fa[i]);
        }
        if (pre[i] >= l[i]) break;
        ans = min(ans, max(0, y - i));
    }

    cout << ans << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    cin >> pT;
    while (pT--)
    {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}