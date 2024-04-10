#include<cstdio>
#include<algorithm>
#define INF 1000000000
using namespace std;
int t,n,minn[15],maxn[15],a[200005];
bool check(int x,int y)
{
	for(int i=x;i<=y;i++)
	{
		if(maxn[i]!=0) return true;
	}
	return false;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<=9;i++)
		{
			minn[i]=INF;
			maxn[i]=0;
		}
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			char temp;
			scanf(" %c",&temp);
			a[i]=temp-'0';
			minn[a[i]]=min(minn[a[i]],i);
			maxn[a[i]]=max(maxn[a[i]],i);
		}
//		for(int i=0;i<=9;i++)
//		{
//			printf("%d %d\n",minn[i],maxn[i]);
//		}
		int now1=0,now2=n+1,l=0,r=9,tmp=-1;
		bool flag=false;
		for(int i=0;i<=9;i++)
		{
			if(maxn[i]==0)
			{
				l=i;
				continue;
			}
			if(now1<minn[i]) 
			{
				now1=maxn[i];
				l=i;
			}
			else 
			{
				maxn[i]=now1;
				while(maxn[i]>0 && a[maxn[i]]!=i) maxn[i]--; 
				tmp=i;
				break;
			}
		}
		for(int i=9;i>=0;i--)
		{
			if(maxn[i]==0)
			{
				r=i;
				continue;
			} 
			if(now2>maxn[i]) 
			{
				now2=minn[i];
				r=i;
			}
			else break;
		}
		if(r-l>1 && check(l+1,r-1))
		{
			printf("-\n");
			continue;
		} 
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=l) printf("1");
			else if(a[i]==tmp && i>now1) printf("1");
			else printf("2");
		}
		printf("\n");
	}
}
//1 12 040425524644
//1314341456