//by tzupengwang
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int n , m ;
vector< ii > v1[ 100005 ] ;
bool vis[ 100005 ] ;
int dis[ 100005 ] ;
int start = 0 , mend ;

void init() {
    scanf( "%d%d" , &n , &m ) ;
    mend = n - 1 ;
    int a , b , c ;
    for ( int i = 0 ; i < m ; i ++ ) {
        scanf( "%d%d%d" , &a , &b , &c ) ;
        v1[ a ].emplace_back( b , c ) ;
        v1[ b ].emplace_back( a , c ) ;
    }
    dis[ start ] = 0 ;
    queue< int > q ;
    q.push( start ) ; vis[ start ] = true ;
    while ( !q.empty() ) {
        int tp = q.front() ; q.pop() ;
        FO( it , v1[ tp ] ) if ( !vis[ it->first ] ) {
            dis[ it->first ] = dis[ tp ] + 1 ;
            vis[ it->first ] = true ;
            q.push( it->first ) ;
        }
    }
}

vector< int > t ;
int nxt[ 100005 ] , ndis[ 100005 ] ;

int step1() {
    memset( vis , false , sizeof vis ) ;
    queue< int > q ;
    vector< int > tt ;
    int mmin = dis[ mend ] ;
    ndis[ mmin ] = 0 ;
    q.push( mend ) ; vis[ mend ] = true ;
    while ( !q.empty() ) {
        int tp = q.front() ; q.pop() ;
        tt.push_back( tp ) ;
        mmin = min( mmin , dis[ tp ] ) ;
        FO( it , v1[ tp ] ) if ( !vis[ it->first ] && it->second == 0 ) {
            ndis[ it->first ] = ndis[ tp ] + 1 ;
            nxt[ it->first ] = tp ;
            vis[ it->first ] = true ;
            q.push( it->first ) ;
        }
    }
    for ( auto x : tt ) if ( dis[ x ] == mmin ) t.push_back( x ) ;
    return mmin ;
}
vector< ii > v2[ 100005 ] ;

void step2( int mdis ) {
    for ( int i = 0 ; i < n ; i ++ ) {
        FO( it , v1[ i ] ) {
            if ( dis[ i ] == dis[ it->first ] + 1 ) {
                v2[ i ].emplace_back( it->first , it->second ) ;
            }
        }
    }

    vector< int > vt[ 2 ] ;
    vt[ 0 ] = t ;
    int nnnnn = 0 ;
    for ( int i = mdis ; i > 0 ; i -- ) {
        vt[ 1 - nnnnn ].clear() ;
        int mmin = 10 ;
        FO( it , vt[ nnnnn ] ) {
            FO( it2 , v2[ *it ] ) {
                mmin = min( mmin , it2->second ) ;
            }
        }
        FO( it , vt[ nnnnn ] ) {
            FO( it2 , v2[ *it ] ) if ( it2->second == mmin ) {
                if ( nxt[ it2->first ] == 0 ) {
                    vt[ 1 - nnnnn ].push_back( it2->first ) ;
                    nxt[ it2->first ] = *it ;
                    ndis[ it2->first ] = ndis[ *it ] + 1 ;
                } else if ( ndis[ it2->first ] > ndis[ *it ] + 1 ) {
                    nxt[ it2->first ] = *it ;
                    ndis[ it2->first ] = ndis[ *it ] + 1 ;
                }
            }
        }
        printf( "%d" , mmin ) ;
        nnnnn = 1 - nnnnn ;
    }
    if ( mdis == 0 ) printf( "0" ) ;
    printf( "\n%d\n" , ndis[ start ] + 1 ) ;
    int nw = start ;
    while ( nw != mend ) {
        printf( "%d " , nw ) ;
        nw = nxt[ nw ] ;
    } printf( "%d\n" , mend ) ;
}

void process() {
    step2( step1() ) ;
}

int main() {
    init() ;
    process() ;
    return 0 ;
}