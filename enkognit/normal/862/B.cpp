#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimise("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

//#define {a...} make_struct(a...)
#define ll long long
#define fr front()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define ld long double
#define sqr(a) ((a)*(a))

using namespace std;
using namespace __gnu_pbds;

template <typename ENKOGNIT>
using ordered_set = tree<ENKOGNIT, null_type, less<ENKOGNIT>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, O, k, i, j, ans1, ans2, l, r, kl, OO, o;
ll a[500001];ll tt[200001];
vector<ll> c[100001];


void dfs(int h,int k)
{
    tt[h]=k;
    ll p=k+1;
    if (p==3) p=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]])
        dfs(c[h][i],p);
}

int main()
{
    //freopen("bomb.in","r",stdin);
    //freopen("bomb.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1;i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1,1);
    ll p=0;
    for (int i = 1; i <= n; i++)
        a[tt[i]]++;
    cout << a[1]*a[2]-n+1;
    return 0;
}
/*
6 5 2
5 1 3 6 2 4
1 3
1 6
3 5
4 5
2 2

*/