#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

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
#define sqr(a) ((a)*(a))

using namespace std;

//mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

//const ll md1=1e9+7, md2=998244357, md3=rnd()%(ll)(1e8), p1=31, p2=37, p3=41;

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, l, r, i, j, a[1000001], ans[10001];
string s;
ll tt[1000001];
vector<ll> c[100001], v[3001];

void dfs(ll h)
{
    for (int i = 0; i < c[h].size(); i++)
    {
        dfs(c[h][i]);
        for (int j = 0; j < v[c[h][i]].size(); j++)
        {
            if (v[h].size()==a[h]) v[h].pb(h);
            v[h].pb(v[c[h][i]][j]);
        }
    }
    if (a[h]>v[h].size()) {cout << "NO\n";exit(0);}
    if (a[h]==v[h].size()) v[h].pb(h);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll p=1;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x >> a[i];
        if (x!=0) c[x].pb(i); else p=i;
    }
    dfs(p);
    for (int i = 0; i < v[p].size(); i++) {ans[v[p][i]]=i+1;}
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}