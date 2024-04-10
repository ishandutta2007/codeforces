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
int a,b=1,c,d=0,r,f,i,j;

int main()
{
    //fin
    //fout
    cin>>a;
    c=a;
    rep( 1, a ){
        if( d==0 ){
            cout<<b<<" ";
            b++;
            d=1;
        }
        else{
            cout<<c<<" ";
            c--;
            d=0;
        }
    }
    return 0;
}