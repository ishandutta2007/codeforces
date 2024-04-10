#include<stdio.h>
#define N 100005
main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int c[N];
	long long int sum=0;
	for(int i=1;i<=n;i++)
	scanf("%d",&c[i]),sum+=c[i];
	long long int ans=0;
	for(int i=2;i<=n;i++)
	ans+=c[i]*c[i-1];
	ans+=c[n]*c[1];
	for(int i=0;i<k;i++){
		int a;
		scanf("%d",&a);
		ans+=c[a]*(sum-(a==n?c[1]:c[a+1])-c[a]-(a==1?c[n]:c[a-1]));
		sum-=c[a];
		c[a]=0;
	}
	printf("%I64d\n",ans);
}