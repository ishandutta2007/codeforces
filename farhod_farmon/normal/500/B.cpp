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

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "skidesign.in", "r", stdin );
#define fout freopen( "skidesign.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a,b[301],i;
char c[301][301];
vector < int > v[301];
bool used[301];

void dfs( int x )
{
    if( used[x] )return;
    used[x]=true;
    for( int j=0; j<v[x].size(); j++ ){
        c[i][v[x][j]]='1';
        dfs( v[x][j] );
    }
}

int main()
{
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
    }
    for( i=1; i<=a; i++ ){
        for( int j=1; j<=a; j++ ){
            cin>>c[i][j];
            if( c[i][j]=='1' )v[i].pb(j);
        }
    }
    for( i=1; i<=a; i++ ){
        for( int j=1; j<=a; j++ )used[j]=0;
        dfs(i);
    }
    for( i=1; i<=a; i++ ){
        for( int j=1; j<=a; j++ ){
            if( b[i]<b[j] && c[i][j]=='1'  ) swap( b[i], b[j] );
        }
    }
    for( i=1; i<=a; i++ )cout<<b[i]<<" ";
}