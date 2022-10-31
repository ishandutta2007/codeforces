#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
#define N 510
#define mod9 1000000009ll
#define mod7 1000000007ll
#define P 33000
ll getint(){
    ll x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
ll t , n , pt;
bool p[ P ];
vector<ll> pset , cnt;
ll ans;
map<ll,ll> M;
typedef map<ll,ll>::iterator mi;
ll mypow( ll a , ll x ){
    if( x == 0 ) return 1ll;
    ll tmp = mypow( a , x / 2 );
    tmp = ( tmp * tmp ) % mod7;
    if( x & 1 ) tmp = ( tmp * a ) % mod7;
    return tmp;
}
void build(){
    for( ll i = 2 ; i < P ; i ++ ) if( !p[ i ] ){
        pset.push_back( i );
        cnt.push_back( 0ll );
        for( ll j = P / i ; j >= i ; j -- )
            p[ i * j ] = true;
    }
    pt = (ll)pset.size();
}
void init(){
    ans = 1ll;
    n = getint();
}
void cal( ll tmp ){
    for( ll i = 0 ; i < pt && pset[ i ] <= tmp ; i ++ )
        while( !( tmp % pset[ i ] ) ){
            cnt[ i ] ++;
            tmp /= pset[ i ];
        }
    if( tmp != 1ll ) M[ tmp ] ++;
//    if( tmp != 1 ) ans = ( ans * (ll)n ) % mod7;
}
// H(a,b) = C(a+b-1,b)
ll C( ll ta , ll tb ){
    ll tans = 1;
    for( ll i = 1 , j = ta ; i <= tb ; i ++ , j -- ){
        tans = ( tans * j ) % mod7;
        tans = ( tans * mypow( i , mod7 - 2ll ) ) % mod7;
    }
    return tans;
}
void solve(){
    for( ll i = 1 ; i <= n ; i ++ ){
        ll ai = getint();
        cal( ai );
    }
    for( ll i = 0 ; i < pt ; i ++ )
        if( cnt[ i ] > 0 )
            ans = ( ans * C( (ll)n + (ll)cnt[ i ] - 1ll , (ll)cnt[ i ] ) ) % mod7;
    for( mi it = M.begin() ; it != M.end() ; it ++ )
        ans = ( ans * C( (ll)n + ((ll)it->second) - 1ll , (ll)(it->second) ) ) % mod7;
    printf( "%I64d\n" , ans );
}
int main(){
    build();
    init();
    solve();
}