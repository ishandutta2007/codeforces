#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[2005],c[2005],t[2005],cnt=1,now,ans=10000;
struct node
{
	int x;
	int pos;
}b[2005];
bool cmp(node x,node y)
{
	return x.x<y.x;
}
bool check()
{
	for(int i=1;i<=cnt;i++)
	{
		if(t[i]>1) return false;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i].x=a[i];
		b[i].pos=i;
	}
	sort(b+1,b+n+1,cmp);
	a[b[1].pos]=1;
	for(int i=2;i<=n;i++)
	{
		if(b[i].x!=b[i-1].x)
		{
			cnt++;
		} 
		a[b[i].pos]=cnt;
	}
	for(int i=1;i<=n;i++)
	{
		t[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		bool flag=true;
		while(!check())
		{
			if(now==n)
			{
				flag=false;
				break;
			}
			now++;
			t[a[now]]--;
		}
//		printf("%d %d\n",i,now);
		if(!flag) break;
		ans=min(ans,now-i+1);
		t[a[i]]++;
	}
	printf("%d\n",ans);
}