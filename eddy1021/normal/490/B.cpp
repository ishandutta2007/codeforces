#include <bits/stdc++.h>
using namespace std;
#define N 1000010
vector<int> v[ 4 ];
int n , f[ N ] , b[ N ] , fd[ N ] , bd[ N ];
void init(){
    scanf( "%d" , &n );
    for( int i = 0 ; i < n ; i ++ ){
        int s , t;
        scanf( "%d%d" , &s , &t );
        f[ t ] = s;
        b[ s ] = t;
        fd[ t ] ++; bd[ s ] ++;
    }
}
int find_s(){
    for( int i = 1 ; i < N ; i ++ )
        if( !fd[ i ] && bd[ i ] )
            return i;
    return 0;
}
void solve(){
    int st = find_s();
    int st2 = 0;
    for( int i = 0 ; i < n ; i ++ )
        if( !( i & 1 ) ){
            printf( "%d " , st );
            st = b[ st ];
        }else{
            st2 = b[ st2 ];
            printf( "%d " , st2 );
        }
}
int main(){
    init();
    solve();
}