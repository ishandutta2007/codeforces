#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100010,mod=1000000007;
typedef long long LL;
struct Edge {int y,ne;};
int n,m,p,q,num;
LL tmp[100][3];
int f[N][12][3];
Edge e[N*2];int last[N];
void dfs(int i,int fa)
{
	/*
	f[i][0]=(f[j][0]+f[j][1]+f[j][2])*
	f[i][1]=(f[j][0])*
	f[i][2]=(f[j][0]+f[j][2]*/
	f[i][0][0]=p-1;
	f[i][1][1]=1;
	f[i][0][2]=m-p;
	for (int j=last[i];j;j=e[j].ne)
	if (e[j].y!=fa)
	{
		dfs(e[j].y,i);
		for (int k=0;k<=q;k++)
		for (int l=0;k+l<=q;l++)
		{
			tmp[k+l][0]+=(0LL+f[e[j].y][k][0]+f[e[j].y][k][1]+f[e[j].y][k][2])*f[i][l][0];
			tmp[k+l][1]+=1LL*f[e[j].y][k][0]*f[i][l][1];
			tmp[k+l][2]+=1LL*(f[e[j].y][k][0]+f[e[j].y][k][2])*f[i][l][2];
			tmp[k+l][0]%=mod;tmp[k+l][1]%=mod;tmp[k+l][2]%=mod;
		}
		for (int k=0;k<=q;k++) 
		for (int l=0;l<3;l++)
			f[i][k][l]=tmp[k][l],tmp[k][l]=0;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	num=0;
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		e[++num]=(Edge){y,last[x]};last[x]=num;
		e[++num]=(Edge){x,last[y]};last[y]=num;
	}
	scanf("%d%d",&p,&q);
	dfs(1,0);
	int ans=0;
	for (int i=0;i<=q;i++)
	for (int j=0;j<3;j++) ans=(ans+f[1][i][j])%mod;
	printf("%d\n",ans);
	return 0;
}