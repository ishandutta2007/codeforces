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
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "INPUT.TXT", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define N 100000
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a,b,i,j,k,l,dp[101][10001],dp1[101][10001],ans=99999999,x[101],y[101];
bool used[101];
char c[101][10001];

int main()
{
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            cin>>c[i][j];
            if( !x[i] && c[i][j]=='1' )x[i]=j;
            if( c[i][j]=='1' )y[i]=j;
        }
        if( !x[i] ){
            cout<<"-1";
            return 0;
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=x[i]; j<=b; j++ ){
            if( c[i][j]=='1' )continue;
            dp[i][j]=dp[i][j-1]+1;
        }
        if( x[i]!=1 ){
            dp[i][1]=dp[i][b]+1;
            for( j=2; j<x[i]; j++ )dp[i][j]=dp[i][j-1]+1;
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=y[i]; j>=1; j-- ){
            if( c[i][j]=='1' )continue;
            dp1[i][j]=dp1[i][j+1]+1;
        }
        if( y[i]!=b ){
            dp1[i][b]=dp1[i][1]+1;
            for( j=b-1; j>y[i]; j-- )dp1[i][j]=dp1[i][j+1]+1;
        }
    }
    for( i=1; i<=b; i++ ){
        int cnt=0;
        for( j=1; j<=a; j++ ){
            cnt+=min(dp[j][i],dp1[j][i]);
        }
        ans=min(ans,cnt);
    }
    cout<<ans;
}