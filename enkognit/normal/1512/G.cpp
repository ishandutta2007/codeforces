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

ll n, m, k, e[1001], b[1001], sz;
ll tt[10000001];
int ans[10000001];
pair<int,int> lst[10000001];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h;
        h*=h;
        r/=2;
    }
    return l;
}

void solve()
{
    cin >> n;
    if (ans[n]==0) cout << "-1\n"; else
    cout << ans[n] << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll E=1e7;
    ans[1]=1;
    vector<ll> v;
    ll p=0;
    for (ll i = 2; i <= E; i++) tt[i]=1;
    for (ll i = 2; i <= E; i++)
    {
        if (tt[i]==1)
        {
            //if (i%1000==0)cout << i << "\n";
            tt[i]=i+1;
            lst[i]=mp(i, 1);
            sz=1;
            e[1]=i+1;
            b[1]=i;
            b[0]=1;
            for (ll j = i*2; j <= E; j+=i)
            {
                if (lst[j/i].fi==i)
                {
                    if (sz==lst[j/i].se)
                    {
                        sz++;
                        b[sz]=b[sz-1]*i;
                        e[sz]=e[sz-1]+b[sz];
                    }
                    tt[j]*=e[lst[j/i].se+1];
                    lst[j]=mp(i, lst[j/i].se+1);
                }else
                tt[j]*=i+1, lst[j]=mp(i, 1);
            }
        }
        //if (i<100)cout << i << " : " << tt[i] << "\n";
        if (tt[i]<=1e7)
        {
            if (ans[tt[i]]==0)
                ans[tt[i]]=i;
        }
    }
    //cout << v.size() << "\n";
    /*for (int i = 1; i <= E; i++) dp[i]=1e9;
    dp[1]=1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]<10)
        cout << v[i] << "\n";
        for (int j = 1, sm = v[i]+1; sm <= E; j++, sm+=binpow(v[i],j))
            for (int u = E/sm; u > 0; u--)
                if (dp[u]<1e9)
                {
                    dp[u*sm]=min(dp[u]*binpow(v[i],j),dp[u*sm]);
                }
    }*/
    ll t=1;
    cin >> t;
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