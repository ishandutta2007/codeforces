#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define forv(x) for(unsigned i=0;i<g[x].size();++i)
#define ckfa const int y=g[x][i];if(y==fa)continue;
using namespace std;

const int mxn=1e5+3,mod=1e9+7;
vector<int>g[mxn];
int n,co[mxn],root;
inline void add(int x,int y){ g[x].push_back(y); }

long long f[mxn][2];
void dfs(int x,int fa){
	if(g[x].size()==1&&x!=1){
		if(co[x])f[x][1]=1;
		else f[x][0]=1;
		return;
	}
	forv(x) {
		ckfa
		dfs(y,x);
	}
	if(co[x]){
		f[x][1]=1;
		forv(x) {
			ckfa
			f[x][1] = f[x][1]*(f[y][0]+f[y][1])%mod;
		}
		return;
	}
	
	// no color this vertex
	f[x][0]=1,f[x][1]=0;
	forv(x){
		ckfa
		f[x][1] = f[x][1]*(f[y][0]+f[y][1]) + f[x][0]*f[y][1];
		f[x][1]%=mod;
		f[x][0] = f[x][0]*(f[y][0]+f[y][1])%mod;
	}
}

int main(void){
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		int u;scanf("%d",&u);
		add(u+1,i),add(i,u+1);
	}
	for(int i=1;i<=n;++i)scanf("%d",co+i);
	dfs(1,0);
	printf("%lld\n",f[1][1]);
	return 0;
}
//4
//1 0 0 1
//1 2
//2 3
//3 4