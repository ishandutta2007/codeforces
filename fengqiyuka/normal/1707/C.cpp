#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100,maxn=17;
vector<int> B[N];

int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int Fa[N][19],dep[N],dfn[N],sum=0,si[N];bool bk[N],bz[N];
void dfs(int x){
	bk[x]=false;dfn[x]=++sum;si[x]=1;
	for(int i=1;i<=maxn;i++) Fa[x][i]=Fa[Fa[x][i-1]][i-1];
	for(auto y:B[x])
		if(bk[y]){
			Fa[y][0]=x;
			dep[y]=dep[x]+1;dfs(y);
			si[x]+=si[y];
		}
}

int findlca(int x,int y){
	for(int i=maxn;i>=0;i--){
		if(dep[Fa[x][i]]>=dep[y]) x=Fa[x][i];
		if(dep[Fa[y][i]]>=dep[x]) y=Fa[y][i];
	}
	for(int i=maxn;i>=0;i--)
		if(Fa[x][i]!=Fa[y][i])
			x=Fa[x][i],y=Fa[y][i];
	if(x!=y) x=Fa[x][0],y=Fa[y][0];
	return x;
}

int X[N],Y[N],qz[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	memset(bz,false,sizeof(bz));
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int xx=find(x),yy=find(y);
		if(xx!=yy) bz[i]=true,fa[xx]=yy,B[x].push_back(y),B[y].push_back(x);
		X[i]=x;Y[i]=y;
	}
	
	memset(bk,true,sizeof(bk));
	dep[1]=1;dfs(1);
	
	for(int i=1;i<=m;i++)
		if(!bz[i]){
			int x=X[i],y=Y[i];
			int t=findlca(x,y);
			if(x==t) swap(x,y);
			if(y==t){
				int tt=x;
				for(int j=maxn;j>=0;j--)
					if(dep[Fa[tt][j]]>dep[y]) tt=Fa[tt][j];
				qz[dfn[x]]++;qz[dfn[x]+si[x]]--;
				qz[1]++;qz[dfn[tt]]--;qz[dfn[tt]+si[tt]]++;qz[n+1]--;
			}
			else{
				qz[dfn[x]]++;
				qz[dfn[x]+si[x]]--;
				qz[dfn[y]]++;
				qz[dfn[y]+si[y]]--;
			}
		}
	
	for(int i=1;i<=n;i++) qz[i]+=qz[i-1];
	for(int i=1;i<=n;i++){
		if(qz[dfn[i]]==m-n+1){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	printf("\n");
	
	return 0;
}