#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair

using namespace std;

ll n, m, i, j, k, ans[500001], l, r, kol[500005], sum[500005];
string s[1005];
vector <pll> v, c;
bool t[1000001];
ll d[3000001];

ll get(ll h,ll l,ll r,ll x,ll k=0)
{
    if (l==r) return l;
    ll w=(l+r)/2;
    if (k+d[h*2]>=x) return get(h*2,l,w,x,k); else return get(h*2+1,w+1,r,x,k+d[h*2]);
}

void update(ll h,ll l,ll r,ll x)
{
    if (l==r) {d[h]=1;return;}
    ll w=(l+r)/2;
    if (w>=x) update(h*2,l,w,x); else update(h*2+1,w+1,r,x);
    d[h]=d[h*2]+d[h*2+1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin >> n >> m >> k;
    ll kl=m;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        kol[x]++;
        if (kol[x]==1) kl--;
    }

    for (int i = 1; i <= m; i++)
    {
        v.pb(mp(kol[i], i));
    }

    sort(v.begin(),v.end());

    for (int i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        c.pb(mp(x,i));
    }

    sort(c.begin(),c.end());

    ll year=n, mn=0, w=0;

    for (int i = 0; i < kl; i++) update(1,1,m,v[i].se);

    for (int i = 0; i < c.size(); i++)
    {
        if (c[i].fi-year>kl-w)
        {
            year+=kl-w;
            w=0;
            mn++;
            while (kl<v.size() && v[kl].fi==mn) update(1,1,m,v[kl].se),kl++;
            while (c[i].fi-year>kl && kl<m)
            {
                mn++;
                year+=kl;
                while (kl<v.size() && v[kl].fi==mn) update(1,1,m,v[kl].se),kl++;
            }
            if (c[i].fi-year>kl && kl==m) year+=(c[i].fi-year-1)/kl*kl;
        }
        w+=c[i].fi-year;
        year=c[i].fi;
        ans[c[i].se]=get(1,1,m,w);
        //cout << c[i].fi << " " << mn << " " << kl << " " << w << "\n";
    }
    for (int i = 0; i < k; i++) cout << ans[i] << "\n";
}