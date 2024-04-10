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
    int a,b[200002],c[200002],i,j,max1=0,max2=0,sum=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i]>>c[i];
        sum+=b[i];
        if( c[i]>=max1 ){
            max2=max1;
            max1=c[i];
        }
        else if( c[i]>=max2 )max2=c[i];
    }
    for( i=1; i<=a; i++ ){
        if( max1==c[i] )cout<<(sum-b[i])*max2<<" ";
        else cout<<(sum-b[i])*max1<<" ";
    }
}