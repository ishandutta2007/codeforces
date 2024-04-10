#include <deque>
#include <stdio.h>
using namespace std;
#define N 200010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , t , c , a[ N ];
void init(){
    n = getint(); t = getint(); c = getint();
    for( int i = 1 ; i <= n ; i ++ )
        a[ i ] = getint();
}
void solve(){
    int ans = 0;
    deque< pair<int,int> > q;
    for( int i = 1 ; i <= c ; i ++ ){
        while( q.size() && q.back().second <= a[ i ] ) q.pop_back();
        q.push_back( make_pair( i , a[ i ] ) );
    }
    if( q.front().second <= t ) ans ++;
    for( int i = c + 1 ; i <= n ; i ++ ){
        while( q.size() && q.front().first <= i - c ) q.pop_front();
        while( q.size() && q.back().second <= a[ i ] ) q.pop_back();
        q.push_back( make_pair( i , a[ i ] ) );
        if( q.front().second <= t ) ans ++;
    }
    printf( "%d\n" , ans );
}
int main(){
    init();
    solve();
}