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

ll n, m, T, k, kl, a[1000001];
vector<ll> v;
string s;
map<int,bool> ww;

void solve()
{
    cin >> n >> m;
    bool tt=0;
    ww.clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ww[a[i]]=1;
    }
    ll ans=1e18;
    for (int i = 1; i <= n; i++)
    {
        ll u=m/a[i];
        if (m%a[i]==0) u=m/a[i]; else
        {
            if (ww[m%a[i]]) u++; else
            {
                if (u>0) u++; else
                u+=2;
            }
        }
        ans=min(ans,u);
    }
    cout << ans << "\n";
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
*/