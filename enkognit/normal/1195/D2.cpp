#include <bits/stdc++.h>
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

using namespace std;

const ll MOD = 998244353;

ll n, m, k, q, ans, l, r, i, j, g0, x, y, z;
ll a[100001];
pll b[12];

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        ll j=0, h=a[i], p=0;
        while (h)
        {
            p+=(h%10)*(ll)pow(10,j*2);
            ans%=MOD;
            p%=MOD;
            ans+=p*b[j+1].se*11;
            ans%=MOD;
            ans+=b[j+1].fi*11;
            ans%=MOD;
            h/=10;
            ans+=(((h*((ll)pow(10,(j+1)*2)%MOD))%MOD)*b[j+1].se)%MOD*2;
            ans%=MOD;
            j++;
        }
        b[j].fi+=p;
        b[j].fi%=MOD;
        b[j].se++;
        ans+=p*11;
        ans%=MOD;
        //cout << p << " " << j << " " << ans << "\n";
    }
    cout << ans;
    return 0;
}


/*

| 1 5 13 29 | 2 7 17 37 | 18 39 22 47 |


*/