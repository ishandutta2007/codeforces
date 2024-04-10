/*
                                        
                                    
                                    
                                      
                                  
                                
                              
                              
                            
                            
                          
                            
                        
                      
                        
                      
                                
                              
                              
                                
                                    
                              
                                  
                              
                              
                          
                        
                                  
                                      
                                
                                              
                                                  
                                                      
                                              
                                                  
                                                    
                                            
                                            
                                        
                                        
                                  
                                        
                                                
                                                    
                                                  
                                              
*/
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

ll n, m, T, a[501][501];
bool tt[501];

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
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) a[i][j]=0;
    ll ans=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) tt[j]=0;
        for (int j = 1; j <= n; j++)
        {
            ll u=i+j-1;
            if (u>n) u-=n;
            if (k)
            {
                k--;
                a[j][u]=1;
                tt[u]=1;
            }
        }
        if (k==0) break;
    }
    ll mxr=0, mnr=1e18, mxc=0, mnc=1e18;
    for (int i = 1; i <= n; i++)
    {
        ll kl=0;
        for (int j = 1; j <= n; j++)
            kl+=a[i][j];
        mxr=max(mxr, kl);
        mnr=min(mnr, kl);
    }
    for (int i = 1; i <= n; i++)
    {
        ll kl=0;
        for (int j = 1; j <= n; j++)
            kl+=a[j][i];
        mxc=max(mxc, kl);
        mnc=min(mnc, kl);
    }
    ans+=sqr(mxr-mnr)+sqr(mxc-mnc);
    cout << ans << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cout << a[i][j];
        cout << "\n";
    }
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