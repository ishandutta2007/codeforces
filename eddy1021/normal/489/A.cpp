#include <bits/stdc++.h>
using namespace std;
#define N 3010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , a[ N ];
vector< pair<int,int> > ans;
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ )
        a[ i ] = getint();
}
void solve(){
    for( int i = 0 ; i < n ; i ++ ){
        int ptr = -1 , tmin = a[ i ];
        for( int j = i + 1 ; j < n ; j ++ )
            if( a[ j ] < tmin )
                tmin = a[ j ] , ptr = j;
        if( ptr != -1 ){
            ans.push_back( make_pair( i , ptr ) );
            swap( a[ i ] , a[ ptr ] );
        }
    }
    printf( "%d\n" , (int)ans.size() );
    for( int i = 0 ; i < (int)ans.size() ; i ++ )
        printf( "%d %d\n" , ans[ i ].first , ans[ i ].second );
}
int main(){
    init();
    solve();
}