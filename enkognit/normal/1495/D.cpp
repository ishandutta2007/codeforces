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

const ll MOD=998244353;

ll n, m, k, T, a[500][500], b[500], len=0;
vector<ll> c[500], v[500];
bool tt[500];
ll d[500][500];

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
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }

    for (int s = 1; s <= n; s++)
    {
        for (int i = 1; i <= n; i++) d[s][i]=-1;
        queue<ll> q;
        d[s][s]=0;
        q.push(s);
        //v[s].pb(s);
        while (!q.empty())
        {
            ll x=q.front();
            q.pop();
            //v[s].pb(x);
            for (int i = 0; i < c[x].size(); i++)
                if (d[s][c[x][i]]==-1)
                {
                    q.push(c[x][i]);
                    d[s][c[x][i]]=d[s][x]+1;
                }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i>j)
            {
                a[i][j]=a[j][i];
                continue;
            }
            len=0;
            ll z=j, o=d[i][j];
            while (o)
            {
                int kl=0, p=0;
                for (int u = 0; u < c[z].size(); u++)
                    if (d[i][c[z][u]]+1==d[i][z]) kl++, p=c[z][u];
                len++;
                b[len]=z;
                if (kl>1)
                {
                    break;
                }
                z=p;
                o--;
            }
            //cout << i << " " << j << " " << o << "\n";
            if (o)
            {
                a[i][j]=0;
                continue;
            }
            for (int u = 1; u <= n; u++) tt[u]=0;
            len++;
            b[len]=i;
            for (int u = 1; u <= len; u++)
            {
                tt[b[u]]=1;
            }
            a[i][j]=1;
            for (int u = 1; u <= n; u++)
                if (!tt[u])
                {
                    ll kl=0;
                    for (int z = 0; z < c[u].size(); z++)
                        if (d[i][u]-d[i][c[u][z]]==1 && d[j][u]-d[j][c[u][z]]==1) kl++;
                    a[i][j]=(a[i][j]*kl)%MOD;
                    //cout << " " << u << " " << kl << "\n";
                }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
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