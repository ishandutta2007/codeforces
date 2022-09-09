#include<cstdio>
typedef long long ll;
const int MAXN = 1000 + 5;
const int MAXA = 1e6;

int isnp[MAXA*2+5],p[MAXA*2+5],pcnt=0;

inline void gao(void)
{
	int maxa=MAXA*2;
	isnp[1]=1;
	for(int i=2; i<=maxa; ++i)
	{
		if(!isnp[i]) p[++pcnt]=i;
		for(int j=1; j<=pcnt; ++j)
		{
			if((ll)p[j]*i > (ll)maxa) break;
			isnp[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}

int a[MAXN];

int main(void)
{
	gao();
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	if(n==1){ printf("1\n%d",a[1]); return 0;}
	
	int cnt=0;
	for(int i=1; i<=n; ++i)
		if(a[i]==1) ++cnt;
	
	int ai=1,aj=0,ans=1;
	bool flag=0;
	for(int i=1; i<n; ++i) if(a[i]!=1)
		for(int j=i+1; j<=n; ++j) if(a[j]!=1)
			if(!isnp[a[i]+a[j]])
			{
				if(ans<2)
				{
					ans=2;
					ai=i; aj=j;
					flag=0;	
				}
				if(!isnp[a[i]+1] && !isnp[a[j]+1] && ans<cnt+2)
				{
					ans=2+cnt;
					ai=i; aj=j;
					flag=1;
				}
			}
	
	for(int i=1; i<=n; ++i)
		if(a[i]!=1 && !isnp[a[i]+1] && ans<cnt+1)
		{
			ans=cnt+1;
			ai=i; aj=0;
			flag=1;
		}
	
	if(ans<cnt)
	{
		ans=cnt;
		ai=aj=0;
		flag=1;
	}
	
	printf("%d\n",ans);
	if(ai) printf("%d ",a[ai]);
	if(aj) printf("%d ",a[aj]);
	if(flag) while(cnt--) printf("1 ");
	return 0;
}