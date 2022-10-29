#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, i, j, kol=0, T=0, mask, d[3000001];

string s;
ll tt[200001];
vector <ll> v;
vector <pll> a, z;

void build(ll h,ll l,ll r)
{
    if (l==r)
    {
        d[h]=v[l];
        return;
    }
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=max(d[h*2],d[h*2+1]);
}

ll get(ll h,ll l,ll r,ll x,ll y)
{
    if (x>y) return 0;
    if (l==x && y==r) return d[h];
    ll w=(l+r)/2;
    return max(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
}

ll solve()
{
        cin >> n;
        ll p=0;
        v.clear();
        a.clear();
        z.clear();
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.pb(x);
            p=max(p, v[i]);
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            z.pb(mp(x,y));
        }
        sort(z.begin(),z.end());
        if (z.back().fi<p) {return -1;}
        build(1,0,n-1);
        a.pb(z.back());
        for (int i = m-2; i > -1; i--) if (a.back().se<z[i].se) a.pb(z[i]);
        reverse(a.begin(),a.end());
        p=0;
        ll ans=0;
        while (p<n)
        {
           // cout << p << "\n";
            ans++;
            ll l=0, r=a.size()-1;
            while (l+1<r)
            {
                ll w=(l+r)/2;
                ll z=get(1,0,n-1,p,min(p+a[w].se-1,n-1));
                if (z<=a[w].fi)
                {
                    if (p+a[w].se-1>=n-1) return ans;
                    r=w;
                } else l=w;
            }
            ll l1=p, r1=min(n-1,p+a[l].se-1);
            //cout << a[l].fi << " " << a[l].se << "\n" << a[r].fi << " " << a[r].se << "\n";
            while (l1<r1)
            {
                ll w=(l1+r1+1)/2;
                if (get(1,0,n-1,p,w)>a[l].fi) r1=w-1; else l1=w;
            }
            if (p+a[r].se>l1+1) p+=a[r].se; else p=l1+1;
        }
        return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        cout << solve() << "\n";
    }
    return 0;
}
/*
1
9
1 3 1 10 5 1 2 3 4
6
5 2
11 1
4 3
10 1
2 1
2 55
3
*/