#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;
const ll N=1e6+1;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

const ll md1=1e9+7, md2=998244357, md3=rnd()%(ll)(1e8), p1=31, p2=37, p3=41;

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, ans, TT, l, T, i, j, h, num=1;
ll kol[1000001];
bool tt[2000001];
pll a[1000001];
vector <ll> c[1000001];
map<int,int> w;

/*void dfs(ll h,ll p=-1)
{
    kol[h]=1;
    for (int i = 0 ;i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i],h);
            kol[h]+=kol[c[h][i]];
        }
}*/

void dfs(ll h,ll p=-1)
{
    //cout << h << "\n";
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            a[c[h][i]].fi=num;
            num++;
        }
    a[h].se=num;
    num++;
    for (int i = c[h].size()-1; i > -1; i--)
        if (c[h][i]!=p)
        {
            dfs(c[h][i],h);
        }
}

int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    //dfs2(1);
    num=2;
    a[1].fi=1;
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << a[i].fi << " " << a[i].se << "\n";
    //exit(0);
    return 0;
}