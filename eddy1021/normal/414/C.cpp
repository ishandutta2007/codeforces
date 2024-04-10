#include <vector>
#include <stdio.h>
using namespace std;
#define N 21
#define ll long long
ll getint(){
    ll x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
ll n , a[ 1 << N ] , tmp[ 1 << N ];
ll b[ N ] , c[ N ];
void init(){
    n = getint();
    for( int i = 1 ; i <= ( 1 << n ) ; i ++ )
        a[ i ] = getint();
}
void Merge_sort( ll lyr , ll l , ll r ){
    if( lyr == 0 ) return;
    ll m = ( l + r ) >> 1;
    Merge_sort( lyr - 1 , l , m );
    Merge_sort( lyr - 1 , m + 1 , r );
    ll ltp = l , rtp = m + 1 , tp = l , prel = l , prer = m + 1;
    while( ltp <= m && rtp <= r ){
        if( a[ ltp ] < a[ rtp ] ){
            while( prer <= r && a[ prer ] < a[ ltp ] ) prer ++;
            b[ lyr ] += prer - m - 1;
            tmp[ tp ++ ] = a[ ltp ++ ];
        }else if( a[ ltp ] > a[ rtp ] ){
            while( prel <= m && a[ prel ] < a[ rtp ] ) prel ++;
            c[ lyr ] += prel - l;
            tmp[ tp ++ ] = a[ rtp ++ ];

        }else{
            while( prer <= r && a[ prer ] < a[ ltp ] ) prer ++;
            tmp[ tp ++ ] = a[ ltp ++ ];
            b[ lyr ] += prer - m - 1;
        }
    }
    while( ltp <= m ){
        while( prer <= r && a[ prer ] < a[ ltp ] ) prer ++;
        tmp[ tp ++ ] = a[ ltp ++ ];
        b[ lyr ] += prer - m - 1;
    }
    while( rtp <= r ){
        while( prel <= m && a[ prel ] < a[ rtp ] ) prel ++;
        c[ lyr ] += prel - l;
        tmp[ tp ++ ] = a[ rtp ++ ];
    }
    for( int i = l ; i <= r ; i ++ )
        a[ i ] = tmp[ i ];
}
void process(){
    ll ans = 0; int q , t;
    for( int i = 0 ; i <= n ; i ++ )
        ans += b[ i ];
    q = getint(); while( q -- ){
        t = getint();
        for( int i = 0 ; i <= t ; i ++ ){
            ans = ans - b[ i ] + c[ i ];
            ll swp = b[ i ]; b[ i ] = c[ i ]; c[ i ] = swp;
        }
        printf( "%I64d\n" , ans );
    }
}
int main(){
    init();
    Merge_sort( n , 1 , ( 1 << n ) );
    process();
}