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

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, l, r, T, i, j, h, a[N];
string s, d;

int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--)
    {
        ll x, y, j=0;
        cin >> x;
        y=x;
        while (y)
        {
            y/=10;
            j++;
        }
        ll ans=(j-1)*9;
        for (int i = 1; i <= 9; i++)
        {
            ll o=0;
            for (int u = 0; u < j; u++) o=o*10+i;
            if (o<=x) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}