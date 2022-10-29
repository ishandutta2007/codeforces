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

using namespace std;

ll md1=1e9+7, md2=998244357, p1=31, p2=127;

ll n, m, k, f, l, r, i, j, b[300001], a[300001], c[300001];
vector <ll> v;

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

ll get(ll w)
{
    if (w==0) return 1e18;
    if (w>n) return 0;
    ll o=w, j=0, an=0;
    while (o*2<=n) o*=2, an+=binpow(2,j), j++;
    ll u=n-o;
    an+=min(binpow(2,j),u+1);
    return an;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    //for (int i = 2; i <= n; i+=2) cout << get(i)+get(i+1) << " ";
    //cout << "\n";
    ll l=0, r=n/2;
    while (l<r)
    {
        ll w=(l+r+1)/2;
        ll an1=get(w*2);
        an1+=get(w*2+1);
        if (an1<k)  r=w-1; else l=w;
    }
    while (get(l*2)+get(l*2+1)<k) l--;
    if (get(l*2+1)>=k && l*2+1<=n) cout << l*2+1 << "\n"; else cout << l*2 << "\n";
    return 0;
}
/*
cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
    }
*/