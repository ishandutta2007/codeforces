#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
#define all(v) v.begin(),v.end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))

using namespace std;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, s, f, o, T, dp[50][50][2];

ll binpow(ll h,ll r,ll md=MOD)
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
    cin >> n >> m;
    if (m<n)
    {
        cout << "NO\n";
        return;
    }
    string s, d;
    ll x=n;
    while(x)
    {
        s+=('0'+x%2);
        x/=2;
    }
    ll y=m;
    while(y)
    {
        d+=('0'+y%2);
        y/=2;
    }
    ll k1=0, k2=0;
    vector<ll> v1, v2;
    v1.pb(0);
    v2.pb(0);
    while (s.size()<d.size()) s+='0';
    reverse(all(s));
    reverse(all(d));
    for (int i = 0; i < s.size(); i++)
        if (s[i]=='1')
        {
            k1++;
            v1.pb(i+1);
        }
    for (int i = 0; i < d.size(); i++)
        if (d[i]=='1')
        {
            k2++;
            v2.pb(i+1);
        }
    if (k1<k2)
    {
        cout << "NO\n";
        return;
    }
    //cout << s << "\n" << d << "\n";
    for (int i = 0; i < v2.size(); i++)
        for (int j = 0; j < v1.size(); j++)
            for (int u = 0; u < 2; u++) dp[i][j][u]=0;
    dp[0][0][0]=1;
    for (int i = 0; i < v2.size(); i++)
        for (int j = 0; j < v1.size(); j++)
            for (int u = 0; u < 2; u++)
                if (dp[i][j][u])
                {
                    //cout << i << " " << j << " " << u << " " << (j+1<v1.size()?v1[j+1]:-1) << " " << v2[i+1] << "\n";
                    if (j+1<v1.size())
                    {
                        if (u) dp[i][j+1][1]=1;
                        if (i+1<v2.size())
                        {
                            if (v1[j+1]==v2[i+1])
                                dp[i+1][j+1][0]=1;
                            if (v1[j+1]>v2[i+1])
                            {
                                dp[i+1][j+1][1]=1;
                            }
                        }
                    }
                }
    cout << (dp[v2.size()-1][v1.size()-1][0] || dp[v2.size()-1][v1.size()-1][1]?"YES\n":"NO\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
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
10 10
1 3
3 5
5 7
7 9
2 9
1 4
4 6
6 8
8 10
2 10
*/