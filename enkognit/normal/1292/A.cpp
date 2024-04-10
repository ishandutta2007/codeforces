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

ll n, m, k, l, r, x, y, i, j, X, Y, a[1000001][2], kl[1000001], ans=1e18;
string s;

int main()
{
    //freopen("loan.in","r",stdin);
    //freopen("loan.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> n >> q;
    ll kol=0;
    for (int i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (a[y][x]==0)
        {
            a[y][x]=1;
            ll o=1;
            if (x==1) o=2;
            if (a[y][o]==1) kol++;
            if (a[y-1][o]==1) kol++;
            if (a[y+1][o]==1) kol++;
        }else
        {
            a[y][x]=0;
            ll o=1;
            if (x==1) o=2;
            if (a[y][o]==1) kol--;
            if (a[y-1][o]==1) kol--;
            if (a[y+1][o]==1) kol--;
        }
        if (kol) cout << "No\n"; else cout << "Yes\n";
    }
}