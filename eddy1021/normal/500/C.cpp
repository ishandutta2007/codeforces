#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
#define N 510
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
TYPE t = 1 , n , m , w[ N ] , ans;
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        w[ i ] = getint();
}
vector<int> v;
void insert( int idx ){
    int tv = (int)v.size() , presum = 0;
    for( int i = tv - 1 ; i >= 0 ; i -- )
        if( v[ i ] == idx ){
            ans += presum;
            v.erase( v.begin() + i );
            v.push_back( idx );
            return;
        }else presum += w[ v[ i ] ];
    ans += presum;
    v.push_back( idx );
}
void solve(){
    while( m -- ){
        int now = getint();
        insert( now );
    }
    printf( "%d\n" , ans );
}
int main(){
//    t = getint();
    while( t -- ){
        init();
        solve();
    }
}