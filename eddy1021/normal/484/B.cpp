#include <bits/stdc++.h>
using namespace std;
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , ans;
vector<int> v;
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ )
        v.push_back( getint() );
    sort( v.begin() , v.end() );
    vector<int>::iterator it = unique( v.begin() , v.end() );
    v.resize( distance( v.begin() , it ) );
}
int BS( int st , int pvt ){
    int l = st , r = n - 1 , m , a = -1;
    while( l <= r ){
        m = ( l + r ) >> 1;
        if( v[ m ] < pvt ) a = m , l = m + 1;
        else r = m - 1;
    }
    return a;
}
void solve(){
    n = (int)v.size();
    for( int i = 0 ; i < n ; i ++ )
        for( int j = v[ i ] ; j <= v[ n - 1 ] + v[ i ] ; j += v[ i ] ){
            int idx = BS( i , j );
            if( idx != -1 ){
                if( v[ idx ] % v[ i ] > ans )
                    ans = v[ idx ] % v[ i ];
            }
        }
    printf( "%d\n" , ans );
}
int main(){
    init();
    solve();
}