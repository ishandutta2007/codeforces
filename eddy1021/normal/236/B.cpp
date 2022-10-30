#include <stdio.h>
#define maxN 1000001
#define mod 1073741824
#define FOR(i,j,k) for( int i=j;i<=k;i++ )
int cnt[maxN],a,b,c,ans;
void build(){
	FOR(i,2,maxN-1){
		for( int j=i;j<maxN;j+=i ) cnt[j]++;
	}
}
int main(){
	build(); scanf("%d%d%d",&a,&b,&c);
	FOR(i,1,a) FOR(j,1,b) FOR(k,1,c) ans+=(cnt[i*j*k]+1),ans%=mod;
	printf("%d\n",ans);
}