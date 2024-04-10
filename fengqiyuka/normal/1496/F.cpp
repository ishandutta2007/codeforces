#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=410,M=610,mod=998244353;
struct edge{
	int x,y,next;
}a[2*M];int len,last[N];
void ins(int x,int y){
	a[++len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
int dis[N][N],d[N],bz[2*M][N],Ans[N][N],g[N];
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		ins(x,y);ins(y,x);
	}
	memset(bz,0,sizeof(bz));
	memset(dis,60,sizeof(dis));
	for(int i=1;i<=n;i++){
		int st=0,ed=1;d[1]=i;
		dis[i][i]=0;
		while(st<ed){
			int x=d[++st];
			for(int k=last[x];k;k=a[k].next){
				int y=a[k].y;
				if(dis[i][y]>dis[i][x]+1){
					dis[i][y]=dis[i][x]+1;
					d[++ed]=y;
				}
			}
		}
		for(int j=1;j<=len;j++)
			if(dis[i][a[j].x]+1==dis[i][a[j].y]) bz[j][i]=1;
	}
	memset(Ans,0,sizeof(Ans));
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			memset(g,0,sizeof(g));
			for(int k=1;k<=len;k++)
				if(bz[k][i]&&bz[k][j]) g[a[k].y]++;
			bool pd=true;
			int t=i;
			while(t!=j){
				g[t]++;
				if(g[t]>1) {pd=false;break;}
				for(int k=last[t];k;k=a[k].next)
					if(bz[k][i]&&!g[a[k].y]) {t=a[k].y;break;}
			}
			g[j]++;
			for(int k=1;k<=n;k++)
				if(!g[k]) {pd=false;break;}
			if(pd){
				int Sum=1;
				for(int k=1;k<=n;k++) Sum=(ll)Sum*g[k]%mod;
				Ans[i][j]=Sum;
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++) Ans[i][j]=Ans[j][i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) printf("%d ",Ans[i][j]);
		printf("\n");
	}
	return 0;
}