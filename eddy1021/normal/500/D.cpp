#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
#define N 100010
#define mod9 1000000009
#define mod7 1000000007
#define INF 1023456789
TYPE getint(){
    TYPE x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
TYPE t = 1 , n , q;
D par[ N ] , para , ans , cst[ N ];
vector< pair<int,int> > v[ N ];
// des idx
void init(){
    n = getint();
    para = (D)n * (D)( n - 1 ) * (D)( n - 2 ) / 6.0;
    for( int i = 1 ; i < n ; i ++ ){
        int ta , tb , tc;
        ta = getint(); tb = getint(); tc = getint();
        cst[ i ] = (D)tc;
        v[ ta ].push_back( make_pair( tb , i ) );
        v[ tb ].push_back( make_pair( ta , i ) );
    }
}
int DFS( int now , int p ){
    int cnt = 1;
    for( int i = 0 ; i < (int)v[ now ].size() ; i ++ )
        if( v[ now ][ i ].first != p ){
            int tcnt = DFS( v[ now ][ i ].first , now );
            par[ v[ now ][ i ].second ] = (D)( tcnt ) * (D)( n - tcnt );
            ans += par[ v[ now ][ i ].second ] * cst[ v[ now ][ i ].second ];
            cnt += tcnt;
        }
    return cnt;
}
void solve(){
    DFS( 1 , -1 );
    q = getint(); while( q -- ){
        int tno , tc;
        tno = getint(); tc = getint();
        ans -= par[ tno ] * cst[ tno ];
        cst[ tno ] = tc;
        ans += par[ tno ] * cst[ tno ];
        printf( "%.18f\n" , ( ans * ( n - 2 ) ) / para );
    }
}
int main(){
//    t = getint();
    while( t -- ){
        init();
        solve();
    }
}