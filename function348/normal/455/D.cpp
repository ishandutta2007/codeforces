#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int N=100010,B=400;
int n,bl,ans,m;
int a[N],len[N];
int b[B][B*2],cnt[B][N];
void get(int k,int &x,int &y)
{
	for (int i=1;i<=bl;i++)
	if (k<=len[i]) { x=i;y=k;return;}
	else k-=len[i];
}
int main()
{
	scanf("%d",&n);
	bl=sqrt(n)+1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i=1;i<=n;i++) 
	{
		int j=i/bl+1;
		b[j][++len[j]]=a[i];
		cnt[j][a[i]]++;
	}
	while (m--)
	{
		int kd,l,r,k;
		scanf("%d%d%d",&kd,&l,&r);
		l=(l+ans-1)%n+1;r=(r+ans-1)%n+1;
		if (l>r) swap(l,r);
		if (kd==1)
		{
			int x,y;
			get(r,x,y);
			int tmp=b[x][y];
			for (int i=y;i<len[x];i++) b[x][i]=b[x][i+1];
			b[x][len[x]]=0;len[x]--;cnt[x][tmp]--;

			get(l,x,y);
			for (int i=len[x];i>=y;i--) b[x][i+1]=b[x][i];
			len[x]++;b[x][y]=tmp;cnt[x][tmp]++;
		}
		if (kd==2)
		{
			int x,y,k;
			scanf("%d",&k);
			k=(k+ans-1)%n+1;
			ans=0;
			get(r,x,y);
			for (int i=1;i<x;i++) ans+=cnt[i][k];
			for (int i=1;i<=y;i++) ans+=b[x][i]==k;
			get(l-1,x,y);
			for (int i=1;i<x;i++) ans-=cnt[i][k];
			for (int i=1;i<=y;i++) ans-=b[x][i]==k;
			printf("%d\n",ans);
		}
		if (m%bl==0) 
		{
			int num=0;
			for (int i=1;i<=bl;i++)
			for (int j=1;j<=len[i];j++)
			{
				a[++num]=b[i][j];
				cnt[i][b[i][j]]--;
			}
			for (int i=1;i<=bl;i++) len[i]=0;
			for (int i=1;i<=n;i++) 
			{
				int j=i/bl+1;
				b[j][++len[j]]=a[i];
				cnt[j][a[i]]++;
			}
		}
	}
	return 0;
}