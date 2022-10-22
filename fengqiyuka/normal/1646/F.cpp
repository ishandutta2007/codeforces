#include<cstdio>
#include<cstring>
using namespace std;

const int N=110;
int c[N][N],b[N],Ans[N*N][N],tot=0,g[N][N];

int main()
{
	
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		bool pd=true;
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
			g[i][j]=c[i][j]-i;
			if(g[i][j]<=0) g[i][j]+=n;
			if(g[i][j]==n&&pd) pd=false,g[i][j]=0;
		}
	}
			
	while(1){
		bool pd=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				if(g[i][j]) {pd=false;break;}
			if(!pd) break;
		}
		if(pd) break;
		
		for(int i=1;i<=n;i++){
			int Max=-1;
			for(int j=1;j<=n;j++){
				int t=g[i][j];
				if(Max<t) Max=t,b[i]=j;
			}
		}
		
		tot++;
		for(int i=1;i<=n;i++) Ans[tot][i]=c[i][b[i]],g[i][b[i]]--;
		int t1=c[n][b[n]],t2=g[n][b[n]];
		for(int i=n;i>=2;i--) c[i][b[i]]=c[i-1][b[i-1]],g[i][b[i]]=g[i-1][b[i-1]];
		c[1][b[1]]=t1;g[1][b[1]]=t2;
	}
	
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=n;j++) printf("%d ",Ans[i][j]);
		printf("\n");
	}
	
	return 0;
}