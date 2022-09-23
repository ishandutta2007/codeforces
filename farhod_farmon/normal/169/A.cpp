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
    int a,b,c,d[2001],i,j,cnt=0;
    cin>>a>>b>>c;
    for( i=1; i<=a; i++ )cin>>d[i];
    sort( d+1, d+a+1 );
    for( i=1; i<=a; i++ ){
        if( i==c ){
            cnt=d[i+1]-d[i];
            break;
        }
    }
    cout<<cnt;
    return 0;
}