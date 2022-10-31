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
#define eps 1e-7
D a , v , l , d , w , ans;
void build(){
    
}
void init(){
    scanf( "%lf%lf%lf%lf%lf" , &a , &v , &l , &d , &w );
    ans = 1e30;
}
D Ti( D sv , D tv ){
    return abs( sv - tv ) / a;
}
D dist( D sv , D tv ){
    return ( sv + tv ) * Ti( sv , tv ) / 2.0;
}
bool good( D mv ){
    if( mv < w + eps ){
        if( dist( 0 , mv ) > d ) return false;
        return true;
    }
    if( dist( 0 , mv ) + dist( mv , w ) > d ) return false;
    return true;
}
void solve(){
    D ndtime = 0;
    D lv = 0 , rv = v , mid;
    for( int i = 0 ; i < 100 ; i ++ ){
        mid = ( lv + rv ) / 2.0;
        if( good( mid ) ) lv = mid;
        else rv = mid;
    }
    if( lv > w ){
        ndtime = Ti( 0 , lv ) + Ti( lv , w ) + ( ( d - dist( 0 , lv ) - dist( lv , w ) ) / lv );
        lv = w;
    }else ndtime = Ti( 0 , lv ) + ( ( d - dist( 0 , lv ) ) / lv );
    if( dist( lv , v ) < ( l - d ) + eps ){
        ndtime += Ti( lv , v );
    //printf( "%.20f\n" , ndtime );
    //printf( "%.20f %.20f %.20f\n" , ( l - d ) , dist( lv , v ) ,  v );
        ndtime += ( ( l - d ) - dist( lv , v ) ) / v;
    //printf( "%.20f\n" , ndtime );
    }else{
        D tl = lv , r = v , tmid;
        for( int i = 0 ; i < 100 ; i ++ ){
            tmid = ( tl + r ) / 2.0;
            if( dist( lv , tmid ) > ( l - d ) ) r = tmid;
            else tl = tmid;
        }
        ndtime += Ti( lv , tl );
    }
    printf( "%.20f\n" , ndtime );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}