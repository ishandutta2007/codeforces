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

using namespace std;

const ll MOD=1e9+7;
const ll N=1e6+1;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

const ll md1=1e9+7, md2=998244357, md3=rnd()%(ll)(1e8), p1=31, p2=37, p3=41;

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, ans, TT, l, T, i, j, h;
ll a[1000001], b[1000001];
string s, d;
bool tt[2000001];
ll c[100001], g[1000001];
map<int,int> w;

int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        cin >> n;
        ll p=0, u=0;
        for (int i = 1; i <= n*2; i++) {cin >> a[i];if (a[i]==1) p++; else u++;}
        if (p==u) {cout << "0\n";continue;}
        ll l=0, r=0, ans=2*n;
        map<int,int> w;
        for (int i = n; i > 0; i--)
        {
            if (a[i]==1) l++; else r++;
            if (p-l==u-r) ans=min(n-i+1,ans);
            if (!w[l-r])w[l-r]=n-i+1;
        }
        l=0, r=0;
        //map<int,int> w;
        for (int i = n+1; i <= n*2; i++)
        {
            if (a[i]==1) l++; else r++;
            if (p-l==u-r) ans=min(ans,i-n);
            if (w[p-u-l+r]) ans=min(ans,i-n+w[p-u-l+r]);
        }
        cout << ans << "\n";
    }
    return 0;
}