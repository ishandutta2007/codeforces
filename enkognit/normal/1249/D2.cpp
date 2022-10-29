#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back


using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, i, j, a[200001], d[10000001], q[200001];
ll t[200001], f[200001];
vector <pll> v, p;

void update(ll h,ll l,ll r,ll x,ll k)
{
    if (l==r)
    {
        d[h]+=k;
        return;
    }
    ll w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
    d[h]=d[h*2+1]+d[h*2];
}

pll get(ll h,ll l,ll r)
{
    if (l==r) return mp(l,v[l].se);
    ll w=(l+r)/2;
    //cout << l << "-" << r << " " << d[h*2+1] << "\n";
    if (d[h*2+1]>0) return get(h*2+1,w+1,r); else return get(h*2,l,w);
}

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ll l, r;
        cin >> l >> r;
        v.pb(mp(r,i));
        p.pb(mp(l,i));
        t[l]++;
        t[r+1]--;
        f[i]=r+1;
    }
    p.pb(mp(0,0));
    v.pb(mp(0,0));
    sort(p.begin(),p.end());
    sort(v.begin(),v.end());
    for (int i = 1; i <= n; i++) q[v[i].se]=i;
    ll o=0, sm=0;
    vector <ll> ans;
    for (int i = 1; i <= 200000; i++)
    {
        while (o<p.size() && p[o+1].fi<=i)
        {
            o++;
            update(1,1,200000,q[p[o].se],1);
            //cout << p[o].se << "\n";
        }
        sm+=t[i];
        //if (i<1200)cout << i << " " << sm << "\n";
        while (sm>m)
        {
            pll u=get(1,1,200000);
            ans.pb(u.se);
            //cout << u.se << "\n";
            update(1,1,200000,u.fi,-1);
            t[f[u.se]]++;
            sm--;
        }
    }
    cout << ans.size() << "\n";
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}