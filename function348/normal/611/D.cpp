#include<cstdio>
#include<iostream>
using namespace std;
const int N=5100,p=1000000007;
int n;
char s[N];
int c[N][N],f[N][N],g[N][N];
int cmp(int p1,int q1,int p2,int q2)
{
	int k=c[p1][p2];
	if (k>=q1-p1+1) return 0;
	return s[p1+k]<s[p2+k];
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	if (s[1]=='0') { printf("0\n");return 0;}
	for (int i=n;i>=1;i--)
	for (int j=i+1;j<=n;j++)
	if (s[i]==s[j]) c[i][j]=c[i+1][j+1]+1;else c[i][j]=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=i;j++)
	{
		if (s[i+1]=='0'&&i<n) f[i][j]=0;
		else if (j==1) f[i][j]=1;else
		{
			int l=0;
			if (j-1<i-j+1) l=1;else
				if (cmp(2*j-i-1,j-1,j,i)) l=2*j-i-1;else l=2*j-i;
			f[i][j]=(g[j-1][j-1]-g[j-1][l-1])%p;
		}
		
	//	printf("%d %d %d\n",i,j,f[i][j]);
		g[i][j]=(g[i][j-1]+f[i][j])%p;
	}
	if (g[n][n]<0) g[n][n]+=p;
	printf("%d\n",g[n][n]);
	return 0;
}