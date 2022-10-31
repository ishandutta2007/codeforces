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
#define L 200010
string c;
int len;
deque<int> v[ 11 ];
void build(){
    
}
void init(){
    cin >> c;
    len = c.length();
}
bool bad(){
    for( int i = 0 ; i < len ; i ++ )
        if( c[ i ] % 2 == 0 )
            return false;
    return true;
}
void op(){
    for( int i = 0 ; i < len ; i ++ ){
        string ts; bool got = false , got2 = false;
        for( int j = 9 ; j > c[ i ] - '0' ; j -- )
            if( (int)v[ j ].size() > 0 ){
                int tsz = (int)v[ j ].size();
                got = true;
                swap( c[ i ] , c[ v[ j ][ tsz - 1 ] ] );
                ts = c;
                swap( c[ i ] , c[ v[ j ][ tsz - 1 ] ] );
            }
        if( c[ i ] % 2 == 0 && c[ len - 1 ] > c[ i ] ){
            got2 = true;
            swap( c[ i ] , c[ len - 1 ] );
        }
        if( got && got2 ){
            if( ts > c ) c = ts;
            return;
        }else if( got ){
            c = ts;
            return;
        }else if( got2 ) return;
        v[ c[ i ] - '0' ].pop_front();
    }
}
void solve(){
    if( bad() ){
        puts( "-1" );
        return;
    }
    for( int i = 0 ; i < len - 1 ; i ++ )
        v[ c[ i ] - '0' ].PB( i );
    if( c[ len - 1 ] % 2 ){
        int bst = 0;
        for( int i = 0 ; i < len ; i ++ )
            if( c[ i ] % 2 == 0 ){
                bst = i;
                if( c[ len - 1 ] > c[ i ] ) break;   
            }
        swap( c[ bst ] , c[ len - 1 ] );
    }else op();
    cout << c << endl;
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}