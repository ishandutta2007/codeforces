#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;

const int mod = 7340033;
const int maxn = 2e5 + 5;

struct node {
    LL nowS, nowB; // sum = nowS * t + nowB
    LL lza, lzb;
    void update(LL x, LL y, int len) {
        lza += x;
        lzb += y;
        nowS += x * len;
        nowB += y * len;
    }
} f[maxn << 2];

void pushDown(int t, int l, int r, int mid)
{
    if (f[t].lza || f[t].lzb) {
        f[t << 1].update(f[t].lza, f[t].lzb, mid - l + 1);
        f[t << 1 | 1].update(f[t].lza, f[t].lzb, r - mid);

        f[t].lza = f[t].lzb = 0;
    }
}

void pushUp(int t)
{
    f[t].nowS = f[t << 1].nowS + f[t << 1 | 1].nowS;
    f[t].nowB = f[t << 1].nowB + f[t << 1 | 1].nowB;
}

void update(int t, int l, int r, int ll, int rr, LL lza, LL lzb)
{
    if (ll <= l && r <= rr) {
        f[t].update(lza, lzb, r - l + 1);
        return;
    }
    int mid = (l + r) >> 1;
    pushDown(t, l, r, mid);
    if (ll <= mid) update(LSON, ll, rr, lza, lzb);
    if (rr > mid) update(RSON, ll, rr, lza, lzb);
    pushUp(t);
}

// now is (nowS * t + nowB)
// every node in [ll, rr]: S += delta, B -= t * delta
void update(int n, int ll, int rr, int t, int delta)
{
    if (rr < ll) return;
    update(1, 1, n, ll, rr, delta, -1LL * t * delta);
}

PLL merge(PLL l, PLL r)
{
    return PLL(l.fi + r.fi, l.se + r.se);
}

PLL query(int t, int l, int r, int ll, int rr)
{
    //if (ll <= l && r <= rr) cout << l << " " << r << " : " << f[t].nowS << " " << f[t].nowB << " " << vt << endl;
    if (ll <= l && r <= rr) return PLL(f[t].nowS, f[t].nowB);
    int mid = (l + r) >> 1;
    pushDown(t, l, r, mid);

    if (rr <= mid) return query(LSON, ll, rr);
    if (ll > mid) return query(RSON, ll, rr);
    return merge(query(LSON, ll, rr), query(RSON, ll, rr));
}

template <class T>
inline bool In(T &ret) {
    char c = getchar();
    ret = 0;
	if(c == EOF) return false;
	T flag = 1;
    while (c != '-' && !isdigit(c)) c = getchar();
	if(c == '-') flag = -1, c = getchar();
    while (isdigit(c)) ret = ret * 10 + (c - '0'), c = getchar();
	ret *= flag;
	return true;
}

int a[maxn], idx[maxn], inque[maxn], pre[maxn], tail = 0;
P st[maxn];
vector<P> qry[maxn], upd[maxn];
LL ans[maxn * 5];
void solve()
{
    int n, q, l, r;
    In(n), In(q);

    for (int i = 1; i <= n; i++) {
        In(a[i]);
        idx[a[i]] = i;
    }

    for (int i = 1; i <= q; i++) {
        In(l), In(r);
        if (l > r) swap(l, r);
        qry[r].push_back(P(l, i));
    }

    for (int i = 1; i * i <= n; i++) {
        for (int j = i * (i + 1); j <= n; j += i) {
            l = idx[j / i];
            r = idx[i];
            if (l > r) swap(l, r);
            upd[max(r, idx[j])].push_back(P(j, min(l, idx[j])));
        }
    }

    for (int i = 1; i <= n; i++) {
        while (tail > 0 && st[tail].fi < a[i]) {
            inque[st[tail].fi] = 0;
            tail--;
            //cout << "upd " << st[tail].se + 1 << " " << pre[tail + 1] - 1 << " " << 0 << endl;
            // [st[tail].se + 1, pre[st[tail + 1].fi] - 1] now is 1
            update(n, st[tail].se + 1, pre[tail + 1] - 1, i - 1, -1);
        }

        st[++tail] = P(a[i], i);
        pre[tail] = st[tail - 1].se + 1;
        inque[a[i]] = tail;

        for (auto e:upd[i]) {
            int x = inque[e.fi];
            if (x == 0) continue;
            l = pre[x];
            r = min(st[x].se, e.se);
            //cout << "upd " << l << " " << r << " " << 1 << endl;
            if (r >= l) {
                update(n, l, r, i - 1, 1);
                pre[x] = r + 1;
            }
        }

        for (auto e:qry[i]) {
            PLL ret = query(1, 1, n, e.fi, i);
            ans[e.se] = ret.fi * i + ret.se;
        }
    }

    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    //cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}