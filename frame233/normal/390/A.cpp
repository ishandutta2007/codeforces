#include<cstdio>
int cnt1[105],cnt2[105];
int main()
{
	int n,x,y,ans1=0,ans2=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&x,&y);
		++cnt1[x],++cnt2[y];
	}
	for(int i=0;i<=100;++i)
	{
		if(cnt1[i]) ++ans1;
		if(cnt2[i]) ++ans2;
	}
	printf("%d\n",ans1<ans2?ans1:ans2);
	return 0;
}
//Dpair ak IOI
//DPair bless me