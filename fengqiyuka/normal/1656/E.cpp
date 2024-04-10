#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int N=1e5+100;
vector<int> B[N];bool bk[N];

int dfn[N],ID[N],p[N],fa[N],sum,f[N],g[N];
void dfs(int x){
	bk[x]=false;dfn[x]=++sum;ID[sum]=x;
	for(auto y:B[x]){
		if(bk[y]){
			fa[y]=x;p[x]++;
			dfs(y);
		}
	}
}

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) B[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			B[x].push_back(y);
			B[y].push_back(x);
		}
		
		for(int i=1;i<=n;i++) bk[i]=true,fa[i]=0,p[i]=0,dfn[i]=0,ID[i]=0;sum=0;
		dfs(1);
		
		f[1]=1;g[1]=-p[1];
		for(auto y:B[1]) f[y]=0,g[y]=1;
		for(int i=2;i<=n;i++){
			int x=ID[i];
			if(x==9){
				x++;x--;
			}
			for(auto y:B[x]){
				if(fa[y]==x){
					f[y]=1-f[x];
					g[y]=-g[x];
				}
			}
			int t1=1-f[x],t2=-g[x];
			f[x]=f[x]-p[x]*t1;g[x]=g[x]-p[x]*t2;
		}
		
		for(int i=1;i<=n;i++) printf("%d ",g[i]);
		printf("\n");
	}
	
	
	return 0;
}