#include<iostream>
#include<cstring>
#include<cstdio>
#define num(t,x,y) ((t)*n*3+((x)-1)*n+(y))
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[5][105];
int n,num,K,vis[60006],flag;
struct Train{int x,y1,y2;
	bool crash(int t,int X,int Y){return X==x&&Y>=y1-t*2&&Y<=y2-t*2;}
}s[100];

void dfs(int t,int x,int y)
{
//	cout<<"Dfs"<<t<<" "<<x<<" "<<y<<endl;
	vis[num(t,x,y)]=1;if(t==105||flag) return;
	for(int i=1;i<=K;++i) if(s[i].crash(t,x,y)||s[i].crash(t,x,y+1)) return;
	if(y==n) flag=1;
	for(int i=-1;i<=1;++i)
	{
		int Fg=1,nx=x+i,ny=y+1;
		if(nx<1||ny<1||nx>3||ny>n) continue;
		for(int j=1;j<=K;++j) if(s[j].crash(t+1,nx,ny)||s[j].crash(t,nx,ny)) Fg=false;
		if(Fg&&!vis[num(t+1,nx,ny)]) dfs(t+1,nx,ny);	
	}
}

int main()
{
	for(int T=read();T;--T)
	{
		n=read();K=read();num=flag=0;int Sx,Sy;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=3;++i) scanf("%s",st[i]+1);
		for(int i=1;i<=3;++i)
			for(int j=1,k;j<=n;j=k+1)
			{
				if(st[i][k=j]=='.') continue;
				if(st[i][j]=='s') {Sx=i;Sy=j;continue;}
				for(;k<n&&st[i][k+1]==st[i][j];++k);
				s[++num]=(Train){i,j,k};
			}
		dfs(0,Sx,Sy);
		puts(flag?"YES":"NO");
	}
	return 0;
}