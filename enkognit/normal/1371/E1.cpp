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

ll n, m, T, a[500001];
bool tt[500001];

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
    ll p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    vector<ll> v;
    for (int i = 1; i <= a[n]; i++)
    {
        ll l=1, kl=0;
        bool tt=1;
        //cout << i << " : ";
        for (int j = 0; j < n; j++)
        {
            while (l<=n && a[l]<=i+j) l++, kl++;
            if (kl==0) {tt=0;break;}
            if (kl==p) {tt=0;break;}
            //cout << kl << " ";
            kl--;
        }
        //cout << "\n";
        if (tt) v.pb(i);
    }
    cout << v.size() << "\n";
    for (int  i= 0 ;i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
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