#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, q, ans, l, r, i, j;
vector <ll> c[100008], v, z;
ll t[1000001],u[1000001];

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    for (int i = 2; i <= 1e4; i++)
        if (!t[i])
        {
            u[z.size()]=1;
            z.pb(i);
            ll j=i*i;
            while (j<=1e4) t[j]=1, j+=i;
        }
    cin >> n;
    if (n==1) {cout << 1;exit(0);}
    ll p=sqrt(n), o=1;
    for (int i = 2; i <= p; i++)
    {
        while (n%i==0) v.pb(i),n/=i, o*=i;
    }
    if (n>1) v.pb(n), o*=n;
    ll ans=1;
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        ll e=1e18, w=0;
        for (int j = 0; j < z.size(); j++)
        {
            if (e>pow(z[j],u[j]*(v[i]-1)))
              e=pow(z[j],u[j]*(v[i]-1)), w=j;
        }
        u[w]*=v[i];
        ans*=e;
    }
    cout << ans;

    return 0;
}