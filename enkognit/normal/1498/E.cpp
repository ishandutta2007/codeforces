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

ll n, m, k, sz;
pll a[200005];

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

bool is(ll n)
{
    ll x=n, o=0;
    while (x)
    {
        o+=x%10;
        x/=10;
    }
    return __gcd(n, o)>1;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].se=i;
    }
    sort(a+1,a+n+1);
    vector<pair<ll,pll> > v;
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            v.pb(mp(abs(a[i].fi-a[j].fi), mp(i, j)));
    sort(all(v));
    reverse(all(v));
    for (int i = 0; i < v.size(); i++)
    {
        cout << "? " << a[v[i].se.se].se << " " << a[v[i].se.fi].se << "\n";
        string s;
        cin >> s;
        if (s[0]=='Y')
        {
            cout << "! " << a[v[i].se.se].se << " " << a[v[i].se.fi].se << "\n";
            exit(0);
        }
    }
    cout << "! 0 0\n";
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