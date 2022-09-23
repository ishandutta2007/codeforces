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
    //fin
    //fout
    vector < int > v,v1;
    int a,c[400],b[400],i,j;
    cin>>a;
    for( i=1; i<=a; i++ )cin>>b[i];
    for( i=1; i<=a; i++ )cin>>c[i];
    for( i=1; i<=a; i++ ){
        for( j=i; j<=a; j++ ){
            if( b[i]==c[j] ){
                break;
            }
        }
        for( int h=j; h>i; h-- ){
            v.pb(h-1);
            v1.pb(h);
            swap( c[h], c[h-1] );
        }
    }
    cout<<v.size()<<endl;
    for( i=0; i<v.size(); i++ )cout<<v[i]<<" "<<v1[i]<<endl;
    return 0;
}