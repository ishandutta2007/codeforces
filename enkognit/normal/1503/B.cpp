#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, T, m, ans=0, a[100001];
string s, d1, d2;

void solve()
{
    cin >> n;
    vector<pll> v1, v2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ((i+j)%2) v1.pb(mp(i, j)); else v2.pb(mp(i, j));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            ll q;
            cin >> q;
            if (q==1)
            {
                if (v2.size())
                {
                    cout << "2 " << v2.back().fi << " " << v2.back().se << "\n";
                    v2.pop_back();
                }else
                {
                    cout << "3 " << v1.back().fi << " " << v1.back().se << "\n";
                    v1.pop_back();
                }
            }else
            if (q==2)
            {
                if (v1.size())
                {
                    cout << "1 " << v1.back().fi << " " << v1.back().se << "\n";
                    v1.pop_back();
                }else
                {
                    cout << "3 " << v2.back().fi << " " << v2.back().se << "\n";
                    v2.pop_back();
                }
            }else
            if (q==3)
            {
                if (v1.size())
                {
                    cout << "1 " << v1.back().fi << " " << v1.back().se << "\n";
                    v1.pop_back();
                }else
                {
                    cout << "2 " << v2.back().fi << " " << v2.back().se << "\n";
                    v2.pop_back();
                }
            }
        }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*

*/