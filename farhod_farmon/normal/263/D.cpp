#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define REP(x,y) for( x=1; x<=y; x++ )
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int n,m,k,h;
bool used[100001];
vector <int> v[100001],ans;

void dfs( int x )
{
    if( used[x] )return;
    if( ans.size()>=k ){
        for( int i=0; i<v[x].size(); i++ ){
            if( v[x][i]==h ){
                cout<<ans.size()+1<<endl;
                for( int i=0; i<ans.size(); i++ )cout<<ans[i]<<" ";
                cout<<x;
                exit(0);
            }
        }
    }
    used[x]=1;
    ans.pb(x);
    for( int i=0; i<v[x].size(); i++ )dfs(v[x][i]);
    ans.p_b();
}

int main()
{
    int x,y;
    cin>>n>>m>>k;
    for( int i=1; i<=m; i++ ){
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for( h=1; h<=n; h++ ){
        for( int j=1; j<=n; j++ )used[j]=0;
        dfs(h);
    }
    return 0;
}