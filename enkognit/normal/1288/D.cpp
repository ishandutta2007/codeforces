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
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, l, r, i, j;
ll a[300005][11], tt[1000010];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    ll l=0, r=1e9, p=(1<<m)-1;
    while (l<r)
    {
        ll w=(l+r+1)/2;
        for (int i = 0; i < (1<<m); i++) tt[i]=0;
        bool t=0;
        for (int i = 1; i <= n; i++)
        {
            ll x=0;
            for (int j = 1; j <= m; j++) if (a[i][j]>=w) x^=(1<<(j-1));
            for (int j = 0; j <= p; j++) if ((x&j)==j)tt[j]=i;
            if (tt[p^x]) {t=1;break;}
        }
        if (!t) r=w-1; else l=w;
    }
    //cout << l << "\n";
    pll k=mp(0,0);
    for (int i = 0; i < (1<<m); i++) tt[i]=0;
    for (int i = 1; i <= n; i++)
    {
        ll x=0;
        for (int j = 1; j <= m; j++) if (a[i][j]>=l) x^=(1<<(j-1));
        for (int j = 0; j <= p; j++) if ((x&j)==j) tt[j]=i;
        if (tt[p^x]) {k.se=i,k.fi=tt[p^x];break;}
    }
    cout << k.fi << " " << k.se << "\n";
}
/*
6 5 2
5 1 3 6 2 4
1 3
1 6
3 5
4 5
2 2

3 3 5
1 12 6
1 3
2 3
1 2
*/