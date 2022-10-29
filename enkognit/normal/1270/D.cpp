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
#define sqr(a) ((a)*(a))

using namespace std;

const ll MOD=1e9+7;
const ll N=1e6+1;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

const ll md1=1e9+7, md2=998244357, md3=rnd()%(ll)(1e8), p1=31, p2=37, p3=41;

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, l, T, ans, i, j, h, a[1000001], b[1010101], TT;
vector <ll> v;
string s, d;
ll tt[1000001];

string get_mask(ll h)
{
    ll x=h;
    string s;
    while (x)
    {
        s+=(char)(x%2+'0');
        x/=2;
    }
    return s;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> k;
    cout << "? ";
    for (int i = 1; i <= n; i++) {a[i]=-1;}
    for (int i = 1; i <= k; i++) cout << i << " ";
    cout << "\n";
    ll x1, y1;
    cin >> x1 >> y1;
    fflush(stdout);
    a[x1]=y1;
    cout << "? ";
    for (int i = 1; i <= k+1; i++) if (a[i]==-1)cout << i << " ";
    cout << "\n";
    ll x2, y2;
    fflush(stdout);
    cin >> x2 >> y2;
    a[x2]=y2;
    if (a[x1]>a[x2]) swap(x1,x2), swap(y1,y2);
    ll o=0;
    for (int i = 1; i <= k+1; i++)
        if (a[i]==-1)
        {
            cout << "? ";
            for (int j = 1; j <= k+1; j++) if (i!=j) cout << j << " ";
            cout << "\n";
            fflush(stdout);
            ll x, y;
            cin >> x >> y;
            if (y==y2) tt[i]=-1, o++; else tt[i]=1;
        }
    cout << "! " <<  o+1 << "\n";
    return 0;
}
/*
3
0 0 2
8 10 3
16 0 3

2
0 0 1
6 0 1

*/