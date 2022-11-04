#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
using namespace std;

const int MAXN = 5100 ;

vector < int > adj [ MAXN ] ,com [ MAXN ] , radj [ MAXN ];

int col [ MAXN ] = {}  ;

bool mark [ MAXN ] = {} , a [ MAXN ] [ MAXN ] ;

void dfs(int u , int s )
{
    for(auto v : adj[u])
    {
        if(!a[s][v])
            a[s][v] = 1 , dfs(v,s);
    }
}

int dis [ MAXN] = {} , rdis [ MAXN ] = {} ;

int bfs(int s )
{
    fill(dis,dis+MAXN,1e9) ;
    dis[s] = 0 ;
    queue < int >  q ;
    q.push(s);
    while(q.size())
    {
        int x = q.front();
        q.pop();
        for(auto u : adj[x])
        {
            if(dis[u] > dis[x]+1)
                dis[u] = dis[x]+1 , q.push(u);
        }
    }

    int ans = 1e9 ;

    for(auto u : radj[s])
        ans = min(ans,1+dis[u]);
 //   cout << s << ' ' << ans << '\n';
    return ans ;
}


 main()
{
    ios::sync_with_stdio(0);cin.tie(0) ;

    int n , m ;
    int x , y ;

    cin >> n >> m ;
    for(int i = 0 ; i < m ; i ++ )
    {
        cin >> x >> y ;
        adj[x].pb(y);
        radj[y].pb(x);
    }
    for(int i = 1 ; i <= n ; i ++ )
        a[i][i] = 1 , dfs(i,i);
    x = 1 ;
    for(int i = 1 ; i <= n ; i ++ )
    {
        if(!col[i])
        {
            for(int j = 1 ; j <= n ; j ++ )
                if(a[i][j]&&a[j][i])
                    col[j] = x , com[x].pb(j);
            x++;

        }
      //  cout << i << ' ' << col[i]<<'\n';
    }
    int ans = n ;
    for(int i = 1 ; i < x ; i ++ )
    {
        bool f = 0 ;
        for(auto u : com[i] )
            for(auto v : adj[u])
                if(col[v]!=i)
                    f = 1 ;
        if(f||(int)com[i].size()==1)
            continue ;
       // cout << i << endl ;
        ans ++ ;
        int x = 1e9  ;
        for(auto u : com[i])
            x = min(x,bfs(u));
        ans += 998 * x ;
    }
    cout << ans ;


}