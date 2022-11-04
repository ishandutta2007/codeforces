#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
using namespace std;

const int MAXN = 411 ;

int dp[MAXN][MAXN] = {} ;

vector < int > v ;

map < int , int > ind ;

vector < pair < int , int > > a ;

inline int get(int x , int l , int e)
{
    if(x>e)
        return 0 ;
    if(x+l<=e)
        return l ;
    return e - x;
}



 main()
{
    ios::sync_with_stdio(0);cin.tie(0) ;
    int n ;
    cin >> n ;
    int x , y ;
    for(int i = 0 ; i < n ; i ++ )
    {
        cin >> x >> y ;
        a.pb({x,y});
        v.pb(x);
         v.pb(x+y);
        v.pb(x-y);
    }
    v.pb(-1e9) ;
    v.pb(1e9);
    sort(a.begin(),a.end());
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin()) ;
    int m = v.size() ;
    for(int j = 0  ;j < m ; j ++ )
        ind[v[j]] = j , dp[0][j] = get(a[0].F-a[0].S,a[0].S,v[j]) ;
    for(int i = 1 ; i < n ; i ++ )
    {
        for(int j = 0 ; j < m ; j ++ )
        {
            dp[i][j] = dp[i-1][j] ;
            if(a[i].F-a[i].S>=v[j])
                continue ;

            int x = get(a[i].F,a[i].S,v[j]) ;
            dp[i][j] = max(dp[i][j] , x + dp[i-1][ind[min(v[j],a[i].F)]]) ;
            x = get(a[i].F-a[i].S,a[i].S,v[j]);
            dp[i][j] = max(dp[i][j] , x + dp[i-1][ind[a[i].F-a[i].S]]) ;
            int mn = a[i].F-a[i].S ;
            for(int k = i - 1 ; k > -1 ; k -- )
            {

                if(a[k].F+a[k].S > a[i].F  )
                {
                    if(!k)
                    {
                        if(mn>a[k].F)
                        dp[i][j] = max(dp[i][j] ,dp[k-1][ind[a[k].F]] + get(a[k].F,a[k].S,v[j]) ) ;
                        else
                            dp[i][j] = max(dp[i][j] , dp[k-1][ind[mn]] + get(mn,a[k].S + a[k].F - mn,v[j]) ) ;
                        continue ;
                    }

                    if(mn>a[k].F)
                        dp[i][j] = max(dp[i][j] ,dp[k-1][ind[a[k].F]] + get(a[k].F,a[k].S,v[j]) ) ;
                    else
                        dp[i][j] = max(dp[i][j] , dp[k-1][ind[mn]] + get(mn,a[k].S + a[k].F - mn,v[j]) ) ;
                }

                mn = min(mn,a[k].F-a[k].S) ;
            }
        }
    }

    cout << dp[n-1][m-1] ;

}