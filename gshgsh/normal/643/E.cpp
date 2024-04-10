#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 500001
int Q,N,fa[MAXN];double f[MAXN][61];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	Q=get();N=1;For(i,0,60)f[1][i]=1;
	while(Q--)
	{
		int opt=get(),x=get();
		if(opt==1)
		{
			N++;fa[N]=x;For(i,0,60)f[N][i]=1;double lst=f[x][0];int y=x;f[x][0]/=2;x=fa[x];
			For(j,1,60){if(!x)break;double tmp=f[x][j];f[x][j]/=(lst+1)/2;f[x][j]*=(f[y][j-1]+1)/2;lst=tmp;y=x;x=fa[x];}
		}
		else{double ans=0;For(j,1,60)ans+=j*(f[x][j]-f[x][j-1]);printf("%.10lf\n",ans);}
	}
	return 0;
}