#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
/*
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-avx2")
*/
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD=1e9+7;
ll md1=MOD, md2=988244353, p1=621983, p2=751921;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

int n, m, k, l, r, ans, a[400001];
vector<int> v[28];

ll gcd(int x,int y)
{
    if (x==0 || y==0) return x+y; else return __gcd(x,y);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j < 28; j++)
        {
            v[j].pb(a[i]%(1<<(ll)j));
        }
    }
    for (int j = 1; j < 28; j++)
    {
        sort(all(v[j]));
        int l, r, w, k=0, lr=0, rr=0;
        for (int i = 0; i < v[j].size()-1; i++)
        {
            lr=0, rr=0;
            l=i+1, r=v[j].size()-1;
            while (l<r)
            {
                w=(l+r)/2;
                if (v[j][i]+v[j][w]>=(1ll<<(j-1))) r=w; else l=w+1;
            }
            lr=l;
            r=v[j].size()-1;
            while (l<r)
            {
                w=(l+r+1)/2;
                if (v[j][i]+v[j][w]<(1ll<<j)) l=w; else r=w-1;
            }
            rr=l;
            k+=max(rr-lr+1-(v[j][i]+v[j][rr]>=(1ll<<j))+(v[j][i]+v[j][lr]<(1ll<<(j-1))),0);

            lr=0, rr=0;

            l=i+1, r=v[j].size()-1;
            while (l<r)
            {
                w=(l+r)/2;
                if (v[j][i]+v[j][w]>=((1ll<<(j))+(1ll<<(j-1)))) r=w; else l=w+1;
            }
            lr=l;
            rr=v[j].size()-1;

            k+=max(rr-lr+1+(v[j][i]+v[j][lr]<((1ll<<(j))+(1ll<<(j-1)))),0);
        }
        //cout << j-1 << " " << k << "\n";
        if (k%2) ans^=(1ll<<(j-1));
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
6 7
1 2
1 3
4 5
4 6
1 4
2 5
3 6

6 9
1 2
2 3
3 1
4 5
4 6
6 5
1 4
2 5
3 6
*/