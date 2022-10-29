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

ll n, m, k, l, r, i, j, a[1000001], dp[102][102][102][2], b[4];
string s;
ll tt[1000001];
vector<ll> v;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tt[a[i]]++;
        if (a[i]>0) a[i]%=2; else a[i]=-1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int u = 0; u <= n; u++)
                for (int p = 0; p < 2; p++) dp[i][j][u][p]=1e18;
    for (int i = 1; i <= n; i++)
        if (!tt[i]) b[i%2]++;
    //cout << b[0] << " " << b[1] << "\n";
    if (a[1]==-1)
    {
        if (b[0]) dp[1][b[0]-1][b[1]][0]=0;
        if (b[1]) dp[1][b[0]][b[1]-1][1]=0;
    }else
    dp[1][b[0]][b[1]][a[1]]=0;
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= b[0]; j++)
            for (int u = 0; u <= b[1]; u++)
                for (int p = 0; p < 2; p++)
                if (dp[i][j][u][p]!=1e18)
            {
                if (a[i+1]==-1)
                {
                    if (j) dp[i+1][j-1][u][0]=min(dp[i+1][j-1][u][0], dp[i][j][u][p]+(p==1));
                    if (u) dp[i+1][j][u-1][1]=min(dp[i+1][j][u-1][1], dp[i][j][u][p]+(p==0));
                }else
                {
                    dp[i+1][j][u][a[i+1]]=min(dp[i+1][j][u][a[i+1]],dp[i][j][u][p]+(p!=a[i+1]));
                }
            }
    cout << min(dp[n][0][0][1],dp[n][0][0][0]);
}