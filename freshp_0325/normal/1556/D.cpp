#include<bits/stdc++.h>
using namespace std;
#define F fflush(stdout)
int n,k,sum[10005],a[10005];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=2;i<=n;++i)
	{
		int x,y;
		printf("and 1 %d\n",i),F;
		scanf("%d",&x);
		printf("or 1 %d\n",i),F;
		scanf("%d",&y);
		sum[i]=x+y;
	}
	int u,v;
	printf("and 2 3\n"),F;
	scanf("%d",&u);
	printf("or 2 3\n"),F;
	scanf("%d",&v);
	u+=v;
	a[1]=(sum[2]+sum[3]-u)/2;
	for(int i=2;i<=n;++i)	a[i]=sum[i]-a[1];
	sort(a+1,a+1+n);
	printf("finish %d\n",a[k]),F;
	return 0;
}