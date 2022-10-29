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

int n, m, T;
int a[100001];
vector<pair<vector<int>, pii> > v;
int kl[350][100001];

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

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> vv;
    v.pb(mp(vv,mp(1,0)));
    T=0;
    ll p=sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i/p!=(i-1)/p)
        {
            v.pb(mp(vv,mp(i,i)));
            T++;
        }
        kl[T][a[i]]++;
        v[T].se.se=i;
        v[T].fi.pb(a[i]);
    }
    for (int i = 0; i < v.size(); i++) reverse(all(v[i].fi));
    /*cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << " " << i << " " << v[i].se.fi << " " << v[i].se.se << " " << v[i].fi.size() << " " << (ll)v[i].fi.size()-1-((ll)v[i].se.se-(ll)v[i].se.fi+1) << " : ";
        for (int j = (ll)v[i].fi.size()-1; j > (ll)v[i].fi.size()-1-((ll)v[i].se.se-(ll)v[i].se.fi+1); j--) cout << v[i].fi[j] << " ";
        cout << "\n";
    }
    cout << "\n";*/
    ll q;
    cin >> q;
    ll lst=0;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t==1)
        {
            ll x, y;
            cin >> x >> y;
            x=(x+lst-1)%n+1;
            y=(y+lst-1)%n+1;
            if (x>y) swap(x,y);
            //cout << " " << x << " " << y << "\n";
            ll z=y/p, u=x/p, w=v[z].fi[(ll)v[z].fi.size()-1-(y-v[z].se.fi)];
            kl[z][w]--;
            //cout << z << " " << u << "\n";
            v[z].fi.erase(v[z].fi.end()-1-(ll)(y-v[z].se.fi));
            kl[u][w]++;
            //cout << "      " << v[u].fi.size() << " " << w << "\n";
            //if (v[u].fi.size()==0) v[u].fi.pb(w); else
            v[u].fi.insert(v[u].fi.end()-(ll)(x-v[u].se.fi), w);
            //for (int i = 0; i < v[u].fi.size(); i++) cout << v[u].fi[i] << " ";
            for (int i = u; i < z; i++)
            {
                ll o=v[i].fi[(ll)v[i].fi.size()-1-(v[i].se.se-v[i].se.fi+1)];
                kl[i][o]--;
                v[i+1].fi.pb(o);
                kl[i+1][o]++;
                if (v[i].fi.size()>2*p)
                {
                    reverse(all(v[i].fi));
                    while (v[i].fi.size()>v[i].se.se-v[i].se.fi+1) v[i].fi.pop_back();
                    reverse(all(v[i].fi));
                }
            }
        }else
        {
            ll x, y, k;
            cin >> x >> y >> k;
            x=(x+lst-1)%n+1;
            y=(y+lst-1)%n+1;
            if (x>y) swap(x,y);
            k=(k+lst-1)%n+1;
            ll z=x/p, u=y/p, ans=0;
            //cout << " " << x << " " << y << " " << k << " " << z << " " << u << " " << v[z].se.fi << " " << v[u].se.se << "\n";
            if (z==u)
            {
                for (int i = (ll)v[z].fi.size()-1-(x-(ll)v[z].se.fi); i >= (ll)v[z].fi.size()-1-(y-(ll)v[z].se.fi); i--)
                {
                    //cout << "  " << i << " " << v[z].fi[i] <<  "\n";
                    ans+=(v[z].fi[i]==k);
                }
            }else
            {
                for (int i = (ll)v[z].fi.size()-1-(x-v[z].se.fi); i > (ll)v[z].fi.size()-1-(v[z].se.se-v[z].se.fi+1); i--)
                    ans+=(v[z].fi[i]==k);
                for (int i = (ll)v[u].fi.size()-1-(y-v[u].se.fi); i < (ll)v[u].fi.size(); i++)
                    ans+=(v[u].fi[i]==k);
            }
            z++;u--;
            for (int i = z; i <= u; i++) ans+=kl[i][k];
            cout << ans << "\n";
            lst=ans;
        }
        /*for (int i = 0; i < v.size(); i++)
        {
            //cout << " " << i << " : ";
            for (int j = (ll)v[i].fi.size()-1; j > (ll)v[i].fi.size()-1-((ll)v[i].se.se-(ll)v[i].se.fi+1); j--) cout << v[i].fi[j] << " ";
            //cout << "\n";
        }
        cout << "\n";*/
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