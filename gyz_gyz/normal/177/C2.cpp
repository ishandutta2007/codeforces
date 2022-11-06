#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 2001
#define M 200000
int n,m,x,y,k,v[N],X[M],Y[M],p[N],a[N][N],ans;
void dfs(int x,int y){
	v[x]=y;p[y]++;
	rep(i,1,n)if(a[x][i]&&!v[i])dfs(i,y);
}
int main(){
	scanf("%d",&n);scanf("%d",&k);
	rep(i,1,k){
		scanf("%d%d",&x,&y);a[x][y]=a[y][x]=1;
	}
	scanf("%d",&m);
	rep(i,1,m){
		scanf("%d%d",&X[i],&Y[i]);
	}
	rep(i,1,n)if(!v[i])dfs(i,i);
	rep(i,1,m)if(v[X[i]]==v[Y[i]])p[v[X[i]]]=0;
	rep(i,1,n)if(p[i]>ans)ans=p[i];
	printf("%d\n",ans);
}