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
template< class T>
T getint( T& _____ ){
    T _=0,___=1; char tc=getchar();
    while( (tc<'0'||tc>'9')&&tc!='-' ) tc=getchar();
    if( tc == '-' ) tc=getchar() , ___ = -1;
    while(tc>='0'&&tc<='9') _*=10,_+=(tc-'0'),tc=getchar();
    return _*___;
}
int __ = 1;
/*********default*********/
#define N 1010
int n , sc[ N ] , msc , midx;
map<string,int> M;
map<int,string> M2;
int nm[ N ] , tsc[ N ] , w[ N ];
void init(){
    n = getint( n );
    for( int i = 0 ; i < n ; i ++ ){
        string ts; int tx;
        cin >> ts; tx = getint( tx );
        if( M.count( ts ) == 0 ){
            M[ ts ] = ++ midx;
            M2[ midx ] = ts;
        }
        nm[ i ] = M[ ts ];
        tsc[ i ] = tx;
        sc[ nm[ i ] ] += tx;
    }
    for( int i = 1 ; i <= midx ; i ++ )
        if( sc[ i ] > msc ) msc = sc[ i ];
    for( int i = 1 ; i <= midx ; i ++ )
        if( sc[ i ] == msc ) w[ i ] = 1;
    memset( sc , 0 , sizeof( sc ) );
}
void solve(){
    for( int i = 0 ; i < n ; i ++ ){
        sc[ nm[ i ] ] += tsc[ i ];
        if( sc[ nm[ i ] ] >= msc && w[ nm[ i ] ] ){
            cout << M2[ nm[ i ] ] << endl;
            return;
        }
    }
}
int main(){
//    __ = getint( __ );
    while( __ -- ){
        init();
        solve();
    }
}