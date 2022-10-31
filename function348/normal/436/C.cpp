#include<cstdio>
#include<iostream>
#define rep(i,a,b) for (int i=a;i<=b;i++)
using namespace std;
const int N=1010;
int n,m,p,w,ans;
int d[N],g[N];
char a[N][20][20];
int v[N];
int ans1[N],ans2[N];
char getc()
{
	char ch;
	while ((ch=getchar())<=32);
	return ch;
}
int diff(int x,int y)
{
	int res=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		res+=a[x][i][j]!=a[y][i][j];
	return res;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&p,&w);
	rep(k,1,p)
	rep(i,1,n)
	rep(j,1,m)
		a[k][i][j]=getc();
	rep(i,1,p) d[i]=n*m,g[i]=0;
	rep(ii,1,p)
	{
		int j=0;d[0]=1000;
		rep(i,1,p)
		if (!v[i]&&d[i]<d[j]) j=i;
		ans1[ii]=j;ans2[ii]=g[j];
		v[j]=1;ans+=d[j];
		rep(i,1,p)
		if (!v[i]) 
		{
			int t=diff(i,j)*w;
			if (t<=d[i])
			{
				d[i]=t;
				g[i]=j;
			}
		}
	}
	printf("%d\n",ans);
	rep(i,1,p) printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}