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
    unsigned ll n, m;
    cin >> n;
    cin >> m;
    //cout << n << " " << m << "\n";
    vector<pll> v;
    v.pb(mp(0,0));
    v.pb(mp(0,1));
    v.pb(mp(1,0));
    v.pb(mp(1,1));
    for (int i = 0; i <= 80; i++) dp[i][0]=mp(-1,mp(-1,-1)),dp[i][1]=mp(-1,mp(-1,-1));
    dp[0][0]=mp(0,mp(0,0));
    for (int i = 0; i < 70; i++)
    {
        for (int j = 0; j < 2; j++)
            if (dp[i][j].fi!=-1)
            for (int u = 0; u < 4; u++)
            {
                if ((j+(v[u].fi+v[u].se))%2==n%2 && (v[u].fi^v[u].se)==m%2 && dp[i+1][(j+(v[u].fi+v[u].se))/2].fi==-1) dp[i+1][(j+(v[u].fi+v[u].se))/2]=mp(j,mp(v[u].fi,v[u].se));
            }
        n/=2;
        m/=2;
    }
    if (dp[70][0].fi==-1) {cout << -1;exit(0);}
    unsigned ll i=70, j=0, o1=0, o2=0;
    while (i>0)
    {
        o1*=2;
        o2*=2;
        //cout << dp[i][j].se.fi << " " << dp[i][j].se.se << "\n";
        o1+=dp[i][j].se.fi, o2+=dp[i][j].se.se;
        j=dp[i][j].fi;i--;
    }
    if (o1>o2) swap(o1,o2);
    //cout << o1+o2 << "\n" << (o1^o2) << "\n";
    cout << o1 << " " << o2 << "\n";
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