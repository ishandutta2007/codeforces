#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
struct info {
    int mx, mpl;
    info() {mx = maxn, mpl = maxn;}
    info(int a, int b){
        mx = a, mpl = b;
    }
};
info uni(info x, info y) {
    info res;
    res.mx = max(x.mx, y.mx);
    res.mpl = 0;
    if (x.mx == res.mx) chkmax(res.mpl, x.mpl);
    if (y.mx == res.mx) chkmax(res.mpl, y.mpl);
    return res;
}
struct ST
{
    int l, r;
    ST *ch[2];
    int lz; // 
    info mx;
} p[maxn * 20], *root;
int stcnt = 0;
void bdtree(ST *a, int l, int r)
{
    a->l = l, a->r = r;
    a->lz = maxn;
    a->mx = info(maxn, r);
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    a->ch[0] = &p[stcnt++];
    a->ch[1] = &p[stcnt++];
    bdtree(a->ch[0], l, mid);
    bdtree(a->ch[1], mid + 1, r);
}
void actlz(ST *a, int lz) {
    a->lz = lz;
    a->mx = info(lz, a->r);
}
void upd(ST *a) {
    a->mx = uni(a->ch[0]->mx, a->ch[1]->mx);
}
void pushdown(ST *a) {
    if (a->lz < maxn) {
        actlz(a->ch[0], a->lz);
        actlz(a->ch[1], a->lz);
        a->lz = maxn;
    }
}
void pushlz(ST *a, int l, int r, int lz)
{
    if (l > r) return ;
    if (a->l == l && a->r == r) {
        actlz(a, lz);
        return;
    }
    pushdown(a);
    int mid = (a->l + a->r) >> 1;
    if (r <= mid)
        pushlz(a->ch[0], l, r, lz);
    else if (l > mid)
        pushlz(a->ch[1], l, r, lz);
    else
    {
        pushlz(a->ch[0], l, mid, lz);
        pushlz(a->ch[1], mid + 1, r, lz);
    }
    upd(a);
}

info qmn(ST *a, int l, int r) {
    if (a->l == l && a->r == r)
        return a->mx;
    pushdown(a);
    int mid = (a->l + a->r) >> 1;
    if (r <= mid)
        return qmn(a->ch[0], l, r);
    else if (l > mid)
        return qmn(a->ch[1], l, r);
    else
        return uni(qmn(a->ch[0], l, mid), qmn(a->ch[1], mid + 1, r));
}
#define vp vector<pi>
int n, t;
ll dp[maxn]; // min wait time
ll d[maxn];
ll to[maxn]; // from 1 to x
// 0 ~ t - 1
vp mk(ll l, ll r) {
    ll nd = (l / t) * t;
    l -= nd, r -= nd;
    if (l < 0) l += t, r += t;
    if (r < t) return {{l, r}};
    else return {{0, r - t}, {l, t - 1}};
}
int nor(ll x) {
    return (x % t + t) % t;
}
int g[maxn], c[maxn];
vp bad[maxn];
int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) 
        scanf("%d%d", &g[i], &c[i]);
    for (int i = 1; i < n; i++) {
        int h;
        scanf("%d", &h);
        to[i + 1] = to[i] + h;
    }
    for (int i = 1; i <= n; i++)
        bad[i] = mk(t - c[i] - to[i] + g[i], t - c[i] - to[i] + t - 1);
    root = &p[stcnt++];
    vi ids;
    for (int i = 1; i <= n; i++) ids.pb(nor(t - c[i] - to[i]));
    sort(ids.begin(), ids.end());
    auto gid = [&](int x) {
        return lower_bound(ids.begin(), ids.end(), x) - ids.begin();
    };
    bdtree(root, 0, n);

    for (int i = n; i >= 1; i--) {
        dp[i] = 0;
        ll s = nor(t - c[i] - to[i]);
        int nid = gid(s);
        int pl = qmn(root, nid, nid).mx;
        for (auto v : bad[i])
            pushlz(root, gid(v.fi), gid(v.se + 1) - 1, i);
        if (pl > n) dp[i] = 0;
        else {
            dp[i] = dp[pl];
            ll ned = nor(s + to[pl] + c[pl]);
            dp[i] += t - ned;
        }
    }
    ll ans = 1e18;
    stcnt = 0;
    root = &p[stcnt++];
    for (int i = 1; i <= n; i++)
        for (auto v : bad[i]) {
            ids.pb(nor(v.fi - 1));
        }
    sort(ids.begin(), ids.end());
    ids.erase(unique(ids.begin(), ids.end()), ids.end());
    bdtree(root, 0, ids.size() - 1);

    for (int i = 1; i <= n; i++) {
        ll minw = 1e18;
        ll qr = nor(t - to[i] - c[i]);
        int fid = gid(qr);
        assert(ids[fid] == qr);
        int eid = -1;
        auto fh = qmn(root, 0, fid);
        if (fh.mx == maxn) eid = fh.mpl;
        else eid = qmn(root, 0, root->r).mpl;
        assert(eid != -1);
        minw = nor(qr - ids[eid]);
        chkmin(ans, dp[i] + minw);
        for (auto v : bad[i])
            pushlz(root, gid(v.fi), gid(v.se + 1) - 1, i);
        if (root->mx.mx < maxn) break;
    }
    if (root->mx.mx == maxn)
        ans = 0;
    ans += to[n];
    cout << ans << endl;
    return 0;
}