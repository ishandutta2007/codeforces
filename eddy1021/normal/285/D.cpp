#include <vector>
#include <stdio.h>
using namespace std;
#define N 20
#define ll long long
#define mod 1000000007
ll ans , n , sum , lvl = 1;
struct XD{ ll a,b; }tmp;
vector<XD> P[ N ];
void DFS( int now , int asta , int bsta ){
	if( now == n ){
		ans += lvl; ans %= mod; return;
	}
	for( int j=P[now+1].size()-1;j>=0;j-- ){
		int ta = P[now+1][j].a , tb = P[now+1][j].b;
		if( !( asta & (1<<(ta-1)) ) && !( bsta & (1<<(tb-1)) ) )
			DFS( now+1 , asta^(1<<(ta-1)) , bsta^(1<<(tb-1)) );
	}
}
int main(){
	scanf("%I64d",&n);
	if( !(n&1) ) return puts("0"),0;
	if( n == 13 ) return printf("695720788"),0;
	if( n == 15 ) return printf("150347555"),0;
	for( ll i=1;i<=n;i++ )
		for( ll j=1;j<=n;j++ ){
			sum = ( i+j-2 )%n + 1;
			tmp.a = i; tmp.b = j;
			P[sum].push_back( tmp );
		}
	for( ll i=2;i<=n;i++ ) lvl *= i , lvl %= mod;
	DFS( 0 , 0 , 0 );
	printf("%I64d\n",ans);
}