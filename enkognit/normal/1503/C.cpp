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

ll n, T, m, ans=0, a[100001];
string s, d1, d2;
vector<pll > v;
ll d[1000001];

void build(int h,int l,int r)
{
    if (l==r)
    {
        d[h]=v[l].fi+v[l].se;
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=max(d[h*2],d[h*2+1]);
}

ll get(int h,int l,int r,int x,int y)
{
    if (x>y) return 0;
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return max(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
}

void solve()
{
    cin >> n;
    ll sm=0;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x, y));
        sm+=y;
    }
    sort(all(v));
    vector<ll> z;
    for (int i = 0; i < v.size(); i++) z.pb(v[i].fi);

    build(1,0,v.size()-1);

    ll o=0;
    ll ans=sm;
    while (o<v.size()-1)
    {
        ll p=get(1,0,v.size()-1,0,o);
        if (p<v[o+1].fi)
        {
            ans+=v[o+1].fi-p;
            o++;
        }else
        {
            o=(upper_bound(all(z), p)-z.begin())-1;
        }
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

*/