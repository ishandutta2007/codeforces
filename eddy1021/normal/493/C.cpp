#include <bits/stdc++.h>
using namespace std;
#define N 400010
int n , ans , maxa , maxb;
vector< pair<int,int> > v;
void init(){
    scanf( "%d" , &n ); maxa = 3 * n;
    for( int i = 0 ; i < n ; i ++ ){
        int td; scanf( "%d" , &td );
        v.push_back( make_pair( td , 1 ) );
    }
    scanf( "%d" , &n ); maxb = 3 * n;
    for( int i = 0 ; i < n ; i ++ ){
        int td; scanf( "%d" , &td );
        v.push_back( make_pair( td , 2 ) );
    }
    sort( v.begin() , v.end() );
    ans = maxa - maxb;
}
void solve(){
    int tmax = ans , tmaxa = maxa , tmaxb = maxb;
    for( int i = 0 ; i < (int)v.size() ;  ){
        int nd = v[ i ].first;
        while( i < (int)v.size() && v[ i ].first == nd ){
            if( v[ i ].second == 1 ) tmaxa --;
            else tmaxb --;
            i ++;
        }
        tmax = tmaxa - tmaxb;
        if( tmax > ans )
            ans = tmax , maxa = tmaxa , maxb = tmaxb;
    }
    printf( "%d:%d\n" , maxa , maxb );
}
int main(){
    init();
    solve();
}