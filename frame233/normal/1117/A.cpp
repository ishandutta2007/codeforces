#include<cstdio>
#include<algorithm>
int a[100005];
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
inline int abs(int a){return a>0?a:-a;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline void swap(int &a,int &b){int tmp=a;a=b,b=tmp;}
int main()
{
	int n,maxx=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
	}
	int ans=0,now=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==maxx)
		{
			if(now&&a[i-1]==a[i]) ++now;
			else if(!now) ++now;
			ans=max(ans,now);
		}
		else
		{
			now=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}