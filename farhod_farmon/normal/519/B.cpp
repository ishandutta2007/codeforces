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
    int a,b[100001]={},c[100001]={},d[100001]={},x,y,i;
    cin>>a;
    for( i=1; i<=a; i++ )cin>>b[i];
    for( i=1; i<=a-1; i++ )cin>>c[i];
    for( i=1; i<=a-2; i++ )cin>>d[i];
    sort( b+1, b+a+1 );
    sort( c+1, c+a );
    sort( d+1, d+a-1 );
    for( i=1; i<=a; i++ ){
        if( b[i]!=c[i] ){
            x=b[i];
            break;
        }
    }
    for( i=1; i<a; i++ ){
        if( c[i]!=d[i] ){
            y=c[i];
            break;
        }
    }
    cout<<x<<"\n"<<y<<"\n";
    return 0;
}