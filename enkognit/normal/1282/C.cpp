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

ll n, m, k, l, T, ans, i, j, h, sum1, sum2;
pll a[1000001];
string s, d;

int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while(q--)
    {
        ll n, T, b[2], kl0=0;
        cin >> n >> T >> b[0] >> b[1];
        for (int i = 1; i <= n; i++) {cin >> a[i].se;if (a[i].se==0)kl0++;}
        for (int i = 1; i <= n; i++) cin >> a[i].fi;
        sort(a+1,a+n+1);
        ll tm=0, ans=0, kl=0;
        //cout << "-" << kl0 << "\n";
        for (int i = 1; i <= n; i++)
        {
            if (a[i].se==0)
            {
                kl0--;
                if (tm<a[i].fi) {ans=max(ans,kl);}
            }else
            {
                if (tm<a[i].fi)
                {
                    ll p=min(kl0,max((a[i].fi-tm-1)/b[0],0ll));
                    ans=max(ans,kl+p);
                }
            }
            tm+=b[a[i].se];
            kl++;
        }
        //cout << tm << " " << kl << "\n";
        if (tm<=T) ans=max(ans,kl);
        cout << ans << "\n";
    }
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