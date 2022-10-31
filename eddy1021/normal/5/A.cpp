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
#define N 1010
char c[ N ] , c2[ N ] , c3[ N ];
set<string> S;
void build(){

}
void init(){
    int ans = 0;
    while( gets( c ) ){
        if( sscanf( c , "+%s" , c2 ) == 1 ){
            string stmp;
            for( int i = 0 ; c2[ i ] ; i ++ ) stmp += c2[ i ];
            S.insert( stmp );
        }else if( sscanf( c , "-%s" , c2 ) == 1 ){
            string stmp;
            for( int i = 0 ; c2[ i ] ; i ++ ) stmp += c2[ i ];
            S.erase( stmp );
        }else{
            int len = strlen( c );
            for( int i = 0 ; i < len ; i ++ )
                if( c[ i ] == ':' ){
                    len -= ( i + 1 );
                    break;
                }
            ans += (int)S.size() * len;
        }
    }
    printf( "%d\n" , ans );
}
void solve(){

}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}