#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, T;
ll a[10000001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h;
        h *= h;
        //h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

#define dies_from_cringe exit(0)

void solve()
{
    ll k;
    cin >> n >> k;
    if (k==0)
    {
        ll o=0, ans=0, j=0;
        while (o<n)
        {
            ll p=min(n-o,9ll);
            o+=p;
            ans+=p*binpow(10,j);
            j++;
        }
        cout << ans << "\n";
        return;
    }
    if (n==k*(k+1)/2) {cout << "0\n";return;}
    ll ans=1e18;
    for (int i = 0; i < 10; i++)
    {
        ll q=9;
        //cout << i << ": \n";
        ll u=i, y=max(k+1-(10-i),0ll), o=i;
        if (y==0)
        {
            if (n-k*(k+1)/2>=0 && (n-k*(k+1)/2)%(k+1)==0)
            {
                ll N=(n-k*(k+1)/2)/(k+1);
                ll w=i, z=i, j=0;
                while (w<N)
                {
                    j++;
                    ll p=min(9ll, N-w);
                    z+=binpow(10,j)*p;
                    w+=p;
                }
                if (w==N) ans=min(ans, z);
            }
        }else
        for (int j = 0; j < 18; j++)
        {
            //cout << " " << j << " " << u << " " << o << " " << q << "\n";
            if (n-k*(k+1)/2+q*y>=0 && (n-k*(k+1)/2+q*y)%(k+1)==0)
            {
                ll N=(n-k*(k+1)/2+q*y)/(k+1);
                //system("pause");
                if (o>N) break;
                ll w=o, z=u, l=j+1;
                while (w<N)
                {
                    ll p=min(N-w,9ll-(l==j+1));
                    z+=binpow(10,l)*p;
                    w+=p;
                    l++;
                }
                if (w==N) ans=min(ans, z);
                //cout << "  " << w << " " << z << "\n";
            }
            u+=binpow(10,j+1)*9, o+=9;
            q+=9;
            //cout << q << "\n";
        }
    }
    if (ans==1e18) cout << "-1\n"; else cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

/*
3
4 2
1 1
1 0
3 2
2 2

3 1
1 1
1 0
3 2

3 2
1 1
1 0
3 2
*/