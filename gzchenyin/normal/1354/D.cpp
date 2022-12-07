#include<cstdio>
#include<set>
using namespace std;
long double ans,tmp;
int n,k,a[2000005],tree[3000005];
int lowbit(int k)
{
    return k & -k;
}
void add(int x,int k)
{
    while(x<=(1<<20))
    {
        tree[x]+=k;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int ans=0;
    while(x!=0)
    {
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
void del(int x)
{
	int ans=0,sum=0;
	for(int i=20;i>=0;i--)
	{
		if(ans+(1<<i)<=n && sum+tree[ans+(1<<i)]<x)
		{
			ans+=(1<<i);
			sum+=tree[ans];
		}
	}
//	printf("%d\n",ans+1);
	add(ans+1,-1);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		add(a[i],1);
	}
	for(int i=1;i<=k;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp>0) add(tmp,1);
		else del(-tmp);
	}
	int ans=0,sum=0;
	for(int i=20;i>=0;i--)
	{
		if(ans+(1<<i)<=n && sum+tree[ans+(1<<i)]<=0)
		{
			ans+=(1<<i);
			sum+=tree[ans];
		}
	}
	if(ans>=n) printf("0\n");
	else printf("%d\n",ans+1);
}