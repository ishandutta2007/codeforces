#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],n,k,s[N],t,p=1,vis[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
		vis[a[i]]=1;
		if(a[i]==p)
		{
			p++;
			while(s[t]==p)
			{
				p++;
				t--;
			}
		}
		else if(t&&a[i]>s[t])
		{
			puts("-1");
			return 0;
		}
		else
		{
			t++;
			s[t]=a[i];
		}
	}
	if(p<=n)
	{	
		t++;
		s[t]=p-1;
		for(int i=t-1;i>=1;i--)
		{
			for(int j=s[i]-1;j>s[i+1];j--)
			{
				k++;
				a[k]=j;
				vis[j]=1;
			}
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(!vis[i])
		{
			k++;
			a[k]=i;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}