#include <bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
ll getint(){
    ll x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar(); 
    return x;
}
ll n , r , avg , got , ans;
pair<ll,ll> a[ N ];
void init(){
    n = getint(); r = getint(); avg = getint();
    for( int i = 0 ; i < n ; i ++ ){
        a[ i ].second = getint();
        a[ i ].first = getint();
        got += a[ i ].second;
    }
    sort( a , a + n ); avg *= n;
}
void solve(){
    ll ptr = 0;
    while( got < avg ){
        ll tk = min( avg - got , r - a[ ptr ].second );
        ans += tk * a[ ptr ].first;
        got += tk;
        ptr ++;
    }
    printf( "%I64d\n" , ans );
}
int main(){
    init();
    solve();
}