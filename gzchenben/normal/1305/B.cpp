#include<cstdio>
#include<cstring>
#include<queue>
#include<stack> 
#include<algorithm>
using namespace std;
int n,a[200005],sum1[200005],sum2[200005];
char s[200005];
bool check()
{
	if(n%2==1) return false;
	for(int i=1;i<=n/2;i++)
	{
		if(a[i]!=0) return false;
	}
	for(int i=n/2+1;i<=n;i++)
	{
		if(a[i]!=1) return false;
	}
	return true;
}
void print(int x)
{
	int cnt=0;
	for(int i=1;i<=x;i++)
	{
		if(a[i]==0) cnt++;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(a[i]==1) cnt++;
	}
	if(!cnt)
	{
		printf("0\n");
		return;
	}
	printf("1\n");
	printf("%d\n",cnt);
	for(int i=1;i<=x;i++)
	{
		if(a[i]==0) printf("%d ",i);
	}
	for(int i=x+1;i<=n;i++)
	{
		if(a[i]==1) printf("%d ",i);
	}
	printf("\n");
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		sum1[i]=sum1[i-1];
		if(s[i]=='(') 
		{
			a[i]=0;
			sum1[i]++;
		}
		else a[i]=1;
	}
	for(int i=n;i>=1;i--)
	{
		sum2[i]=sum2[i+1]+a[i];
	}
	for(int i=0;i<=n+1;i++)
	{
		if(sum1[i]==sum2[i+1])
		{
			print(i);
			return 0;
		}
	}
	return 0;
}