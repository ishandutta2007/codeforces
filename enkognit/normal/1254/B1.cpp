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

ll n, m, T, k, l, r, i, j, sum, kol=0, ans, a[1000001], b[1000001];
vector <ll> v;
bool tt[5000001];
string s, f;

ll gcd(ll x,ll y)
{
    if (x==0 || y==0) return x+y; else return __gcd(x,y);
}

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    ll p=0, z=0, ans=1e18;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        z=gcd(a[i],z);
        p+=a[i];
    }
    if (z>1) {cout << 0;exit(0);}
    if (p<2) {cout << -1;exit(0);}
    ll o=p, m=sqrt(p);
    ll e=p;
    for (ll it = 1; it <= m; it++)
        if (e%it==0)
        {
            o=it;
            if (o!=1)
            {
                ll p=0, an=0;
                for (int i = 1; i <= n; i++) b[i]=a[i];
                for (int i = 1; i <= n; i++)
                {
                    an+=p;
                    ll j=min(p,b[i]);
                    b[i]-=j;
                    p-=j;
                    ll l=b[i]%o, r=o-l;
                    if (l<r)
                    {
                        b[i+1]+=l;
                        an+=l;
                    }else
                    {
                        p+=r;
                    }
                }
                ans=min(an,ans);
            }
            o=e/it;
            if (o!=1)
            {
                ll p=0, an=0;
                for (int i = 1; i <= n; i++) b[i]=a[i];
                for (int i = 1; i <= n; i++)
                {
                    an+=p;
                    ll j=min(p,b[i]);
                    b[i]-=j;
                    p-=j;
                    ll l=b[i]%o, r=o-l;
                    if (l<r)
                    {
                        b[i+1]+=l;
                        an+=l;
                    }else
                    {
                        p+=r;
                    }
                }
                ans=min(ans,an);
            }
            //ans=min(ans,an);
        }
    //cout << o << "\n";xf

    cout << ans;
    return 0;
}