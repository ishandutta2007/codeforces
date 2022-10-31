// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009
#define mod7 1000000007
#define INF 1023456789
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
#define N 500010
char c[ N ];
int len;
D ans , dp[ N ] , cnt[ N ];
D BIT[ N ];
int lb( int x ){
    return x & (-x);
}
void insert( int no , D dlt ){
    while( no <= len ){
        BIT[ no ] += dlt;
        no += lb( no );
    }
}
D query( int no ){
    D sum = 0;
    while( no ){
        sum += BIT[ no ];
        no -= lb( no );
    }
    return sum;
}
bool vowel( char ctmp ){
    return ctmp == 'I' || ctmp == 'E' ||
            ctmp == 'A' || ctmp == 'O' ||
            ctmp == 'U' || ctmp == 'Y';
}
void build(){
    
}
void init(){
    scanf( "%s" , c + 1 );
    len = strlen( c + 1 );
}
void solve(){
    for( int i = 1 ; i <= len ; i ++ )
        if( vowel( c[ i ] ) ){
            int lft = i , rgt = len - i + 1;
            int tmp = min( lft , rgt );
            ans += (D)tmp;
            int low = tmp + 1 , high = len + 1 - tmp;
            if( low <= high ){
                insert( low , tmp );
                insert( high + 1 , -tmp );
            }
            int st = len + 2 - tmp;
            dp[ st ] += tmp - 1.0;
            cnt[ st ] += 1.0;
        }
    for( int i = 1 ; i <= len ; i ++ ){
        D tsum = query( i );
        ans += tsum / (D)i;
    }
    for( int i = 1 ; i <= len ; i ++ ){
        ans += dp[ i ] / (D)i;
        dp[ i + 1 ] += dp[ i ] - cnt[ i ];
        cnt[ i + 1 ] += cnt[ i ];
    }
    printf( "%.20f\n" , ans );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}