// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
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
#define N 110
int n , m;
vector<int> atk , def;
vector<int> v;
multiset<int> s;
typedef multiset<int>::iterator mi;
void build(){

}
void init(){
    n = getint(); m = getint();
    for( int i = 0 ; i < n ; i ++ ){
        char tmp[ 5 ]; int x;
        scanf( "%s" , tmp ); x = getint();
        if( tmp[ 0 ] == 'A' ) atk.PB( x );
        else def.PB( x );
    }
    sort( atk.begin() , atk.end() );
    sort( def.begin() , def.end() );
    for( int i = 0 ; i < m ; i ++ ){
        int x = getint();
        s.insert( x );
        v.PB( x );
    }
    sort( v.begin() , v.end() );
}
int test( int tmp ){
    int sum = 0;
    for( int i = tmp - 1 , j = (int)v.size() - 1 ; i >= 0 ; i -- , j -- )
        if( v[ j ] >= atk[ i ] )
            sum += v[ j ] - atk[ i ];
    return sum;
}
int cal(){
    int ans1 = 0 , ans2 = 0;
    int tn = min( (int)atk.size() , (int)v.size() );
    for( int i = 1 ; i <= tn ; i ++ )
        ans1 = max( ans1 , test( i ) );
    if( n >= m ) return ans1;
    for( int i = 0 ; i < (int)def.size() ; i ++ ){
        mi it = s.upper_bound( def[ i ] );
        if( it == s.end() ) return ans1;
        s.erase( it );
    }
    while( atk.size() ){
        mi it = s.lower_bound( atk.back() );
        if( it == s.end() ) return ans1;
        ans2 += (*it) - atk.back();
        s.erase( it );
        atk.pop_back();
    }
    for( mi it = s.begin() ; it != s.end() ; it ++ )
        ans2 += *it;
    return max( ans1 , ans2 );
}
void solve(){
    cout << cal() << endl;
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}