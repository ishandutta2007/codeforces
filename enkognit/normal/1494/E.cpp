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

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, dd, m, k, kl1, kl2, T, ans=1, jj, zrp[2005], a[505][505];
bool tt[1001];
vector<pll> an;

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

set<pair<pii, int> > s;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        char c;
        cin >> c;
        if (c=='+')
        {
            int x, y;
            char c;
            cin >> x >> y;
            cin >> c;
            auto u=s.upper_bound(mp(mp(y, x), -1));
            if (u!=s.end() && (*u).fi==mp(y, x))
            {
                kl1++;
                if (c-'a'==(*u).se) kl2++;
            }
            s.insert(mp(mp(x, y), c-'a'));
        }else
        if (c=='-')
        {
            int x, y;
            cin >> x >> y;
            auto z=s.upper_bound(mp(mp(x, y), -1));
            auto u=s.upper_bound(mp(mp(y, x), -1));
            if (u!=s.end() && (*u).fi==mp(y, x))
            {
                kl1--;
                if ((*z).se==(*u).se) kl2--;
            }
            s.erase(z);
        }else
        if (c=='?')
        {
            ll k;
            cin >> k;
            //cout << kl1 << " " << kl2 << "\n";
            if (k%2==0)
                cout << (kl2?"YES":"NO") << "\n"; else
                cout << (kl1?"YES":"NO") << "\n";
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
4 2
30 40 50 60
30 40
50 60

4 4
25 25 30 50
10 40
20 30
70 100
50 50
*/