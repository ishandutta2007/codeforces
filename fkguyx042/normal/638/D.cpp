#include<stdio.h>
#define N 105
using namespace std;
int F[N][N][N],G[N][N][N],A[N],B[N],C[N];char a[N][N][N];
int n,m,p,flag,t,ans,x,y,z,used,i,j,k,d,g;
inline int ok(int i,int j,int k){return a[i][j][k]=='1';}
void BFS(int x,int y,int z,int F[][N][N],int step){
	if (step>3||!ok(x,y,z)) return;
	F[x][y][z]=used;
	BFS(x+1,y,z,F,step+1);
	BFS(x,y+1,z,F,step+1);
	BFS(x,y,z+1,F,step+1);
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			scanf("%s",a[i][j]+1);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			for (k=1;k<=p;k++)
				if (a[i][j][k]=='1'){
					flag=t=0;
					if (ok(i+1,j,k)) A[++t]=i+1,B[t]=j,C[t]=k;
					if (ok(i,j+1,k)) A[++t]=i,B[t]=j+1,C[t]=k;
					if (ok(i,j,k+1)) A[++t]=i,B[t]=j,C[t]=k+1;
					for (d=0;d<3;d++){
						x=i-(d==0);y=j-(d==1);z=k-(d==2);
						if (!ok(x,y,z)) continue;
						a[i][j][k]='1';
						++used;BFS(x,y,z,F,0);
						a[i][j][k]='0';
						BFS(x,y,z,G,0);
						for (g=1;g<=t;g++)
							if (F[A[g]][B[g]][C[g]]==used&&G[A[g]][B[g]][C[g]]!=used)
								flag=1;
				  }
					a[i][j][k]='1';ans+=flag;
			  }
	printf("%d\n",ans);
}