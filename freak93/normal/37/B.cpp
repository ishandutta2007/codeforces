#include<cstdio>

using namespace std;

int i,d[1005],n,h,r,c,t,a[1005],ans[2005][2],rez,maxt,poz;

int main()
{
	scanf("%d%d%d",&n,&h,&r);
	for(i=1;i<=n;++i)
		scanf("%d%d",&a[i],&d[i]);

	c=h;
	while(c>0)
	{
		++t;
		maxt=-1;
        for(i=1;i<=n;++i)
			if(c*100<=a[i]*h)
				if(d[i]>maxt)
					maxt=d[i],poz=i;
		if(maxt==-1&&r>=0)
		{
			printf("NO");
			return 0;
		}
		if(maxt==-1)
		{
			c+=r;
			continue;
		}
		r-=maxt;
		a[poz]=-1;
		ans[++rez][0]=t-1;
		ans[rez][1]=poz;
		c+=r;
		if(c>h)
			c=h;
	}
	printf("YES\n");
	printf("%d %d\n",t,rez);
	for(i=1;i<=rez;++i)
		printf("%d %d\n",ans[i][0],ans[i][1]);
}