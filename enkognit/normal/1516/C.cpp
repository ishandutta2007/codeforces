#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, sz, a[200005], pr[200005];
bool dp[200005];
ll lst[100001];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

void solve()
{
    cin >> n;
    ll p=0, sm=0, mn=1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ll x=a[i], y=0;
        while (x%2==0)
        {
            y++;
            x/=2;
        }
        if (y<mn) mn=y, p=i;
        sm+=a[i];
    }
    if (sm%2)
    {
        cout << "0\n";
        return;
    }
    dp[0]=1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = sm-a[i]; j > -1; j--)
            dp[j+a[i]]|=dp[j];
    }
    if (dp[sm/2])
    {
        cout << "1\n";
        cout << p << "\n";
    }else
    cout << "0\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*
6 6 1 12
1 2 1 1 1
2 4 1 1 1
1 3 1 1 2
3 5 1 1 2
5 4 1 1 1
5 6 1 1 1
1 5
3
5
*/