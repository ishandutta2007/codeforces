#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
using namespace std;

const int MAXN = 1001 * 101;

pair < int , int > seg [2*MAXN] ;

int n , s , e ;

bool mark [MAXN]  ;


vector < pair < int , int > > adj[MAXN] ;

inline void update(int i, pair < int , int > x , bool f = 1 ){
    if(seg[i+n]>x && f )
        return ;
    for(seg[i += n] = x; i >>= 1; )
        seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
}

inline pair < int , int > get(int l, int r){
    pair < int , int > ans = {-1e9,0};
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
	if(l & 1)  ans=max(ans,seg[l++]);
	if(r & 1)  ans=max(ans,seg[--r]);
    }
    return ans;
}

struct TT{
    int F , S , T ;

};

TT ans = {-1,0,0};

int  sz [MAXN] , ss , tt ;

vector < int > v , v2;

vector < TT > v1 ;

void dfs(int u , int p)
{
    sz[u] = 1 ;
    for(auto vv : adj[u])
        if(vv.F!=p&&!mark[vv.F])
            dfs(vv.F,u) , sz[u] += sz[vv.F] , v.pb(vv.S) ;
}

int a [ MAXN ] , d [ MAXN ] ;

void dfs2(int u , int p , int x )
{
    for(auto v : adj[u])
    {
        if(mark[v.F] || p == v.F)
            continue ;
        d[v.F] = d[u] + 1 ;
        a[v.F] = a[u] + (v.S>=x);
        dfs2(v.F,u,x);
    }
    v1.pb({2*a[u]-d[u],d[u],u});
}


void solve(int x)
{
    v.clear() ;
    dfs(x,0);
    int n = sz[x] , p = -1 ;
    if(sz[x]<s)
        return ;
  //  cout<<'*'<<x<<endl;
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
    v.pb(-1) ;
  //  cout << x << endl ;
    sort(v.begin(),v.end());
    int l = 0 , r = (int)v.size()   ;
    while(r-l>1)
    {
        int mid = (l+r) / 2 ;
        int k = v[mid] ;
        v2.clear() ;
        v2.pb(0);
        update(0,{0,x}) ;
        int f = 0 ;
        for(auto u : adj[x])
        {
            if(mark[u.F])
                continue ;
            v1.clear() ;
          //  cout<<'*'<<u.F<<'\n';
            d[u.F] = 1 ;
            a[u.F] = (u.S>=k);
            dfs2(u.F , x , k ) ;
            for(auto v : v1)
            {
            //    if(k==8&&x==3)cout << v.F <<' '<< v.S << ' ' <<  v.T << '\n';
                if(v.S>e)
                    continue ;
                pair < int , int > x = get(max(0,s-v.S),e-v.S+1) ;
           //     if(k==8)cout << x.F <<' '<<x.S<< '\n';
                if(x.F+v.F>=0)
                    f = 1;
                if(x.F+v.F>=0 && ans.F < k )
                    ans = {k,v.T,x.S} ;
            }
            for(auto u : v1)
            {
                update(u.S,{u.F,u.T});
                v2.pb(u.S);
            }
        }

        if(f)
            l = mid ;
        else
            r = mid ;
        for(auto u : v2 )
            update(u,{-1e9,0},0);
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
    int x , y , z ;
    cin >> n >> s >> e  ;
    for(int i = 1 ; i < n ; i ++ )
    {
        cin >> x >> y >> z ;
        adj[x].pb({y,z});
        adj[y].pb({x,z});
    }
    for(int u = 0 ; u < n ; u ++ )
        update(u,{-1e9,0},0);
    solve(1) ;
    cout << ans.S << ' ' << ans.T << '\n';



}