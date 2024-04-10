#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first
#define ld long double
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define pld pair<ld,ld>
#define OO 1000000000000000000

using namespace std;

const ll MOD=998244353;

ll n, m, k, l, r;
ll a[1000001], b[1000001];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=MOD;
        h*=h;
        h%=MOD;
        r/=2;
    }
    return l;
}

void solve()
{

    cin >> n;
    /*for (int i = 0; i < binpow(10,n); i++)
    {
        ll x=i, j=0;
        vector<ll> v;
        while (j<n)
        {
            v.pb(x%10);
            x/=10;
            j++;
        }
        ll kl=1, p=v[0];
        v.pb(-1);
        for (int i = 1; i < v.size(); i++)
        {
            if (p!=v[i])
            {
                b[kl]++;
                p=v[i];
                kl=1;
            } else kl++;
        }
    }*/
    a[n]=10;
    for (int i = 1; i < n; i++)
    {
        if (i<n-1) a[i]=(binpow(10,n-i-1)*9*9)%MOD*(n-i-1)%MOD;
        a[i]=(a[i]+9*binpow(10,n-i)*2%MOD)%MOD;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}