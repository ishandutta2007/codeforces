#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=100+19,oo=(1<<30)-1;
typedef long long LL;
int f[N][N],g[N],A[N],B[N],F[N][N],G[N][N];
int n,T,tot,m,Ans;

void DP()
{
	memset(f,200,sizeof(f));
	For(i,1,n+1)
	{
		memset(g,200,sizeof(g));
		g[i]=1;
		For(j,i+1,n+1) For(k,i,j) if (A[k]<=A[j]) g[j]=max(g[j],g[k]+1);
		For(j,1,n+1) if (A[i]<=A[j]) f[A[i]][A[j]]=max(f[A[i]][A[j]],g[j]);
	}
}

int main()
{
	n=IN(),T=IN();
	For(i,1,n+1) A[i]=B[i]=IN();
	sort(B+1,B+n+1);m=unique(B+1,B+n+1)-B-1;
	For(i,1,n+1) A[i]=lower_bound(B+1,B+m+1,A[i])-B;
	DP();

	memset(F,200,sizeof(F));
	memset(G,200,sizeof(G));
	For(i,1,m+1) F[0][i]=G[0][i]=0;
	For(i,1,n+1) For(j,1,m+1)
	{
		int tmp=-oo;
		for (int k=1;k<=m;k++) tmp=max(tmp,F[i-1][k]),F[i][j]=max(F[i][j],tmp+f[k][j]);
	}
	For(i,1,n+1) For(j,1,m+1)
	{
		int tmp=-oo;
		for (int k=m;k>=1;k--) tmp=max(tmp,G[i-1][k]),G[i][j]=max(G[i][j],tmp+f[j][k]);
	}
	For(i,0,n+1) For(j,0,n+1) For(k,1,m+1)
		if (i+j<=T) Ans=max(Ans,F[i][k]+G[j][k]+f[k][k]*(T-i-j));
	printf("%d\n",Ans);
}