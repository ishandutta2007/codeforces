#include<bits/stdc++.h>
using namespace std;
const int N=5005;
char s[N][N];
int a[N],b[N],d[N],n,k,f;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int j=1;j<=k;j++)
		a[s[1][j]-'a']++;
	for(int j=0;j<26;j++)
		f+=a[j]>1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<26;j++)
			b[j]=0;
		for(int j=1;j<=k;j++)
		{
			b[s[i][j]-'a']++;
			if(s[i][j]!=s[1][j])
				d[i]++;
		}
		for(int j=0;j<26;j++)
		{
			if(a[j]!=b[j])
			{
				puts("-1");
				return 0;
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=i+1;j<=k;j++)
		{
			int sum=1;
			for(int t=2;t<=n;t++)
			{
				int zh=d[t];
				zh-=s[1][i]!=s[t][i];
				zh-=s[1][j]!=s[t][j];
				zh+=s[1][i]!=s[t][j];
				zh+=s[1][j]!=s[t][i];
				if(zh==2||(zh==0&&f))
					sum++;
			}
			if(sum==n)
			{
				swap(s[1][i],s[1][j]);
				printf("%s\n",s[1]+1);
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}