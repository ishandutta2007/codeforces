#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

const ll MOD=998244353;

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0;

pll a[400001];
vector <ll> c[300001];
string s;

ll fact(ll h)
{
    if (h==1) return 1; else return (h*fact(h-1))%MOD;
}

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector <ll> v={}, z={};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        v.pb(a[i].fi);
        z.pb(a[i].se);
    }
    sort(v.begin(),v.end());
    sort(z.begin(),z.end());
    v.pb(1e18);
    z.pb(1e18);
    ll o=1, p=1;
    for (int i = 1; i <= n; i++)
    {
        if (v[i-1]==v[i])  o++; else
        {
            p*=fact(o);
            p%=MOD;
            o=1;
        }
    }
    ll w=1;
    o=1;
    for (int i = 1; i <= n; i++)
    {
        if (z[i-1]==z[i])  o++; else
        {
            w*=fact(o);
            w%=MOD;
            o=1;
        }
    }
    p+=w;
    p%=MOD;
    sort(a,a+n);
    ll q=1;
    o=1;
    //a[n]=mp(1e18,1e18);
    for (int i = 1; i < n; i++)
    {
        if (a[i].se<a[i-1].se) {q=0;break;}
        if (a[i].fi==a[i-1].fi && a[i].se==a[i-1].se)
        {
            o++;
        }else
        {
            q*=fact(o);
            q%=MOD;
            o=1;
        }
    }
    q*=fact(o);
    q%=MOD;
    ll u=fact(n)-p+q;
    while (u<0) u+=MOD;
    u%=MOD;
    cout << u;
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/