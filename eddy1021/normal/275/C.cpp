#include <map>
#include <stdio.h>
#include <algorithm>
#define N 100010
#define ll long long
using namespace std;
ll getint(){
	ll x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
map<ll,bool> M; ll n,k,ans,bx[N];
int main(){
	n = getint(); k = getint();
	for( int i=0;i<n;i++ ) bx[i] = getint();
	sort( bx , bx+n );
	for( int i=0;i<n;i++ ) if( !M[bx[i]] ) ans ++, M[ bx[i]*k ] = 1;
	printf("%I64d\n",ans);
}