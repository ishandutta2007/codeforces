#include <bits/stdc++.h>
using namespace std;
#define N 110
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , m , k , a[ N ];
void init(){
    n = getint();
    m = getint();
}
char ch[ N ];
void DFSmin( int now , int s ){
    if( now == n ){
        ch[ now ] = '\0';
        if( s == 0 ){
            printf( "%s " , ch );
//            puts( ch );
        }
        return;
    }
    if( now == 0 && ( n - now - 1 ) * 9 >= s ){
        ch[ now ] = '1';
        DFSmin( now + 1 , s - 1 );
    }else{
        int tmin = s - ( n - now - 1 ) * 9;
        if( tmin < 0 ) tmin = 0;
        ch[ now ] = tmin + '0';
        DFSmin( now + 1 , s - tmin );
    }
}
void DFSmax( int now , int s ){
    if( now == n ){
        ch[ now ] = '\0';
        puts( ch );
        return;
    }
    int tnum = min( s , 9 );
    ch[ now ] = tnum + '0';
    DFSmax( now + 1 , s - tnum );
}
void solve(){
    if( n * 9 < m || ( m == 0 && n != 1 ) ){
        puts( "-1 -1" );
        return;
    }
    if( m == 0 ){
        puts( "0 0" );
        return;
    }
    DFSmin( 0 , m );
    DFSmax( 0 , m );
}
int main(){
    init();
    solve();
}