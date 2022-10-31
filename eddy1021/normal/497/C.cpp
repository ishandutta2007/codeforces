#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define MP make_pair
#define inf 2000000000
typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
struct XD{
    int a , b , no , cnt;
}va[ N ] , vb[ N ];
bool cmp( XD x , XD y ){
    if( x.a != y.a ) return x.a < y.a;
    return x.b > y.b;
}
int n , m , ans[ N ];
void init(){
    n = getint();
    for( int i = 0 ; i < n ; i ++ ){
        va[ i ].a = getint();
        va[ i ].b = getint();
        va[ i ].no = i;
    }
    sort( va , va + n , cmp );
    m = getint();
    for( int i = 0 ; i < m ; i ++ ){
        vb[ i ].a = getint();
        vb[ i ].b = getint();
        vb[ i ].no = i + 1;
        vb[ i ].cnt = getint();
    }
    sort( vb , vb + m , cmp );
}
multiset< pair< pii , int > > S;
typedef multiset< pair< pii , int > >::iterator si;
void solve(){
    S.insert( MP( MP( -inf , -inf ) , -inf ) );
    S.insert( MP( MP( inf , inf ) , inf ) );
    int midx = 0;
    for( int i = 0 ; i < n ; i ++ ){
        while( midx < m && vb[ midx ].a <= va[ i ].a ){
            S.insert( MP( MP( vb[ midx ].b , vb[ midx ].cnt ) , vb[ midx ].no ) );
            midx ++;
        }
        pair<pii,int> tp = *S.lower_bound( MP( MP( va[ i ].b , -inf ) , -inf ) );
        if( tp.first.first >= inf || tp.first.first < 0 ){
            puts( "NO" );
            return;
        }
        S.erase( S.find( tp ) );
        ans[ va[ i ].no ] = tp.second;
        if( tp.first.second > 1 ){
            tp.first.second --;
            S.insert( tp );
        }
    }
    puts( "YES" );
    for( int i = 0 ; i < n ; i ++ )
        printf( "%d%c" , ans[ i ] , i == n - 1 ? '\n' : ' ' );
}
int main(){
    init();
    solve();
}