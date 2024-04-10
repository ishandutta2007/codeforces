#include <bits/stdc++.h>
using namespace std;
#define N 10010
#define D double
#define ll long long
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
vector< pair<int,int> > v;
int t , n , m , a[ N ];
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ ){
        int x , y;
        x = getint(); y = getint();
        v.push_back( make_pair( x , y ) );
    }
    sort( v.begin() , v.end() );
}
void solve(){
    int pre;
    pre = min( v[ 0 ].first , v[ 0 ].second );
    for( int i = 1 ; i < n ; i ++ )
        if( min( v[ i ].first , v[ i ].second ) >= pre )
            pre = min( v[ i ].first , v[ i ].second );
        else pre = max( v[ i ].first , v[ i ].second );
    printf( "%d\n" , pre );
}
int main(){
    init();
    solve();
}