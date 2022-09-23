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
int a,x[101],y[101],cnt=0;
char s[1001][1001];
bool b1=false,used[1001][1001];

void dfs( int c, int d )
{
    if( used[c][d] ) return;
    used[c][d]=1;
    for( int i=1; i<=1001; i++ ){
        if( s[i][d]=='x' )dfs(i, d);
        if( s[c][i]=='x' )dfs(c, i);
    }
}

int main()
{
    cin>>a;
    for( int i=1; i<=a; i++ ){
        cin>>x[i]>>y[i];
        s[x[i]][y[i]]='x';
    }
    while( !b1 ){
        b1=true;
        for( int i=1; i<=1000; i++ ) for( int j=1; j<=1000; j++ ) used[i][j]=0;
        dfs(x[1],y[1]);
        for( int i=2; i<=a; i++ ){
            if( used[x[i]][y[i]]==0 ){
                b1=false;
                s[x[1]][y[i]]='x';
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}