#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T;
bool tt[305][305];
vector<pll> v[2][3];
queue<pll> q;
string s[301];

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    return l;
}

void add(int x,int y)
{
    if (x<1 || y<1 || x>n || y>n || tt[x][y] || (s[x][y]!='X' && s[x][y]!='O')) return;
    tt[x][y]=1;
    v[s[x][y]=='X'][(x+y)%3].pb(mp(x,y));
    q.push(mp(x,y));
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 1; j <= n; j++) tt[i][j]=0;
        s[i]='.'+s[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!tt[i][j] && (s[i][j]=='X' || s[i][j]=='O'))
            {
                v[0][0].clear();
                v[0][1].clear();
                v[0][2].clear();
                v[1][0].clear();
                v[1][1].clear();
                v[1][2].clear();
                //queue<pll> q;
                add(i,j);
                while(!q.empty())
                {
                    ll x=q.front().fi, y=q.front().se;
                    q.pop();
                    //cout << x << " " << y << "\n";
                    add(x-1, y);add(x+1, y);
                    add(x, y+1);add(x, y-1);
                }
                //cout << "---\n";
                ll z1=0, z2=0, mx=1e18;
                for (int u1 = 0; u1 < 3; u1++)
                    for (int u2 = 0; u2 < 3; u2++)
                        if (u1!=u2)
                        {
                            if (v[0][u1].size()+v[1][u2].size()<mx)
                            {
                                mx=v[0][u1].size()+v[1][u2].size();
                                z1=u1;
                                z2=u2;
                            }
                        }
                for (int u = 0; u < v[0][z1].size(); u++)
                {
                    s[v[0][z1][u].fi][v[0][z1][u].se]='X';
                }
                for (int u = 0; u < v[1][z2].size(); u++)
                {
                    s[v[1][z2][u].fi][v[1][z2][u].se]='O';
                }
            }
    for (int i = 1; i <= n; i++)
    {
        s[i].erase(s[i].begin());
        cout << s[i] << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
9 0
1 1
3 1
5 1
5 2
3 2
3 3
2 3
2 2
1 2
*/