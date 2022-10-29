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

ll n, dd, m, k, T, ans=1, jj, a[200005];
bool tt[200005];
vector<ll> v;
bool tl[18000];
set<pii > s[18000], f[18000];

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

void solve()
{
    ll q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ll p=sqrt(a[i]), x=a[i];
        //cout << p << "\n";
        for (int j = 2; j <= p; j++)
            if (x%j==0)
            {
                //cout << " " << j << " " << x << "-\n";
                ll o=0;
                while (x%j==0) x/=j, o++;

                {
                    ll z=lower_bound(all(v), j)-v.begin();

                    {
                        s[z].insert(mp(o, i));
                        f[z].insert(mp(i, o));
                    }

                    if (s[z].size()==n)
                    {
                        ans=(ans*binpow(j,(*s[z].begin()).fi,MOD))%MOD;
                    }
                }
            }
        if (x>1)
        {
            ll j=x, o=1;
                {
                    ll z=lower_bound(all(v), j)-v.begin();
                    //cout << z << " " << o << "\n";
                    {
                        s[z].insert(mp(o, i));
                        f[z].insert(mp(i, o));
                    }
                    //cout << s[z].size() << "\n";

                    if (s[z].size()==n)
                    {
                        ans=(ans*binpow(j,(*s[z].begin()).fi,MOD))%MOD;
                    }
                }
        }
    }
    //cout << ans << "\n";
    //cout << "---\n";
    while (q--)
    {
        ll i, x;
        cin >> i >> x;

        ll p=sqrt(x);
        for (int j = 2; j <= p; j++)
            if (x%j==0)
            {
                ll o=0;
                while (x%j==0) x/=j, o++;

                {
                    ll z=lower_bound(all(v), j)-v.begin();
                    if (s[z].size()==n)
                    {
                        ans=(ans*binpow(binpow(j,(*s[z].begin()).fi,MOD),MOD-2,MOD))%MOD;
                    }
                    auto u=f[z].upper_bound(mp(i, 0));

                    if (u!=f[z].end() && (*u).fi==i)
                    {
                        pll q=*u;
                        swap(q.fi,q.se);
                        s[z].erase(q);
                        q.fi+=o;
                        s[z].insert(q);

                        f[z].erase(u);
                        swap(q.fi,q.se);
                        f[z].insert(q);
                    }else
                    {
                        s[z].insert(mp(o, i));
                        f[z].insert(mp(i, o));
                    }

                    if (s[z].size()==n)
                    {
                        ans=(ans*binpow(j,(*s[z].begin()).fi,MOD))%MOD;
                    }
                }
            }
        if (x>1)
        {
            ll j=x, o=1;
                {
                    ll z=lower_bound(all(v), j)-v.begin();
                    if (s[z].size()==n)
                    {
                        ans=(ans*binpow(binpow(j,(*s[z].begin()).fi,MOD),MOD-2,MOD))%MOD;
                    }
                    auto u=f[z].upper_bound(mp(i, 0));

                    if (u!=f[z].end() && (*u).fi==i)
                    {
                        pll q=*u;
                        swap(q.fi,q.se);
                        s[z].erase(q);
                        q.fi+=o;
                        s[z].insert(q);

                        f[z].erase(u);
                        swap(q.fi,q.se);
                        f[z].insert(q);
                    }else
                    {
                        s[z].insert(mp(o, i));
                        f[z].insert(mp(i, o));
                    }

                    if (s[z].size()==n)
                    {
                        ans=(ans*binpow(j,(*s[z].begin()).fi,MOD))%MOD;
                    }
                }
        }
        //cout << " " << s[1].size() << " " << (*s[1].begin()).fi << "\n";
        cout << ans << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (ll i = 2; i <= 2e5; i++)
        if (!tt[i])
        {
            v.pb(i);
            ll j=i*i;
            while (j<=2e5) tt[j]=1, j+=i;
        }
    //cout << v.size() << "\n";
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