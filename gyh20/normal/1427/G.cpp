#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,m,a[202][202],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},w[4][202][202],ans;
long long sum;
struct node{
	int x,y,w;
	bool operator <(const node A)const{return w<A.w;}
}p[1002];
char S[202][202],T[202][202],v[202][202];
short u[202][202];
inline bool dfs(re int x,re int y,re int o){
	if(o?T[x][y]:S[x][y]){++u[x][y];return 1;}
	if(v[x][y])return 0;v[x][y]=1;
	for(re int i=0;i<4;++i){
		re int nx=x+dx[i],ny=y+dy[i];
		if(a[nx][ny]==-1||!w[i][x][y])continue;
		if(dfs(nx,ny,o)){
			--w[i][x][y],++w[(i+2)&3][nx][ny];
			return 1;
		}
	}return 0;
}
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[0][i]=a[i][0]=a[n+1][i]=a[i][n+1]=-1;
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j){
			a[i][j]=read(),w[0][i][j]=w[1][i][j]=w[2][i][j]=w[3][i][j]=1;
			if(a[i][j]>0)p[++m]=(node){i,j,a[i][j]},T[i][j]=1;
		}
	sort(p+1,p+m+1);
	for(re int i=1;i<m;++i){memset(v,0,sizeof(v));
		while(u[p[i].x][p[i].y]--)ans-=dfs(p[i].x,p[i].y,0),memset(v,0,sizeof(v));
		T[p[i].x][p[i].y]=0,S[p[i].x][p[i].y]=1;
		for(re int ii=1;ii<=m;++ii)while(S[p[ii].x][p[ii].y]&&dfs(p[ii].x,p[ii].y,1))memset(v,0,sizeof(v)),++ans;
		sum+=1ll*ans*(p[i+1].w-p[i].w);
	}printf("%lld",sum);
}