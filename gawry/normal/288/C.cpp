#include<cstdio>
const int MAX=1000000+123;
int n,p[MAX];
void go(int n){
//printf("%d\n",n);
	if(n<=0)return;
	int k=0;
	while((1<<k+1)<=n+1)++k;
	int left=n+1-(1<<k);
//	printf("%d %d %d\n",n,1<<k,left);
	if(!left){
		for(int i=0;i<=n;i++){
			int x=i;
			int y=~i&(((1<<k))-1);
			p[x]=y;
			p[y]=x;
	//		printf("%d - %d\n",x,y);
		}
		return;
	}
	for(int i=0;i<left;i++){
		int x=(1<<k)+i;
		int y=~((1<<k)+i)&(((1<<k))-1);
		p[x]=y;
		p[y]=x;
	//	printf("%d - %d\n",x,y);
	}
	go((1<<k)-left-1);
}
main(){
	int n;
	scanf("%d",&n);
	go(n);
	long long ans=0;
	for(int i=0;i<=n;i++)ans+=p[i]^i;
	printf("%I64d\n",ans);
	for(int i=0;i<=n;i++)printf("%d ",p[i]);
	puts("");
}