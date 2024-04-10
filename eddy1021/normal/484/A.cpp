#include <bits/stdc++.h>
using namespace std;
#define N 100
typedef long long ll;
ll getint(){
    ll x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
ll t , l , r , lb[ N ] , rb[ N ] , ans , anscnt;
void init(){
    l = getint(); r = getint();
    memset( lb , 0 , sizeof( lb ) );
    memset( rb , 0 , sizeof( rb ) );
    int idx = 0;
    while( l ){
        lb[ idx ] = l % 2;
        idx ++; l >>= 1;
    }
    idx = 0;
    while( r ){
        rb[ idx ] = r % 2;
        idx ++; r >>= 1;
    }
}
void DFS( ll now , ll num , ll cnt , bool flag ){
//    printf( "%I64d %I64d %I64d\n" , now , num , cnt );
    if( now == -1 ){
        if( cnt > anscnt || ( cnt == anscnt && num < ans ) )
            ans = num , anscnt = cnt;
        return;
    }
    if( cnt + now + 1 <= anscnt ) return;
    if( flag ){
        DFS( now - 1 , num , cnt , flag );
        DFS( now - 1 , num + ( 1ll << now ) , cnt + 1 , flag );
    }else if( lb[ now ] < rb[ now ] ){
        DFS( now - 1 , num , cnt , true );
        DFS( now - 1 , num + ( 1ll << now ) , cnt + 1 , flag );
    }else if( lb[ now ] > rb[ now ] ){
        for( ll i = 0 ; i <= rb[ now ] ; i ++ )
            DFS( now - 1 , num + i * ( 1ll << now ) , cnt + i , flag | ( i == 0 && rb[ now ] == 1 ) );
    }else DFS( now - 1 , num + lb[ now ] * ( 1ll << now ) , cnt + lb[ now ] , flag );
}
void solve(){
    anscnt = -1;
    DFS( 60 , 0 , 0 , false );
    printf( "%I64d\n" , ans );
}
int main(){
    t = getint(); while( t -- ){
        init();
        solve();
    }
}