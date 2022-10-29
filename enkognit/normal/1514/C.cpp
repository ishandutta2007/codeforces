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

ll n, m, k, sz, a[200005];
vector<pll> c[200005];
vector<ll> v[200005];
ll tt[200005];
bool tl[200005];

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
    cin >> n;
    ll sm=1;
    vector<int> v;
    for (int i = 1; i < n; i++)
        if (__gcd((ll)i,n)==1)
        {
            v.pb(i);
            sm=(sm*i)%n;
        }

    if (sm==1) sm--;
    cout << v.size()-(sm!=0) << "\n";
    for (int i = 0; i < v.size(); i++)
        if (v[i]!=sm) cout << v[i] << " ";
    cout << "\n";
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
4 5
1 2 1
2 3 1
3 4 3
4 1 1
1 3 8
*/