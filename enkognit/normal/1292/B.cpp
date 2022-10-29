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
#define all(a) a.begin(),a.end()

using namespace std;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

const ll md1=1e9+7, md2=998244357, md3=rnd()%(ll)(1e8), p1=31, p2=37, p3=41;

//template <typename T>
//using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, l, r, x, y, i, j, X, Y, a[1000001][2], kl[1000001], ans=0, p=1e17;
string s;
vector<pll> v;
bool tt[100001];
ll x0, y0, ax, ay, bx, by, xs, ys, t;

int main()
{
    //freopen("loan.in","r",stdin);
    //freopen("loan.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    v.pb(mp(x0,y0));
    while (1)
    {
        if (p/ax<=x0 || p/ay<=y0) break;
        x0=x0*ax+bx;
        y0=y0*ay+by;
        v.pb(mp(x0,y0));
    }
    n=v.size();
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            //cout << i << " " << j << " " << min(abs(xs-v[i].fi)+abs(ys-v[i].se),abs(xs-v[j].fi)+abs(ys-v[j].se))+abs(v[i].fi-v[j].fi)+abs(v[i].se-v[j].se) << "\n";
            if (min(abs(xs-v[i].fi)+abs(ys-v[i].se),abs(xs-v[j].fi)+abs(ys-v[j].se))+abs(v[i].fi-v[j].fi)+abs(v[i].se-v[j].se)<=t) ans=max((int)ans,j-i+1);
        }
    cout << ans;
}