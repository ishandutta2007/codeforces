// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll 
#define INF 1023456789ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
ll getint(){
    ll _x=0,_tmp=1; char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar() , _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
    if( _x == 0 ) return 1ll;
    ll _tmp = mypow( _a , _x / 2 , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
    return _tmp;
}
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
#define N 1010
#define T 110
priority_queue<int> heap[ T ];
int n , t , ans;
void build(){

}
void init(){
    n = getint(); t = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        int ti , qi;
        ti = getint(); qi = getint();
        ans = max( ans , qi );
        heap[ ti ].push( qi );
    }
}
void solve(){
    for( int i = 1 ; i < t ; i ++ ){
        while( heap[ i ].size() > 1 ){
            int tmp1 = heap[ i ].top(); heap[ i ].pop();
            int tmp2 = heap[ i ].top(); heap[ i ].pop();
            int sum = tmp1 + tmp2;
            ans = max( ans , sum );
            heap[ i + 1 ].push( sum );
        }
        while( heap[ i ].size() ){
            int tmp = heap[ i ].top(); heap[ i ].pop();
            heap[ i + 1 ].push( tmp );
        }
    }
    printf( "%d\n" , ans );
}
int main(){
    build();  
    //  __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}