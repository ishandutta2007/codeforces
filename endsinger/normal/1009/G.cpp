#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int v[N],x[64],y[64],n,m;
char s[N],ans[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		v[i]=63;
	for(int i=1;i<=n;i++)
		for(int j=1;j<64;j++)
			if(j&(1<<(s[i]-'a')))
				y[j]++;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		char t[10];
		scanf("%d%s",&x,t);
		int s=strlen(t);
		v[x]=0;
		for(int j=0;j<s;j++)
			v[x]|=1<<(t[j]-'a');
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<64;j++)
			if(v[i]&j)
				x[j]++;
	for(int i=0;i<64;i++)
	{
		if(y[i]>x[i])
		{
			puts("Impossible");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int m=v[i];
		for(int j=1;j<63;j++)
			if(v[i]&j)
				if(x[j]==y[j])
					m&=j;
		for(int j=0;j<6;j++)
		{
			if(m&(1<<j))
			{
				m=1<<j;
				ans[i]=j+'a';
				break;
			}
		}
		for(int j=1;j<64;j++)
			if(m&j)
				y[j]--;
		for(int j=1;j<64;j++)
			if(v[i]&j)
				x[j]--;
	}
	printf("%s\n",ans+1);
	return 0;
}