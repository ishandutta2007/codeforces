//in the name of god
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define pb push_back
#define F first
#define S second
using namespace std;

const int MAXN = 101 * 1001    ;

int MOD , xx ;


vector < pair < int , int > > adj [ MAXN ] ;

bool mark [ MAXN ] ;

int sz [ MAXN ] ;

int tv [ MAXN ] ;

int po(int x , int y)
{
    if(!y)
        return 1 ;
    int ans = po(x,y/2);
    ans*=ans ;
    ans %= MOD ;
    if(y&1)
        ans*=x;
    return ans % MOD ;
}

int phi(int x)
{
    int ans = x ;
    for(int i = 2 ; i * i <= x ; i ++ )
    {
        if(x%i==0)
        {
            ans/=i;
            ans*=(i-1);
            while(x%i==0)
                x/=i;
        }
    }
    if(x>1)
    {
        ans/=x;
        ans*=(x-1);
    }

    return ans ;
}

void dfs(int u , int p)
{
    sz[u] = 1 ;
    for(auto v : adj[u])
        if(v.F!=p&&!mark[v.F])
            dfs(v.F,u) , sz[u] += sz[v.F] ;
}

int t [ MAXN ] , a [ MAXN ] , b [ MAXN ];

map < int , int > m ;

vector < int > vv  ;

int ans = 0 ;

void dfs2(int u , int p )
{
    vv.pb(u);
    for(auto v : adj[u])
    {
        if(mark[v.F]||v.F==p)
            continue ;
        t[v.F] = t[u] + 1 ;
        a[v.F] = (a[u] + v.S * po(10,t[v.F]-1)) % MOD ;
        b[v.F] = (v.S + 10ll * b[u]) % MOD ;
        dfs2(v.F,u);

      //  m[b[v.F]]++;
    }
}


void solve(int x)
{
  //  cout << x << endl ;
    dfs(x,0);
    int n = sz[x] , p = -1 ;
    while(1)
    {
        int f = 1 , v ;
        for(auto u : adj[x])
            if(!mark[u.F]&&sz[u.F]>n/2&&p!=u.F)
                f= 0 , v = u.F ;
        if(f)
            break ;
        p = x ;
        x = v ;
    }
 //   cout << x << endl ;
    m.clear() ;
    for(auto u : adj[x])
    {
        if(mark[u.F])
            continue ;
        t[u.F] = 1;
        a[u.F] = b[u.F] = u.S % MOD ;

        vv.clear() ;
        dfs2(u.F,x) ;
        for(auto u : vv)
        {
            int k = (MOD - b[u]) % MOD ;
            k *= tv[t[u]];
        //    cout << u << ' ' << m[b[u]]<<endl;
            ans+=m[k%MOD];
        }
        for(auto u : vv)
            m[a[u]]++;

    }
 //   cout << ans << endl;
    m.clear() ;
    reverse(adj[x].begin() , adj[x].end());
    for(auto u : adj[x])
    {
        if(mark[u.F])
            continue ;
        t[u.F] = 1;
        a[u.F] = b[u.F] = u.S % MOD ;
        vv.clear() ;
        dfs2(u.F,x) ;
        for(auto u : vv)
        {
            int k = (MOD - b[u]) % MOD ;
            k *= tv[t[u]];
            ans+=m[k%MOD];
            if(!a[u])
                ans++;
            if(!b[u])
                ans++;
        }
        for(auto u : vv)
            m[a[u]]++;

    }



    mark[x] = 1 ;
    for(auto u : adj[x])
       if(!mark[u.F])
            solve(u.F);

}

int32_t main()
{
    ios::sync_with_stdio(0);
   cin.tie(0);
    int n , x , y , z ;
    cin >> n >> MOD ;
    if(MOD==1)
        return cout << n*(n-1) , 0 ;
    xx = po(10,phi(MOD)-1);
 //   cout << xx << endl ;

    for(int i = 1 ; i < n ; i ++ )
    {
        cin >> x >> y >> z ;
        x++ , y ++ ;
        adj[x].pb({y,z});
        adj[y].pb({x,z});
    }
    tv[0] = 1 ;
    for(int i = 1 ; i < MAXN ; i ++ )
        tv[i] = tv[i-1] * xx % MOD ;
    solve(1);

    cout << ans ;









}