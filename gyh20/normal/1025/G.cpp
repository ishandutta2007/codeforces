#include<cstdio>
long long pw[502],n,sz[502],ans,M=1e9+7;
int main(){
	scanf("%lld",&n);
	for(int i=pw[0]=1,x;i<=n;++i)pw[i]=2*pw[i-1]%M,scanf("%d",&x),x>0&&++sz[x];
	for(int i=1;i<=n;++i)ans+=pw[sz[i]]-1;
	printf("%lld",(pw[n-1]-1-ans%M+M)%M);
}