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
map<int,string> M;
void init(){
    n = getint();
    M[ 0 ] = "zero";
    M[ 10 ] = "ten";	 	 
    M[ 1 ] = "one";
    M[ 11 ]	= "eleven";	 	 
    M[ 2 ] = "two";
    M[ 12 ] = "twelve";
    M[ 20 ] = "twenty";
    M[ 3 ] = "three";
    M[ 13 ] = "thirteen";
    M[ 30 ] = "thirty";
    M[ 4 ] = "four";
    M[ 14 ] = "fourteen";
    M[ 40 ] = "forty";
    M[ 5 ] = "five";
    M[ 15 ] = "fifteen";
    M[ 50 ] = "fifty";
    M[ 6 ] = "six";
    M[ 16 ] = "sixteen";
    M[ 60 ] = "sixty";
    M[ 7 ] = "seven";
    M[ 17 ] = "seventeen";
    M[ 70 ] = "seventy";
    M[ 8 ] = "eight";
    M[ 18 ] = "eighteen";
    M[ 80 ] = "eighty";
    M[ 9 ] = "nine";
    M[ 19 ] = "nineteen";
    M[ 90 ] = "ninety";
}
string ans( int x ){
    if( M.count( x ) ) return M[ x ];
    int tmp1 = ( x / 10 ) * 10; x %= 10;
    return M[ tmp1 ] + "-" + M[ x ];
}
void solve(){
    cout << ans( n ) << endl;
}
int main(){
    init();
    solve();
}