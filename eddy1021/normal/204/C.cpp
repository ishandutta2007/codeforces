#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
#define mod9 1000000009
#define mod7 1000000007
#define C 30
#define N 200010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1ll;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n;
ll presum[ C ][ N ] , presum2[ C ][ N ] , precnt[ C ][ N ];
char c1[ N ] , c2[ N ];
D ans;
void init(){
    n = getint();
    scanf( "%s%s" , c1 + 1 , c2 + 1 );
    for( int i = 1 ; i <= n ; i ++ ){
        for( int j = 0 ; j < C ; j ++ )
            presum[ j ][ i ] = presum[ j ][ i - 1 ] ,
            presum2[ j ][ i ] = presum2[ j ][ i - 1 ] ,
            precnt[ j ][ i ] = precnt[ j ][ i - 1 ];
        presum[ c2[ i ] - 'A' ][ i ] += (ll)( i );
        presum2[ c2[ i ] - 'A' ][ i ] += (ll)( n - i + 1 );
        precnt[ c2[ i ] - 'A' ][ i ] ++;
    }
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ ){
        int tc = c1[ i ] - 'A';
        ll lsum = presum[ tc ][ i ] , rsum = presum2[ tc ][ n ] - presum2[ tc ][ i ];
//        ll lcnt = precnt[ tc ][ i ] , rcnt = precnt[ tc ][ n ] - precnt[ tc ][ i ];
        ans += lsum * ( n - i + 1 );
        ans += rsum * i;
//        printf( "%.2f\n" , ans );
    }
    D base = 0.0;
    for( int i = 1 ; i <= n ; i ++ )
        base += (D)i * (D)i;
    printf( "%.20f\n" , ans / base );
}
int main(){
    init();
    solve();
}