#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;

ll n, m, i, p, k, T, j, A, B, C, y, kol, r[1002], c[1002], a[2002][2002];
ll b[80];
vector <ll> v, z, e;
bool tt[100001];

ll binpow(ll h,ll p)
{
    ll l=1;
    h%=MOD;
    while (p)
    {
        if (p%2) l*=h, l%=MOD;
        h*=h;
        h%=MOD;
        p/=2;
    }
    return l;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll x, n;
    cin >> x >> n;
    v.pb(x);
    ll p=sqrt(x);
    for (int i = 2; i <= p; i++)
        if (x%i==0) v.pb(i), v.pb(x/i);
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
        if (!tt[i])
    {
        z.pb(v[i]);
        for (int j = i+1; j < v.size(); j++)
            if (v[j]%v[i]==0) tt[j]=1;
    }
    ll ans=1;
    for (int i = 0; i < z.size(); i++)
    {
        //cout << z[i] << ":\n";
        ll p=0, l=1;
        e.clear();
        while (n/l>=z[i])
        {
            p++;
            l*=z[i];
            e.pb(l);
        }
        ll u=0;
        for (p=p-1; p > -1; p--)
        {
            ll w=n/e[p];
            //cout << " " << e[p] << "-" << w << "\n";
            ans*=binpow(e[p],w-u)%MOD;
            ans%=MOD;
            u=w;
        }
        //cout << ans << "\n";
    }
    cout << ans;
}