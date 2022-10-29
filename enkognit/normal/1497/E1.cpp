#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef double ld;
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

ll n, m, k, T, sm, a[200005], b[200005], kl[100005], dp[200005];

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

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

void solve()
{
    cin >> n >> k;
    map<int,int> lst;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int p=sqrt(a[i]);
        ll x=a[i], y=1;
        for (int j = 2; j <= p; j++)
            if (x%j==0)
            {
                bool t=0;
                while (x%j==0) t^=1, x/=j;
                if (t) y*=j;
            }
        y*=x;
        if (lst.find(y)!=lst.end())
        {
            b[i]=lst[y];
        } else b[i]=-1;
        lst[y]=i;
        a[i]=y;
    }
    ll o=-1;
    for (int i = 1; i <= n; i++)
    {
        {
            o=max(o, b[i]);
            dp[i]=dp[o]+1;
        }
        //cout << i << " : " << dp[i] << " " << o << "\n";
    }
    //cout << "\n";
    cout << dp[n] << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}