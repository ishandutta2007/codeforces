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
#define eps 1e-10
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
    if( _x == 0 ) return 1;
    ll _tmp = mypow( _a , _x / 2 , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
    return _tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
/*********default*********/
int n;
int bs[ 10 ] , tn[ 10 ];
vector<int> ans;
void init(){
    tn[ 0 ] = 1;
    for( int i = 1 ; i < 8 ; i ++ )
        tn[ i ] = tn[ i - 1 ] * 10;
    n = getint();
    int tmp = n;
    for( int i = 0 ; i < 8 && tmp ; i ++ ){
        bs[ i ] = tmp % 10;
        tmp /= 10;
    }
}
void reduce(){
    int gt = 0;
    for( int i = 0 ; i < 8 ; i ++ )
        if( bs[ i ] ){
            bs[ i ] --;
            gt += tn[ i ];
        }
    ans.PB( gt );
    n -= gt;
}
void solve(){
    while( n ) reduce();
    printf( "%d\n" , (int)ans.size() );
    for( int i = 0 ; i < (int)ans.size() ; i ++ )
        printf( "%d " , ans[ i ] );
    puts( "" );
}
int main(){
    init();
    solve();
}