#include<cstdio>
#include<cstring>
const int N=5005;
int l[N],r[N];
int d[N],sum[N];
inline int max(int a,int b){return a>b?a:b;}
int main()
{
	int n,q,ans=0;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=q;++i) scanf("%d %d",&l[i],&r[i]);
	for(int i=1;i<=q;++i)
	{
		memset(d,0,sizeof(d));
		for(int j=1;j<=q;++j)
		{
			if(i!=j)
			{
				++d[l[j]],--d[r[j]+1];
			}
		}
		int s=0,tot=0;
		for(int j=1;j<=5000;++j)
		{
			s+=d[j];
			if(s) ++tot;
			sum[j]=sum[j-1]+(s==1);
		}
		for(int j=i+1;j<=q;++j)
		{
			ans=max(ans,tot-sum[r[j]]+sum[l[j]-1]);
		}
	}
	printf("%d\n",ans);
	return 0;
}