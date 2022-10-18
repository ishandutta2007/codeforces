#include <bits/stdc++.h>
#define N 2005
int n,m,k,s,A[N][N],B[N][N],C[N][N],D[N][N],G[N][N],b[100005],dis[100][100],ans=0;
void work(int c){
	for(int i=0;i<=n+1;++i){
		for(int j=0;j<=m+1;++j){
			A[i][j]=B[i][j]=C[i][j]=D[i][j]=-1e6;
			if(G[i][j]==c){
				A[i][j]=-i-j;
				B[i][j]=i-j;
				C[i][j]=-i+j;
				D[i][j]=i+j;
			}
		}
	}for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)A[i][j]=std::max(std::max(A[i-1][j],A[i][j-1]),A[i][j]);
	for(int i=n;i>=1;--i)
	for(int j=1;j<=m;++j)B[i][j]=std::max(std::max(B[i+1][j],B[i][j-1]),B[i][j]);
	for(int i=1;i<=n;++i)
	for(int j=m;j>=1;--j)C[i][j]=std::max(std::max(C[i-1][j],C[i][j+1]),C[i][j]);
	for(int i=n;i>=1;--i)
	for(int j=m;j>=1;--j)D[i][j]=std::max(std::max(D[i+1][j],D[i][j+1]),D[i][j]);
}
	

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&G[i][j]);
	for(int i=1;i<=s;++i)scanf("%d",&b[i]);
	for(int i=1;i<=k;++i){
		work(i);
		for(int x=1;x<=n;++x)
			for(int y=1;y<=m;++y)
				dis[i][G[x][y]]=
				std::max(std::max(std::max(std::max(dis[i][G[x][y]],x+y+A[x][y]),y-x+B[x][y]),
				x-y+C[x][y]),-x-y+D[x][y]);
	}for(int i=1;i<s;++i){
//		printf("%d\n",dis[b[i]][b[i+1]]);
		ans=std::max(ans,dis[b[i]][b[i+1]]);
	}
	printf("%d",ans);
	return 0;
}