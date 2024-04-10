#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
#define N 30010
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
bool can[ N ];
TYPE t = 1 , n , m , a;
void init(){
    can[ 1 ] = true;
    n = getint(); m = getint();
    for( int i = 1 ; i < n ; i ++ ){
        int ta = getint();
        if( can[ i ] )
            can[ i + ta ] = true;
    }
}
void solve(){
    puts( can[ m ] ? "YES" : "NO" );
}
int main(){
//    t = getint();
    while( t -- ){
        init();
        solve();
    }
}