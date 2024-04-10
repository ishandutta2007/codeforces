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
ll a[1000001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--)
    {
        ll n, d;
        cin >> n >> d;
        ll p=0, x=d;
        while (x)
        {
            p++;
            x/=10;
        }
        if (d!=(ll)pow(10,p)-1) p--;
        cout << p*n << "\n";
    }
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