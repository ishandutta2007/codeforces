#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF 1023456789
#define FI first
#define SE second
int getint(){
    int x=0,tmp=1; char tc=getchar();
    while( (tc<'0'||tc>'9')&&tc!='-' ) tc=getchar();
    if( tc == '-' ) tc=getchar() , tmp = -1;
    while(tc>='0'&&tc<='9') x*=10,x+=(tc-'0'),tc=getchar();
    return x*tmp;
}
int __ = 1;
/*********default*********/
#define N 200010
int n , a[ N ] , b[ 2 ][ N ];
void init(){
    n = getint();
    for( int i = n - 1 ; i >= 0 ; i -- )
        b[ 0 ][ i ] = getint();
    for( int i = n - 1 ; i >= 0 ; i -- )
        b[ 1 ][ i ] = getint();
}
int lb( int x ){ return x & (-x); }
int BIT[ N ];
void insert( int no , int dlt ){
    while( no <= n ) BIT[ no ] += dlt , no += lb( no );
}
int query( int no ){
    int sum = 0;
    while( no ) sum += BIT[ no ] , no -= lb( no );
    return sum;
}
int find_kth( int tk ){
    int l = 1 , r = n , mid , ta = 1;
    while( l <= r ){
        mid = ( l + r ) >> 1;
        if( query( mid ) >= tk ) r = mid - 1 , ta = mid;
        else l = mid + 1;
    }
    return ta;
}
void pre_solve(){
    for( int j = 0 ; j < 2 ; j ++ ){
        memset( BIT , 0 , sizeof( BIT ) );
        for( int i = n - 1 ; i >= 0 ; i -- ){
            int ta = query( b[ j ][ i ] + 1 );
            a[ i ] += b[ j ][ i ] - ta;
            insert( b[ j ][ i ] + 1 , 1 );
        }
    }
}
void print(){
    for( int i = 0 ; i <= n ; i ++ ) BIT[ i ] = 0;
    for( int i = 1 ; i <= n ; i ++ )
        insert( i , 1 );
    for( int i = n - 1 ; i >= 0 ; i -- ){
        int tx = find_kth( a[ i ] + 1 );
        printf( "%d%c" , tx - 1 , i == 0 ? '\n' : ' ' );
        insert( tx , -1 );
    }
}
void solve(){
    pre_solve();
    for( int i = 0 ; i < n ; i ++ ){
        a[ i + 1 ] += a[ i ] / ( i + 1 );
        a[ i ] %= ( i + 1 );
    }
    print();
}
int main(){
//    __ = getint( __ );
    while( __ -- ){
        init();
        solve();
    }
}