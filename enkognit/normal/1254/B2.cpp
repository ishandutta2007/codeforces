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

ll n, m, T, k, l, r, i, j, sum, kol=0, ans, a[1000003], b[1000003];
string s, f;
bool tt[10000001];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    ll p=0, ans=1e18;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p+=a[i];
    }
    ll w=p;
    vector <ll> v;
    for (int i = 2; i <= sqrt(w); i++)
        if (w%i==0)
    {
        v.pb(i);
        while(w%i==0) w/=i;
    }
    if (w>1) v.pb(w);
    if (p<2) {cout << -1;exit(0);}
    for (i = 1; i <= n; i++) b[i]=a[i];
    ll o=p, m=sqrt(p);
    ll e=p, j, an, l, r, it;
    for (auto it : v)
        {
            //cout << it << "\n";
            o=it;
            if (o!=1)
            {
                p=0, an=0;
                for (i = 1; i <= n; i++)
                {
                    an+=p;
                    if (p>b[i]) j=b[i]; else j=p;
                    b[i]-=j;
                    p-=j;
                    l=b[i]%o, r=o-l;
                    if (l<r)
                    {
                        b[i+1]+=l;
                        an+=l;
                    }else
                    {
                        p+=r;
                    }
                    b[i]=a[i];
                }
                if (ans>an) ans=an;
            }
            //ans=min(ans,an);
        }
    //cout << o << "\n";xf

    cout << ans;
    return 0;
}