#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N];
int n,ans[N];
void mi()
{
	for(int i=1;i<=n;i++)
		ans[i]=n-i+1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='>')
			continue;
		int j=i;
		while(s[j]=='<')
			j++;
		ans[i]=ans[j];
		for(int k=i+1;k<=j;k++)
			ans[k]=ans[k-1]+1;
		i=j;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	puts("");
}
void ma()
{
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(s[j]=='>')
			j++;
		for(int k=j;k>=i;k--)
		{
			ans[k]=cnt;
			cnt++;
		}
		i=j;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("\n%d %s",&n,s+1);
		mi();
		ma();	
	}
	return 0;
}