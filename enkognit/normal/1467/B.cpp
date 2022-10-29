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

ll n, m, k, q, T, a[300005];

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

bool is(ll i)
{
    return (i>1 && i<n && (a[i]>a[i-1] &&
                           a[i]>a[i+1] || a[i]<a[i-1] && a[i]<a[i+1]));
}

void solve()
{
    cin >> n;
    ll k=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        k+=is(i);
    }
    ll ans=k;
    for (int i = 1; i <= n; i++)
    {
        ll kk=k-is(i-1)-is(i)-is(i+1);
        ll o=a[i];
        a[i]=-1;
        ans=min(ans, kk+is(i)+is(i+1)+is(i-1));
        a[i]=1e18;
        ans=min(ans, kk+is(i)+is(i+1)+is(i-1));
        if (i>1)
        {
            a[i]=a[i-1];
            ans=min(ans, kk+is(i)+is(i+1)+is(i-1));
        }
        if (i<n)
        {
            a[i]=a[i+1];
            ans=min(ans, kk+is(i)+is(i+1)+is(i-1));
        }
        a[i]=o;
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
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