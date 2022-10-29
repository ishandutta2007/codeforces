#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, a[500001];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

ll read()
{
    char c=getchar();
    while (!isdigit(c))
    {
        c=getchar();
    }
    ll res=0;
    while (isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

void solve()
{
    string s;
    cin >> s;
    n=s.size();
    s=' '+s;
    bool t=0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i]=='?') a[i]=2; else
        {
            t=1;
            a[i]=(s[i]-'0');
            a[i]^=(i%2);
        }
    }
    if (!t)
    {
        cout << n*(n+1)/2 << "\n";
        return;
    }
    ll k=0, lst=-1, ans=0;
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        //cout << a[i];
        if (a[i]==lst) v.back().se++; else
            v.pb(mp(a[i], 1));
        lst=a[i];
    }
    for (int i = 0; i < v.size(); i++)
        if (v[i].fi==2)
        {
            ll z=0;
            if (i>0 && i<v.size()-1)
            {
                if (v[i-1].fi!=v[i+1].fi) ans-=v[i].se*(v[i].se+1)/2, v[i-1].se+=v[i].se, v[i+1].se+=v[i].se;
                    else v[i-1].se+=v[i].se;
            }else
            if (i>0) v[i-1].se+=v[i].se; else
            if (i<v.size()-1) v[i+1].se+=v[i].se;
        }
    vector<pll> u;
    for (int i = 0; i < v.size(); i++)
        if (v[i].fi!=2)
        {
            if (u.size()==0 || u.back().fi!=v[i].fi) u.pb(v[i]); else
                u.back().se+=v[i].se;
        }
    for (int i = 0; i < u.size(); i++) ans+=u[i].se*(u[i].se+1)/2;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //cin >> t;
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
ll read()
{
    char c=getchar();
    while (!isdigit(c))
    {
        c=getchar();
    }
    ll res=0;
    while (isdigit(c))
    {
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}
*/