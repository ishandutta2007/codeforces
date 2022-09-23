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
int main()
{
    int x1,x2,x3,x4,a,b,c[1001],d[1001],cnt=0,cnt1=0,i,j;
    cin>>x1>>x2>>x3>>x4>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>c[i];
        cnt+=min( c[i]*x1, x2 );
    }
    cnt=min( cnt, x3 );
    for( i=1; i<=b; i++ ){
        cin>>d[i];
        cnt1+=min( d[i]*x1, x2 );
    }
    cnt1=min( cnt1, x3 );
    cout<<min( cnt+cnt1, x4 );
}