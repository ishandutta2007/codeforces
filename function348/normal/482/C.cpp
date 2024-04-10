#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=54,M=24,NN=1100000;
int n;
char s[N][M];
LL p[N][M];
int cnt[NN],xx[NN];
LL f[NN];
double g[NN];
double ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%s",s[i]);
	int m=strlen(s[1]);cnt[0]=m;
	int K=1<<m;
	for (int i=1;i<=n;i++)
	for (int j=0;j<m;j++)
	for (int k=1;k<=n;k++)
	if (s[i][j]==s[k][j]) p[i][j]+=1LL<<k;
	for (int i=1;i<K;i++) cnt[i]=cnt[i-(i&-i)]-1;
	for (int i=0;i<m;i++) xx[1<<i]=i;
	for (int i=1;i<=n;i++)
	{
		f[0]=(1LL<<(n+1))-2;
		for (int j=1;j<K;j++)
		{
			f[j]=f[j-(j&-j)]&p[i][xx[j&-j]];
		}
		for (int j=K-1;j>=0;j--)
		{
			g[j]=0;
			if (f[j]==(f[j]&-f[j])) continue;
			int t=K-1-j;
			g[j]=cnt[j];
			for (int k;t;t-=k)
			{
				k=t&-t;
				g[j]+=g[j+k];
			}
			g[j]/=cnt[j];
		}
		ans=ans+g[0]/n;
	}
	printf("%.10lf\n",ans);
	return 0;
}