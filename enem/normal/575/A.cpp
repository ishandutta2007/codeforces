#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define F first
#define S second
#define PB push_back
#define DB pop_back
#define V(a) vector<a>

static const ll N = 50005;
static ll n, m, k, p, s0[N], s[N];
static pair<pll, pll> st[4*N];
static map<ll, ll> mp;

inline pair<pll, pll> comp(pair<pll, pll> a, pair<pll, pll> b)
{
    return {
        {(a.F.F*b.F.F + a.S.F*b.F.S)%p, (a.F.S*b.F.F + a.S.S*b.F.S)%p},
        {(a.F.F*b.S.F + a.S.F*b.S.S)%p, (a.F.S*b.S.F + a.S.S*b.S.S)%p}
        };
}

void build(ll v, ll tl, ll tr)
{
    if(tl==tr)
    {
        st[v] = {{0, 1}, {s[tl], s[tl+1]}};
        return;
    }
    build((v<<1), tl, ((tl+tr)>>1));
    build((v<<1)|1, ((tl+tr)>>1)+1, tr);
    st[v] = comp(st[(v<<1)], st[(v<<1)|1]);
    return;
}

void update(ll v, ll tl, ll tr, ll pos, ll val)
{
    if(pos < tl || pos > tr+1)
    {
        return;
    }
    if(tl == tr)
    {
        s[pos] = val;
        st[v] = {{0, 1}, {s[tl], s[tl+1]}};
        return;
    }
    update((v<<1), tl, ((tl+tr)>>1), pos, val);
    update((v<<1)|1, ((tl+tr)>>1)+1, tr, pos, val);
    st[v] = comp(st[(v<<1)], st[(v<<1)|1]);
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>k>>p>>n;
    REP(i,0,n) cin>>s[i];
    s[n] = s[0];
    REP(i,0,n+1) s0[i] = s[i];
    build(1, 0, n-1);
    cin>>m;
    REP(i,0,m)
    {
        ll x, t;
        cin>>x>>t;
        mp[x] = t;
    }
    pair<pll, pll> a = {{1, 0}, {0, 1}};
    ll cur_cyc = 0;
    ll fin_cyc = k/n;
    while(cur_cyc < fin_cyc)
    {
        auto it = mp.lower_bound(cur_cyc*n);
        ll nx_cyc;
        if(it == mp.end()) nx_cyc = fin_cyc;
        else if((*it).F == cur_cyc*n) nx_cyc = cur_cyc;
        else
        {
            nx_cyc = ((*it).F-1)/n;
        }
        if(nx_cyc >= fin_cyc) nx_cyc = fin_cyc - 1;
        pair<pll, pll> x = st[1];
        REP(i,0,60)
        {
            if(nx_cyc == cur_cyc) break;
            if((nx_cyc-cur_cyc)&(1LL<<i))
            {
                cur_cyc += (1LL<<i);
                a = comp(a, x);
            }
            x = comp(x, x);
        }
        V(ll) upd;
        while(it != mp.end() && (*it).F <= (cur_cyc+1)*n)
        {
            upd.PB((*it).F - cur_cyc*n);
            update(1, 0, n-1, upd.back(), (*it).S);
            it++;
        }
        a = comp(a, st[1]);
        cur_cyc++;
        while(!upd.empty())
        {
            update(1, 0, n-1, upd.back(), s0[upd.back()]);
            upd.DB();
        }
    }
    REP(i, 0, k%n)
    {
        if(mp.count(fin_cyc*n+i)) s[i] = mp[fin_cyc*n+i];
        if(mp.count(fin_cyc*n+i+1)) s[i+1] = mp[fin_cyc*n+i+1];
        a = comp(a, {{0, 1}, {s[i], s[i+1]}});
    }
    cout<<a.F.S;

    return 0;
}