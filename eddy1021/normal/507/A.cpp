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
#define N 10010
int n , k;
PII a[ N ];
vector<int> ans;
void build(){
    
}
void init(){
    n = getint(); k = getint();
    for( int i = 0 ; i < n ; i ++ ){
        a[ i ].FI = getint();
        a[ i ].SE = i + 1;
    }
    sort( a , a + n );
}
void solve(){
    for( int i = 0 ; i < n ; i ++ )
        if( a[ i ].FI <= k ){
            ans.PB( a[ i ].SE );
            k -= a[ i ].FI;
        }else break;
    printf( "%d\n" , (int)ans.size() );
    for( int i = 0 ; i < (int)ans.size() ; i ++ )
        printf( "%d " , ans[ i ] );
    puts( "" );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}