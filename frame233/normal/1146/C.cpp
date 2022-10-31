#include<cstdio>
int print(int l1,int r1,int l2,int r2)
{
	printf("%d %d ",r1-l1+1,r2-l2+1);
	for(int i=l1;i<=r1;++i) printf("%d ",i);
	for(int i=l2;i<=r2;++i) printf("%d ",i);
	putchar('\n');
	fflush(stdout);
	int tmp;
	scanf("%d",&tmp);
	return tmp;
}
void MAIN()
{
	int n;
	scanf("%d",&n);
	int l=2,r=n;
	int dis=print(1,1,2,n);
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(print(1,1,l,mid)==dis) r=mid;
		else l=mid+1;
	}
	printf("1 %d %d ",n-1,l);
	for(int i=1;i<=n;++i)
	{
		if(i!=l)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
	fflush(stdout);
	scanf("%d",&dis);
	printf("-1 %d\n",dis);
	fflush(stdout);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		MAIN();
	}
	return 0;
}
//DPair AK IOI