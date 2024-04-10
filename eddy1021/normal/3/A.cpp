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
int getint(){
    int x=0,tmp=1; char tc=getchar();
    while( (tc<'0'||tc>'9')&&tc!='-' ) tc=getchar();
    if( tc == '-' ) tc=getchar() , tmp = -1;
    while(tc>='0'&&tc<='9') x*=10,x+=(tc-'0'),tc=getchar();
    return x*tmp;
}
int __ = 1;
/*********default*********/
char c[ 2 ][ 4 ];
int x1 , y3 , x2 , y2;
void build(){

}
void init(){
    scanf( "%s%s" , c[ 0 ] , c[ 1 ] );
    x1 = c[ 0 ][ 0 ] - 'a'; y3 = c[ 0 ][ 1 ] - '0';
    x2 = c[ 1 ][ 0 ] - 'a'; y2 = c[ 1 ][ 1 ] - '0';
}
vector<string> ans;
void solve(){
    while( x1 < x2 && y3 < y2 ) ans.push_back( "RU" ) , x1 ++ , y3 ++;
    while( x1 < x2 && y3 > y2 ) ans.push_back( "RD" ) , x1 ++ , y3 --;
    while( x1 > x2 && y3 < y2 ) ans.push_back( "LU" ) , x1 -- , y3 ++;
    while( x1 > x2 && y3 > y2 ) ans.push_back( "LD" ) , x1 -- , y3 --;
    while( x1 < x2 ) ans.push_back( "R" ) , x1 ++;
    while( x1 > x2 ) ans.push_back( "L" ) , x1 --;
    while( y3 < y2 ) ans.push_back( "U" ) , y3 ++;
    while( y3 > y2 ) ans.push_back( "D" ) , y3 --;
    printf( "%d\n" , (int)ans.size() );
    for( int i = 0 ; i < (int)ans.size() ; i ++ )
        cout << ans[ i ] << endl;
} 
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}