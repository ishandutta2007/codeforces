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

ll n, m, k, l, r, pp, mx=-1e18, x, y;
string s;
vector<vector<ll> > a, kl;

int main()
{
    //freopen("loan.in","r",stdin);
    //freopen("loan.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    kl.resize(m+1);
    a.resize(n+1);
    for (int j = 1; j <= m; j++) kl[j].resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        a[i].resize(m+1);
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if ((a[i][j]-j)%m==0)
            {
                ll p=(a[i][j]-j)/m+1;
                if (p<=n)
                {
                    ll y=i-p;
                    if (y<0) y+=n;
                    kl[j][y]++;
                }
            }
        }
    }
    ll ans=0;
    for (int i = 1; i <= m; i++)
    {
        ll mn=n;
        for (int j = 0; j < n; j++)
        {
            mn=min(mn,n-kl[i][j]+j);
        }
        ans+=mn;
    }
    cout << ans;
}