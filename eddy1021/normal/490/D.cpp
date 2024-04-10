#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map< ll , ll > dp;
map< ll , pair<ll,ll> > dp2;
map< pair<ll,ll> , bool > tag , tag2;
ll a1 , b1 , a2 , b2;
void init(){
    scanf( "%I64d%I64d" , &a1 , &b1 );
    scanf( "%I64d%I64d" , &a2 , &b2 );
}
void DP( ll ta , ll tb , ll stp ){
    if( ta > tb ) swap( ta , tb );
    if( tag.count( make_pair( ta , tb ) ) )
        return;
    tag[ make_pair( ta , tb ) ] = true;
    if( dp.count( ta * tb ) == 0 || 
            ( dp.count( ta * tb ) && stp < dp[ ta * tb ] ) ){
        dp[ ta * tb ] = stp;
        dp2[ ta * tb ] = make_pair( ta , tb );
    }
    if( !( ta % 2 ) ) DP( ta / 2 , tb , stp + 1 );
    if( !( ta % 3 ) ) DP( ( ta / 3 ) * 2 , tb , stp + 1 );
    if( !( tb % 2 ) ) DP( ta , tb / 2 , stp + 1 );
    if( !( tb % 3 ) ) DP( ta , ( tb / 3 ) * 2 , stp + 1 );
}
ll ans , ansa1 , ansb1 , ansa2 , ansb2;
void DP2( ll ta , ll tb , ll stp ){
    if( ta > tb ) swap( ta , tb );
    if( dp.count( ta * tb ) ){
        if( stp + dp[ ta * tb ] < ans ){
            ans = stp + dp[ ta * tb ];
            ansa1 = dp2[ ta * tb ].first;
            ansb1 = dp2[ ta * tb ].second;
            ansa2 = ta;
            ansb2 = tb;
        }
        return;
    }
    if( tag2.count( make_pair( ta , tb ) ) ) return;
    tag2[ make_pair( ta , tb ) ] = true;
    if( stp > ans ) return;
    if( !( ta % 2 ) ) DP2( ta / 2 , tb , stp + 1 );
    if( !( ta % 3 ) ) DP2( ( ta / 3 ) * 2 , tb , stp + 1 );
    if( !( tb % 2 ) ) DP2( ta , tb / 2 , stp + 1 );
    if( !( tb % 3 ) ) DP2( ta , ( tb / 3 ) * 2 , stp + 1 );
}
void solve(){
    DP( a1 , b1 , 0 );
    ans = 1000000000ll;
    DP2( a2 , b2 , 0 );
    if( ans == 1000000000ll ) puts( "-1" );
    else{
        printf( "%I64d\n" , ans );
        printf( "%I64d %I64d\n" , ansa1 , ansb1 );
        printf( "%I64d %I64d\n" , ansa2 , ansb2 );
    }
}
int main(){
    init();
    solve();
}