#include<bits/stdc++.h>
using namespace std;

int v[2010][2010];
int k,n,m;
bool bo[2010];
char s[110];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool ask(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%s",s+1);
	return (s[1]=='Y')?1:0;
}

int main()
{
	n=rd();k=rd();
	if (k==n)
	{
		for (int i=1;i<=n;i++) bo[i]=ask(i);
		int ans=0;
		for (int i=1;i<=n;i++) ans+=(!bo[i]);
		printf("! %d\n",ans);fflush(stdout);
		return 0;
	}
	if (n==1) { printf("! 1\n");fflush(stdout);return 0; }
	if (k==1)
	{
		for (int i=2;i<=n;i++) for (int j=1;j<i;j++)
		{
			ask(j);
			bo[i]|=ask(i);
		}
		int ans=0;
		for (int i=1;i<=n;i++) ans+=(!bo[i]);
		printf("! %d\n",ans);fflush(stdout);
		return 0;
	}
	k/=2;m=n/k;
	for (int i=1;i<=m;i++) for (int j=1;j<=k;j++) v[i][j]=(i-1)*k+j;
	for (int i=1;i<m;i++)
	{
		for (int j=1;j<=i;j++) if (j+i<=m)
		{
			puts("R");fflush(stdout);
			for (int l=j;l<=m;l+=i)
			{
				for (int l1=1;l1<=k;l1++)
				{
					bo[v[l][l1]]|=ask(v[l][l1]);
				}
			}
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans+=(!bo[i]);
	printf("! %d\n",ans);fflush(stdout);
	return 0;
}