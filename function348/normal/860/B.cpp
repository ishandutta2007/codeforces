#include<cstdio>
#include<iostream>
using namespace std;
const int N=70010;
int n,num;
int ch[N*50][10];
int cnt[N*51],v[N*51];
char a[N][12];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",a[i]);
		for (int j=0;j<9;j++)
		{
			int now=0;
			for (int k=j;k<9;k++)
			{
				if (ch[now][a[i][k]-'0']==0)
				    ch[now][a[i][k]-'0']=++num;
				now=ch[now][a[i][k]-'0'];
				if (v[now]<i) cnt[now]++;
				v[now]=i;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		int ans1=0,ans2=100;
		for (int j=0;j<9;j++)
		{
			int now=0;
			for (int k=j;k<9;k++)
			{
				now=ch[now][a[i][k]-'0'];
				if (cnt[now]==1)
			{
				if (k-j<ans2-ans1) ans1=j,ans2=k;
				break;
			}
			}
		}
		for (int j=ans1;j<=ans2;j++) printf("%c",a[i][j]);
		printf("\n");
	}
}