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

const ll MOD=998244353;

ll n, m, k, sz, a[200005];
pll d[200005][20];
bool tt[200005];

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
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tt[a[i]]^=1;
    }
    for (int i = m; i > 0; i--)
    {
        d[i][0]=mp(0, tt[i]);
        for (int j = 1, u = 2; j < 20; j++, u*=2)
        {
            if (i+u-1>m) break;
            d[i][j].se=d[i][j-1].se+d[i+u/2][j-1].se;
            d[i][j].fi=(d[i][j-1].fi)^(d[i+u/2][j-1].fi)^((u/2)*(d[i+u/2][j-1].se%2));
        }
    }
    /*cout << d[0][1].fi << " " << d[0][1].se << "\n";
    cout << d[1][1].fi << " " << d[1][1].se << "\n";
    cout << d[3][0].fi << " " << d[3][0].se << "\n";
    cout << d[1][2].fi << " " << d[1][2].se << "\n";*/
    ll q;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        ll o=y-x+1, p=0, sm=0;
        for (int j = 19; j > -1; j--)
            if (x+(1<<j)-1<=y)
            {
                //cout << x << " " << j << " " << p << " " << (d[x][j].fi) << " " << (d[x][j].se%2?sm:0) << "\n";
                p=p^(d[x][j].fi)^(d[x][j].se%2?sm:0);
                x+=(1<<j);
                sm+=(1<<j);
            }
        if (p==0) cout << "B"; else cout << "A";
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