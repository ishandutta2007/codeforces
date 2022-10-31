// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF 1023456789000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
int getint(){
    int _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 30010
#define K 510
ll n , k , a[ N ];
ll bstu[ N ][ K ];
ll bstd[ N ][ K ];
bool tagu[ N ][ K ];
bool tagd[ N ][ K ];
void build(){

}
void update_u( ll tn , ll tk , ll ta ){
    if( ta > bstu[ tn ][ tk ] ){
        bstu[ tn ][ tk ] = ta;
        tagu[ tn ][ tk ] = true;
    }
}
void update_d( ll tn , ll tk , ll ta ){
    if( ta > bstd[ tn ][ tk ] ){
        bstd[ tn ][ tk ] = ta;
        tagd[ tn ][ tk ] = true;
    }
}
void init(){
    scanf( "%I64d%I64d" , &n , &k );
    for( ll i = 0 ; i <= n ; i ++ )
        for( ll j = 0 ; j <= k ; j ++ )
            bstu[ i ][ j ] = bstd[ i ][ j ] = -INF;
    for( ll i = 1 ; i <= n ; i ++ )
        scanf( "%I64d" , &a[ i ] );
}
ll ans;
void solve(){
    for( ll i = 1 ; i <= n ; i ++ ){
        if( i > 1 ){
            for( ll j = 1 ; j <= k ; j ++ ){
                update_u( i , j , bstu[ i - 1 ][ j ] );
                update_d( i , j , bstd[ i - 1 ][ j ] );
            }
        }
        ll sum = 0;
        for( ll j = i ; j >= 1 ; j -- ){
            sum += a[ j ];
            for( ll tk = 1 ; tk < k ; tk ++ ){
                ll tmpu = -INF , tmpd = -INF , tb;
                if( tagu[ j - 1 ][ tk ] )
                    tmpu = bstu[ j - 1 ][ tk ] - sum;
                if( tagd[ j - 1 ][ tk ] )
                    tmpd = bstd[ j - 1 ][ tk ] + sum;
                tb = max( tmpu , tmpd );
                if( tb == -INF ) continue;
                if( tk + 1 == k ) ans = max( ans , tb );
                update_u( i , tk + 1 , tb + sum );
                update_d( i , tk + 1 , tb - sum );
            }
            update_u( i ,1 , sum );
            update_d( i , 1 , -sum );
        }
        update_u( i , 1 , sum );
        update_d( i , 1 , -sum );
    }
    printf( "%I64d\n" , ans );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}