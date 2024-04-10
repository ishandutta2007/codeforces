#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define N 1010
#define M 2010
#define ll long long
ll getint(){
    ll x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int min( int x , int y ){ return x<y?x:y; }
vector<ll> r[ N ];
priority_queue< pair<ll,ll> > heap;
ll n , m , v[ N ] , ans;
void init(){
    n = getint(); m = getint();
    for( int i = 1 ; i <= n ; i ++ )
        v[ i ] = getint();
    while( m -- ){
        ll a , b;
        a = getint(); b = getint();
        ans += min( v[ a ] , v[ b ] );
    }
}
void solve(){
    printf( "%I64d\n" , ans );
}
int main(){
    init();
    solve();
}