#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,t,a[200005];
void work()
{
	if(k==1) 
	{
		for(int i=1;i<=n;i++) printf("%c",a[i]+'a'-1);
		return;
	}
	if(a[1]==a[n])
	{
		int len=n/k;
		if(n%k) len++;
		for(int i=1;i<=len;i++) printf("%c",a[i]+'a'-1);
		return;
	}
	int maxn=0,pre=0;
	for(int i=1;i<=k;i++)
	{
		if(a[i]>maxn) maxn=a[i],pre=i;
	}
	if(pre!=1) 
	{
		printf("%c",a[k]+'a'-1);
		return;
	}
	if(a[k+1]==a[k])
	{
		for(int i=k;i<=n;i++) printf("%c",a[i]+'a'-1);
		return;
	}
	if(a[n]!=a[k+1])
	{
		for(int i=k;i<=n;i++) printf("%c",a[i]+'a'-1);
		return;
	}
	else
	{
		printf("%c",a[k]+'a'-1);
		int len=(n-1)/k;
		for(int i=1;i<=len;i++) printf("%c",a[k+1]+'a'-1); 
	}
	
}
int main()
{
	scanf("%d",&t);
	for(int x=1;x<=t;x++)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			char x;
			scanf(" %c",&x);
			a[i]=x-'a'+1;
		}
		sort(a+1,a+n+1);
		work();
		printf("\n");
	}
}