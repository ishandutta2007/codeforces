#include <deque>
#include <vector>
#include <stdio.h>
using namespace std;
#define N 100010
#define ll long long
ll getint(){
    ll x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
deque< vector< ll > > odd , even;
ll n , k , p;
bool can = true;
void init(){
    n = getint(); k = getint();
    p = getint(); p = k - p;
    for( int i = 0 ; i < n ; i ++ ){
        ll tmp = getint();
        vector<ll> tv;
        tv.push_back( tmp );
        if( tmp & 1ll ) odd.push_back( tv );
        else even.push_back( tv );
    }
}
void solve(){
    if( ( ( odd.size() % 2 ) ^ ( p % 2 ) ) || p > odd.size() ){
        can = false; return;
    }
    while( odd.size() > p ){
        vector<ll> tv1 = odd.back(); odd.pop_back();
        vector<ll> tv2 = odd.back(); odd.pop_back();
        tv1.push_back( tv2[ 0 ] );
        even.push_back( tv1 );
    }
    while( even.size() > k ){
        vector<ll> tv1 = even.back(); even.pop_back();
        vector<ll> tv2 = even.back(); even.pop_back();
        for( int i = 0 ; i < tv2.size() ; i ++ )
            tv1.push_back( tv2[ i ] );
        even.push_front( tv1 );
    }
}
void print(){
    if( !can || even.size() + odd.size() < k ){
        puts( "NO" );
    }else{
        puts( "YES" );
        for( int i = 0 , j = k - 1 ; i < k ; i ++ , j -- ){
            if( i < odd.size() && j < even.size() ){
                printf( "%d" , odd[ i ].size() + even[ j ].size() );
                for( int ptr = 0 ; ptr < odd[ i ].size() ; ptr ++ )
                    printf( " %I64d" , odd[ i ][ ptr ] );
                for( int ptr = 0 ; ptr < even[ j ].size() ; ptr ++ )
                    printf( " %I64d" , even[ j ][ ptr ] );
                puts( "" );
            }else if( i < odd.size() ){
                printf( "%d" , odd[ i ].size() );
                for( int ptr = 0 ; ptr < odd[ i ].size() ; ptr ++ )
                    printf( " %I64d" , odd[ i ][ ptr ] );
                puts( "" );
            }else if( j < even.size() ){
                printf( "%d" , even[ j ].size() );
                for( int ptr = 0 ; ptr < even[ j ].size() ; ptr ++ )
                    printf( " %I64d" , even[ j ][ ptr ] );
                puts( "" );
            }
        }
    }
}
int main(){
    init();
    solve();
    print();
}