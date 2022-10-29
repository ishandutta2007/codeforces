#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define all(v) v.begin(),v.end()

using namespace std;

const ll MOD=1e9+7;

ll n[4], m, k, q, T, a[4][300005], sm[4];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%MOD;
        h=(h*h)%MOD;
        r/=2;
    }
    return l;
}

void solve()
{
    cin >> n[1] >> n[2] >> n[3];
    ll s=0;
    for (int j = 1; j <= 3; j++)
    {
        for (int i = 1; i <= n[j]; i++)
        {
            cin >> a[j][i];
            sm[j]+=a[j][i];
            s+=a[j][i];
        }
        sort(a[j]+1, a[j]+n[j]+1);
    }
    vector<ll> v;
    v.pb(0);
    v.pb(1);
    v.pb(2);
    v.pb(3);
    ll ans=0;
    do
    {
        {
            if (sm[v[2]]-a[v[2]][1]>a[v[3]][1])
            {
                ans=max(ans, s-(a[v[2]][1]+a[v[3]][1])*2);
            }else
            {
                ans=max(ans, s-sm[v[2]]*2);
            }
        }
        {
            if (sm[v[3]]-a[v[3]][1]>a[v[2]][1])
            {
                ans=max(ans, s-(a[v[2]][1]+a[v[3]][1])*2);
            }else
            {
                ans=max(ans, s-sm[v[3]]*2);
            }
        }
        if (!(v[1]==3 && v[2]==2 && v[3]==1))
        {
            next_permutation(v.begin()+1,v.end());
        }else break;
    }while(1);
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
3 2
0 1
1 2
1 2
2 3
2 3
3 4
1 2
2 3

3 4
0 0 0 0
1 1 1 1
1 1 1 1
2 2 2 2
0 0 0 0
2 3 2 3
1 3
2 3
*/
/*

}


*/