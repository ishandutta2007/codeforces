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
lli a,b,ans=999999999;
bool used[11111][11111];

void rec( lli x, lli y )
{
    if( x<1 || x>10000 || used[x][y] || y>10000 )return;
    if( x==b ){
        ans=min(ans, y);
    }
    used[x][y]=1;
    rec( x-1, y+1 );
    rec( x*2, y+1 );
}

int main()
{
    cin>>a>>b;
    rec(a, 0);
    cout<<ans;
}