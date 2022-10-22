#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

void upd(ll& a, ll b) { a = max(a, b); }
const int maxn = 1 << 19;
const ll inf = 1e18;
struct segment_tree
{
    vector<ll> st;
    segment_tree() { st.assign(maxn * 2, -inf); }
    void update(int i, ll x)
    {
        for (i += maxn; i > 0; i >>= 1) upd(st[i], x);
    }
    ll query(int l, int r)
    {
        ll ans = -inf;
        l = max(l, 0), r = min(r, maxn - 1);
        for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) upd(ans, st[l++]);
            if (r & 1) upd(ans, st[--r]);
        }
        return ans;
    }
};
segment_tree stdp, sts, stf;
vector<vector<ll> > pf(3, vector<ll>(maxn, 0));
vector<ll> s(maxn), f(maxn);
struct offer { int l, r; ll k; };
bool cmp(const offer& a, const offer& b) { return a.r < b.r; }
ll ans = -inf;
void solve(int l, int r, const vector<offer>& of, ll all = -inf)
{
    if (l == r)
    {
        for (offer o : of) upd(all, -o.k);
        //cout << s[l] << " " << f[l] << " " << all << " : " << s[l] + f[l] + all << "\n";
        upd(ans, s[l] + f[l] + all);
        return;
    }
    int m = (l + r) / 2;
    vector<offer> ofl, ofr;
    for (offer o : of)
    {
        if (o.l <= l && r <= o.r)
        {
            upd(all, -o.k);
            continue;
        }
        if (o.l <= m) ofl.push_back(o);
        if (o.r > m) ofr.push_back(o);
        //cout << (sts.query(o.l, m) + stf.query(m + 1, o.r) - o.k) << "\n";
        upd(ans, sts.query(o.l, m) + stf.query(m + 1, o.r) - o.k);
        //cout << (stdp.query(o.l - 1, m) + stf.query(m + 1, o.r) - o.k) << "\n";
        upd(ans, stdp.query(o.l - 1, m) + stf.query(m + 1, o.r) - o.k);
    }
    //cout << (sts.query(l, m) + stf.query(m + 1, r) + all) << "\n";
    upd(ans, sts.query(l, m) + stf.query(m + 1, r) + all);
    //cout << (stdp.query(l, m) + stf.query(m + 1, r) + all) << "\n";
    upd(ans, stdp.query(l, m) + stf.query(m + 1, r) + all);
    solve(l, m, ofl, all);
    solve(m + 1, r, ofr, all);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < 3; i++) for (int j = 0; j < n; j++)
    {
        ll a; cin >> a;
        pf[i][j + 1] = pf[i][j] + a;
    }
    vector<offer> o(q);
    for (int i = 0; i < q; i++) cin >> o[i].l >> o[i].r >> o[i].k, o[i].l--, o[i].r--;
    sort(o.begin(), o.begin() + q, cmp);
    for (int i = 0; i < n; i++)
    {
        s[i] = pf[0][i + 1] - pf[1][i];
        sts.update(i, s[i]);
        f[i] = pf[1][i + 1] + pf[2][n] - pf[2][i];
        stf.update(i, f[i]);
    }
    for (offer i : o)
    {
        ll val = max(sts.query(i.l, i.r), stdp.query(i.l - 1, i.r)) - i.k;
        stdp.update(i.r, val);
        //cout << i.l << " " << i.r << " " << i.k << " : " << val << "\n";
    }
    solve(0, n - 1, o);
    cout << ans << "\n";
    return 0;
}