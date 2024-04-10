#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
#define mod9 1000000009
#define mod7 1000000007
#define N 100010
ll getint(){
    ll x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
ll x1 , y1 , x2 , y2 , n , ans;
void init(){
    x1 = getint(); y1 = getint();
    x2 = getint(); y2 = getint();
    n = getint();
}
void solve(){
    while( n -- ){
        ll ta , tb , tc;
        ta = getint(); tb = getint(); tc = getint();
        ll v1 , v2;
        v1 = ta * x1 + tb * y1 + tc;
        v2 = ta * x2 + tb * y2 + tc;
        if( ( v1 > 0 ) ^ ( v2 > 0 ) )
            ans ++;
    }
    printf( "%I64d\n" , ans );
}
int main(){
    init();
    solve();
}