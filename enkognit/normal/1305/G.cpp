#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 999999001;
const ll md = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 29, p2 = 17, p3 = 13, md1 = MOD, md2 = md, md3 = 998244353;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, k1, k2, T, K, TT, ans, a[1000001];
pll cc[1000001];
pll bst[1000001];

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x,ll y)
{
    while (x>0 && y>0)
    {
        if (x>y) swap(x, y);
        y%=x;
    }
    return x+y;
}

ll d[1000001];

void make_sets(int h)
{
    for (int i = 0; i <= h; i++) d[i]=i;
}

ll find_set(int h)
{
    if (h==d[h]) return h; else return d[h]=find_set(d[h]);
}

bool unite_sets(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    if (x==y) return 0; else
        {d[x]=y;return 1;}
}

void solve()
{
    cin >> n;
    ll ans=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans-=a[i];
    }
    a[n+1]=-1;
    ll kol=n+1;
    make_sets(n+1);
    vector<pll> v;
    while (kol>1)
    {
        for (int i = 0; i < (1<<18); i++) bst[i]=mp(n+1, n+1);
        for (int i = 0; i <= n; i++)
        {
            ll o=i;
            if (bst[a[i]].fi==n+1) bst[a[i]].fi=i; else
            if (bst[a[i]].se==n+1 && find_set(bst[a[i]].fi)!=find_set(i)) bst[a[i]].se=i;
        }
        for (int i = 0; i < (1<<18); i++)
            for (int j = 0; j < 18; j++)
                if ((1<<j)&i)
                {
                    //if (i==3)
                    pll o=mp(n+1, n+1);
                    if (a[bst[i].fi]<a[bst[i^(1<<j)].fi])
                    {
                        o.fi=bst[i^(1<<j)].fi;
                        if (find_set(bst[i].fi)==find_set(bst[i^(1<<j)].fi))
                        {
                            if (a[bst[i].se]>a[bst[i^(1<<j)].se]) o.se=bst[i].se; else o.se=bst[i^(1<<j)].se;
                        }else
                        {
                            if (a[bst[i].fi]>a[bst[i^(1<<j)].se]) o.se=bst[i].fi; else o.se=bst[i^(1<<j)].se;
                        }
                    }else
                    {
                        o.fi=bst[i].fi;
                        if (find_set(bst[i].fi)==find_set(bst[i^(1<<j)].fi))
                        {
                            if (a[bst[i].se]>a[bst[i^(1<<j)].se]) o.se=bst[i].se; else o.se=bst[i^(1<<j)].se;
                        }else
                        {
                            if (a[bst[i^(1<<j)].fi]>a[bst[i].se]) o.se=bst[i^(1<<j)].fi; else o.se=bst[i].se;
                        }
                    }
                    bst[i]=o;
                    if (find_set(o.fi)==find_set(o.se) && o.fi!=n+1 && o.se!=n+1)
                    {
                        cout << "---" << i << " " << o.fi << " " << o.se << " " << find_set(o.fi) << "\n";
                        exit(0);
                    }
                }
        //cout << bst[3].fi << " " << bst[3].se << "\n";
        for (int i = 0; i <= n+1; i++) cc[i]=mp(-1, n+1);
        for (int i = 0; i <= n; i++)
        {
            ll o1=bst[((1<<18)-1)^a[i]].fi;
            //cout << i << " " << o1 << "\n";
            if (o1==n+1) continue;
            if (find_set(o1)==find_set(i)) o1=bst[((1<<18)-1)^a[i]].se;
            //cout << " - " << o1 << "\n";
            if (o1==n+1) continue;
            if (a[i]&a[o1])
            {
                cout << "!\n";
                exit(0);
            }
            //cout << " ! " << i << " " << o1 << " " << t << "\n";
            if (find_set(i)!=find_set(o1))
            {
                //cout << i << " " << o1 << "\n";
                if (a[i]+a[o1]>cc[find_set(i)].fi) cc[find_set(i)]=mp(a[i]+a[o1], find_set(o1));
            }
        }
        for (int i = 0; i <= n; i++)
        {

            if (find_set(i)==i && cc[i].se!=n+1)
            {
                //cout << i << " " << cc[i].se << "\n";
                if (unite_sets(i, cc[i].se))
                {
                    ans+=cc[i].fi;
                    kol--;
                }
            }
        }
        //cout << kol << "\n";
        //system("pause");
    }
    cout << ans << "\n";

}

int main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
3
1 2 4
1 3 6

6
1 2 4
3 4 3
1 4 10
5 1 2
4 6 5
*/