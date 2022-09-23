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
#define fin freopen( "ride.txt", "r", stdin );
#define fout freopen( "ride.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x-y)*(x-y)+(xx-yy)*(xx-yy) )

using namespace std;
int main()
{
    double x[1001],y[1001];
    int a,i,j,cnt=0;
    bool b[1001]={};
    cin>>a;
    for( i=0; i<=a; i++ )cin>>x[i]>>y[i];
    for( i=1; i<=a; i++ ){
        double c=x[i]-x[0],d=y[i]-y[0];
        if( b[i]==1 )continue;
        b[i]=1;
        cnt++;
        for( j=i; j<=a; j++ ){
            double c1=x[j]-x[0],d1=y[j]-y[0];
            if( c1*d==d1*c ){
                b[j]=1;
            }
        }
    }
    cout<<cnt;
    return 0;
}