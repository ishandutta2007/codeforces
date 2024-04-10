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

const ll MOD=998244353;

ll n, m, k, sz, sm[300005];
vector<vector<ll> > a, rr, cc;

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
    cin >> n >> m;
    a.resize(n+1);
    rr.resize(n+1);
    cc.resize(n+1);
    ll kol=0;
    for (int i = 0; i <= n; i++)
    {
        a[i].resize(m+1, 0);
        rr[i].resize(m+1, 0);
        cc[i].resize(m+1, 0);
        if (i==0) continue;
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            a[i][j+1]=(s[j]=='*');
            kol+=(a[i][j+1]==0);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        rr[i][0]=0;
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j]==1) rr[i][j]=j; else
                rr[i][j]=rr[i][j-1];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cc[0][i]=0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j][i]==1) cc[j][i]=j; else
                cc[j][i]=cc[j-1][i];
        }
    }
    //cout << "----\n";

    for (int i = 1; i <= max(n, m)+3; i++)
    {
        sm[i]=sm[i-1];
        if (i%2 && i!=1)
        {
            sm[i]=(sm[i]+binpow(2, kol-i, MOD))%MOD;
        }
    }
    ll ans=0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j]==0)
        {
            //cout << i << " " << j << " " << rr[i][j] << " " << cc[i][j] << " " << sm[i-cc[i][j]] << " " << sm[j-rr[i][j]] << "\n";
            ans=(ans+sm[i-cc[i][j]]+sm[j-rr[i][j]]+
                 (cc[i][j]%2==i%2?binpow(2,kol-(i-cc[i][j]), MOD):0)+
                 (rr[i][j]%2==j%2?binpow(2,kol-(j-rr[i][j]), MOD):0))%MOD;
            //cout << ans << "\n";
        }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
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