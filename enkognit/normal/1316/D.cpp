#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, ans, T, kl[80], b[1001][1001];
pll a[1001][1001];
bool tt[80];

ll binpow(ll h, ll r, ll md = MOD)
{

    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

ll get(int x)
{
    if (x==1) return 'U';
    if (x==2) return 'D';
    if (x==3) return 'L';
    if (x==4) return 'R';
    if (x==5) return 'X';
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j].fi >> a[i][j].se;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!b[i][j])
        {
            if (a[i][j].fi==-1)
            {
                if (a[i-1][j].fi==-1) b[i][j]=1; else
                if (a[i][j-1].fi==-1) b[i][j]=3; else
                if (a[i][j+1].fi==-1) b[i][j]=4; else
                if (a[i+1][j].fi==-1) b[i][j]=2; else {cout << "INVALID\n";exit(0);}
            } else
            if (a[i][j].fi==i && a[i][j].se==j)
            {
                queue<pii > q;
                b[i][j]=5;
                q.push(mp(i,j));
                while (!q.empty())
                {
                    ll x=q.front().fi, y=q.front().se;
                    q.pop();
                    if (a[x-1][y].fi==i && a[x-1][y].se==j && !b[x-1][y]) b[x-1][y]=2, q.push(mp(x-1,y));
                    if (a[x+1][y].fi==i && a[x+1][y].se==j && !b[x+1][y]) b[x+1][y]=1, q.push(mp(x+1,y));
                    if (a[x][y-1].fi==i && a[x][y-1].se==j && !b[x][y-1]) b[x][y-1]=4, q.push(mp(x,y-1));
                    if (a[x][y+1].fi==i && a[x][y+1].se==j && !b[x][y+1]) b[x][y+1]=3, q.push(mp(x,y+1));
                }
            }
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) if (b[i][j]==0) {cout << "INVALID\n";exit(0);}
    cout << "VALID\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << (char)get(b[i][j]);
        cout << "\n";
    }
    return 0;
}
/*
2
3 2
10
01
01
DL
RU
UU
2 4
1111
0101
RDRD
UUUU
*/