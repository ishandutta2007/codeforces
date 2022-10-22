#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=610;
ll f[N][N],g[N][N];int bk[N][N];
ll mymin(ll x,ll y) {return x<y?x:y;}
ll mymax(ll x,ll y) {return x>y?x:y;}
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	memset(f,60,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	memset(bk,0,sizeof(bk));
	for(int i=1;i<=m;i++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		f[x][y]=mymin(f[x][y],c);
		f[y][x]=mymin(f[y][x],c);
		bk[x][y]=bk[y][x]=c;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=mymin(f[i][j],f[i][k]+f[k][j]);
	int q;scanf("%d",&q);
	memset(g,-60,sizeof(g));
	for(int i=1;i<=q;i++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		for(int j=1;j<=n;j++)
			g[j][y]=mymax(g[j][y],c-f[x][j]),g[j][x]=mymax(g[j][x],c-f[y][j]);
	}
	int Ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(bk[i][j]){
				bool pd=false;
				for(int k=1;k<=n;k++)
					if(bk[i][j]+f[j][k]<=g[i][k]) {pd=true;break;}
				if(pd) Ans++;
			}
	printf("%d\n",Ans);
	return 0;
}