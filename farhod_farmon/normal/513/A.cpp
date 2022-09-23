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
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x-y)*(x-y)+(xx-yy)*(xx-yy) )

using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if( b>=a )cout<<"Second";
    else cout<<"First";
    return 0;
}