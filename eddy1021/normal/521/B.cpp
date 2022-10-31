// eddy1021
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
bool equal( D _x , D _y ){
    return _x > _y - eps && _x < _y + eps;
}
D mypow( D _x , ll _a ){
    if( _a == 0 ) return 1.0;
    D _tmp = mypow( _x , _a / 2 );
    _tmp *= _tmp;
    if( _a & 1ll ) _tmp *= _x;
    return _tmp;
}
ll mypow( ll _x , ll _a , ll _mod ){
    if( _a == 0 ) return 1ll;
    ll _tmp = mypow( _x , _a / 2 , _mod );
    _tmp = ( _tmp * _tmp ) % _mod;
    if( _a & 1ll ) _tmp = ( _tmp * _x ) % _mod;
    return _tmp;
}
int __ = 1 , cs;
/***   default ***/
#define N 100010
map<PII,int> live;
typedef map<PII,int>::iterator si;
set< pair<int,PII> > wait;
int n;
void build(){

}
int under( PII tp ){
    int tx = tp.FI , ty = tp.SE;
    int cnt = 0;
    for( int i = -1 ; i <= 1 ; i ++ )
        if( live.count( MP( tx + i , ty - 1 ) ) && live[ MP( tx + i , ty - 1 ) ] )
            cnt ++;
    return cnt;
}
bool can( PII tp ){
    int tx = tp.FI , ty = tp.SE;
    for( int i = -1 ; i <= 1 ; i ++ )
        if( live.count( MP( tx + i , ty + 1 ) ) && live[ MP( tx + i , ty + 1 ) ] && under( MP( tx + i , ty + 1 ) ) == 1 )
            return false;
    return true;
}
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ ){
        int tx , ty;
        tx = getint(); ty = getint();
        live[ MP( tx , ty ) ] = i + 1;
    }
    for( si it = live.begin() ; it != live.end() ; it ++ )
        if( can( it->first ) )
            wait.insert( MP( it->second , it->first ) );
}
ll add( ll ta , int tnum ){
//    printf( "append %d\n" , tnum );
    ll tans = ( ta * (ll)n ) % mod9;
    tans = ( tans + (ll)tnum ) % mod9;
    return tans;
}
void modify( pair<int,PII> tp ){
    live[ tp.SE ] = 0;
    wait.erase( tp );
    int tx = tp.SE.FI , ty = tp.SE.SE;
    for( int i = -1 ; i <= 1 ; i ++ ){
        PII ttp = MP( tx + i , ty - 1 );
        if( live.count( ttp ) && live[ ttp ] && can( ttp ) )
            wait.insert( MP( live[ ttp ] , ttp ) );
    }
    for( int i = -1 ; i <= 1 ; i ++ ){
        if( i == 0 ) continue;
        PII ttp = MP( tx + i , ty );
        if( live.count( ttp ) && live[ ttp ] && !can( ttp ) && wait.count( MP( live[ ttp ] , ttp ) ) )
            wait.erase( MP( live[ ttp ] , ttp ) );
    }
}
void show(){
    puts( "--" );
    for( set< pair<int,PII> >::iterator it = wait.begin() ; it != wait.end() ; it ++ )
        printf( "%d %d %d\n" , it->FI , it->SE.FI , it->SE.SE );
}
void solve(){
    ll ans = 0;
    for( int i = 0 ; i < n ; i ++ ){
//        show();
        if( i % 2 == 0 ){
            pair<int,PII> tp = *--wait.end();
            if( !can( tp.SE ) ){
                wait.erase( tp );
                i --;
                continue;
            }
            ans = add( ans , tp.FI - 1 );
            modify( tp );
        }else{
            pair<int,PII> tp = *wait.begin();
            if( !can( tp.SE ) ){
                wait.erase( tp );
                i --;
                continue;
            }
            ans = add( ans , tp.FI - 1 );
            modify( tp );
        }
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