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

int n, m, k, T, a[1501][1501], b[1501];
vector<pii> c[3][1501][3];
bool tt[1500*1500+1];

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

vector<pii> v;

vector<pii> merg(vector<pii> &v1,vector<pii> &v2,int o)
{
    v.clear();
    int l=0, r=0;
    while (!(l==v1.size() && r==v2.size()) && v.size()<m+1)
    {
        if (l==v1.size() || (r<v2.size() && v1[l].se>v2[r].se))
        {
            if (!tt[v2[r].fi]) tt[v2[r].fi]=1, v.pb(mp(v2[r].fi, v2[r].se+o));
            r++;
        }else
        {
            if (!tt[v1[l].fi]) tt[v1[l].fi]=1, v.pb(mp(v1[l].fi, v1[l].se+o));
            l++;
        }
    }
    for (int i = 0; i < v.size(); i++) tt[v[i].fi]=0;
    return v;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }

    vector<pii> y, v;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            c[1][j][0].clear();
            c[1][j][1].clear();
            c[1][j][2].clear();

            c[1][j][1].pb(mp(a[i][j], 1));

            for (int u = 0; u < c[0][j-1][1].size() && c[1][j][1].size()<m+1; u++)
                if (c[0][j-1][1][u].fi!=a[i][j])
                {
                    c[1][j][1].pb(mp(c[0][j-1][1][u].fi, c[0][j-1][1][u].se+1));
                }

            c[1][j][0]=merg(c[1][j-1][0],c[1][j-1][1], 1);

            c[1][j][2]=merg(c[0][j][1],c[0][j][2], 1);

            y=merg(c[1][j][1], c[1][j][2], 0);
            v=merg(c[1][j][0], y, 0);

            ll k=0;

            //cout << i << " " << j << " " << v.size() << "\n";
            //for (int o = 0; o < v.size(); o++) cout << " " << v[o].fi << " " << v[o].se << "\n";

            for (int u = 0; u < min((int)v.size(), m); u++)
            {
                if (u+1==v.size())
                {
                    k=min(i, j);
                }else
                if (v[u+1].se!=v[u].se)
                {
                    k=v[u+1].se-1;
                }
            }
            //cout << k << "\n";
            b[1]++;
            b[min(k, (ll)min(i, j))+1]--;
        }
        swap(c[1], c[0]);
    }
    ll kl=0;
    for (int i = 1; i <= n; i++)
    {
        kl+=b[i];
        cout << kl << "\n";
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
01000000
10100000
31100000
00020000
00000000
00000000
00000000
00000000

01100000
10100000
01100000
00100000
00100000
00100000
13112101
00011111
*/