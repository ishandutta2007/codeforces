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
int n , cnt;
map<int,int> ans;
void DFS( int now , int sum , int bs , bool flag ){
    if( now < 1 ){
        ans[ sum ] = cnt ++;
        return;
    }
    if( flag ) DFS( now - 1 , sum , bs / 10 , 1 );
    DFS( now - 1 , sum + 4 * bs , bs / 10 , 0 );
    DFS( now - 1 , sum + 7 * bs , bs / 10 , 0 );
}
void build(){
    DFS( 9 , 0 , 100000000 , 1 );
}
void init(){
    n = getint();
}
void solve(){
    printf( "%d\n" , ans[ n ] );
}
int main(){
    build();
    init();
    solve();
}