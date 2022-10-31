#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100010
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
map<int,ll> M , pre;
typedef map<int,ll>::iterator mi;
int n , a[ N ];
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = getint();
}
void find_ans(){
    M[ a[ 1 ] ] += 1ll;
    pre[ a[ 1 ] ] = 1ll;
    for( int i = 2 ; i <= n ; i ++ ){
        map<int,ll> now;
        for( mi it = pre.begin() ; it != pre.end() ; it ++ ){
            int tgcd = __gcd( it->first , a[ i ] );
            M[ tgcd ] += (ll)it->second;
            now[ tgcd ] += (ll)it->second;
        }
        now[ a[ i ] ] += 1ll;
        M[ a[ i ] ] += 1ll;
        pre = now;
    }
}
void solve(){
    int q , t;
    q = getint(); while( q -- ){
        t = getint();
        if( M.count( t ) ) printf( "%I64d\n" , M[ t ] );
        else puts( "0" );
    }
}
int main(){
    init();
    find_ans();
    solve();
}