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
#define sqr(a) ((a)*(a))
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, T, i, j, h, sum, a[1000001], ans[1000001];
vector <pld> v;
vector <ll> c[200001];

int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> a[i];ans[i]=1e18;}
    set<pll> s;
    for (int i = 1; i <= n; i++)
        if (i-a[i]>0 && a[i-a[i]]%2!=a[i]%2 || i+a[i]<=n && a[i+a[i]]%2!=a[i]%2) ans[i]=1, s.insert(mp(1,i));
    for (int i = 1; i <= n; i++)
        if (ans[i]==1e18)
    {
        if (i-a[i]>0) c[i-a[i]].pb(i);
        if (i+a[i]<=n) c[i+a[i]].pb(i);
    }
    while (s.size())
    {
        ll x=(*s.begin()).se;
        s.erase(s.begin());
        for (int i = 0; i < c[x].size(); i++)
            if (ans[c[x][i]]>ans[x]+1)
        {
            s.erase(mp(ans[c[x][i]],c[x][i]));
            ans[c[x][i]]=ans[x]+1;
            s.insert(mp(ans[c[x][i]],c[x][i]));
        }
    }
    for (int i = 1; i <= n; i++) if (ans[i]==1e18) cout << "-1 "; else cout << ans[i] << " ";
    return 0;
}