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

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

const ll md1=1e9+7, md2=998244357, md3=rnd()%(ll)(1e8), p1=31, p2=37, p3=41;

//template <typename T>
//using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, l, r, x, y, i, j, a[200001];pair<ll,pll> dp[1000001][2];
string s;

int main()
{
    //freopen("input7.txt","r",stdin);
    //freopen("output7.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll sx=0, sy=0, ans=0;
    vector<ll> vx, vy;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        ans+=x*x*(n-1)+y*y*(n-1);
        sx+=x;
        sy+=y;
        vx.pb(x);
        vy.pb(y);
    }
    for (int i = 0; i < vx.size(); i++) ans-=vx[i]*(sx-vx[i]);
    for (int i = 0; i < vy.size(); i++) ans-=vy[i]*(sy-vy[i]);
    cout << ans << "\n";
}
/*
6 7
1 2 a
2 3 b
3 4 a
4 5 a
5 6 b
6 1 a
4 6 b
*/