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
#define rep( a, b ) for( int i=a; i<=b; i++ )
#define tochniy_rep( a, b ) for( int i=min( a, b ); i<=max( a, b ); i++ )
#define fin freopen( "prefrev.txt", "r", stdin );
#define fout freopen( "prefrev.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x-y)*(x-y)+(xx-yy)*(xx-yy) )

using namespace std;
int main()
{
    int a,b,i,k,x=0,y=9999;
    string s,t;
    cin>>a>>b;
    for( i=1; i<=b; i++ ){
        cin>>s>>s>>t>>s>>k;
        if( t=="left" )y=min(y,k);
        else x=max(x,k);
    }
    if( x>y && x!=0 && y!=9999 || y==1 || x==a || abs(x-y)==1 )cout<<-1;
    else if( x==0 )cout<<min(a,y-1);
    else if( y==9999 )cout<<min(a,abs(a-x));
    else cout<<min(a,abs(x-y)-1);
    return 0;
}