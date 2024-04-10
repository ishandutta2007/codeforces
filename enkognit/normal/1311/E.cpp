#include <bits/stdc++.h>
#pragma GCC optimize("-g")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()


using namespace std;

ll n, m, l, r, ans, a[100001];
vector<pll> v[5001];

void solve()
{
    ll n, d;
    cin >> n >> d;
    for (int i = 0; i <= n; i++) v[i].clear(), a[i]=0;
    v[0].pb(mp(1,2));
    if (n*(n-1)/2<d) {cout << "NO\n";return;}
    a[0]=1;
    ll p=n-1, i=0, u=d;
    while(p) i++, p-=(a[i]=min(p,a[i-1]*2)), u-=a[i]*i;
    //cout << u << "\n";
    if (u<0) {cout << "NO\n";return;}

    while (u--)
    {
        bool prichina_zhyc=0;
        for (int i = 1; i <= n; i++)
            if (a[i] && (a[i]-1)*2>=a[i+1]+1) {a[i+1]++, a[i]--, prichina_zhyc=1;break;}
        if (!prichina_zhyc) {cout << "NO\n";return;}
    }

    cout << "YES\n";
    ll kl=1;
    for (int i = 1; i <= n; i++)
    {
        while (a[i]>0)
        {
            a[i]--;
            kl++;
            for (int j = 0; j < v[i-1].size(); j++)
                if (v[i-1][j].se) {v[i-1][j].se--;cout << v[i-1][j].fi << " ";break;}
            v[i].pb(mp(kl,2));
        }
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}