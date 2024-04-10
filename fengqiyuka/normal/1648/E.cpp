#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

const int N=2e5+100;

set<int> S[N];
set<int>::iterator iter;

struct Edge{
	int x,y,c,id;
}g[N];int Ans[N];
bool cmp(Edge n1,Edge n2) {return (n1.c<n2.c);}

struct edge{
	int x,y,c,next;
}a[N];int len,last[N];
void ins(int x,int y,int c){
	a[++len].x=x;a[len].y=y;a[len].c=c;
	a[len].next=last[x];last[x]=len;
}

struct node{
	int x,y;
	node(int _x,int _y) {x=_x;y=_y;}
};

vector<int> B[N];
vector<node> C;

int fa[N],Fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int Find(int x){
	if(Fa[x]==x) return x;
	return Fa[x]=Find(Fa[x]);
}

int mymax(int x,int y) {return (x>y?x:y);}

bool dfs1(int x,int rt){
	iter=S[x].lower_bound(rt);
	if(iter==S[x].end()||(*iter)>rt) return true;
	for(int k=last[x];k;k=a[k].next){
		bool pd=dfs1(a[k].y,rt);
		if(pd) return true;
	}
	return false;
}
bool dfs(int x,int rt){
	bool pd=dfs1(rt,x);
	if(pd) return true;
	for(int k=last[x];k;k=a[k].next){
		bool pd=dfs(a[k].y,rt);
		if(pd) return true;
	}
	return false;
}

int f[N][21],p[N][21],dep[N],maxn=18;
void dfs2(int x){
	for(int i=1;i<=maxn;i++){
		f[x][i]=f[f[x][i-1]][i-1];
		p[x][i]=mymax(p[x][i-1],p[f[x][i-1]][i-1]);
	}
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		dep[y]=dep[x]+1;
		f[y][0]=x;p[y][0]=a[k].c;
		dfs2(y);
	}
}

int main()
{
	
	int T;scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		
		for(int i=1;i<=n;i++) S[i].clear();
		
		for(int i=1;i<=m;i++) scanf("%d%d%d",&g[i].x,&g[i].y,&g[i].c),S[g[i].x].insert(g[i].y),S[g[i].y].insert(g[i].x),g[i].id=i;
		sort(g+1,g+m+1,cmp);
		
		for(int i=1;i<=n;i++) B[i].clear();
		for(int i=1;i<=n;i++) fa[i]=i,Fa[i]=i,B[i].push_back(i);
		
		len=0;
		for(int i=1;i<=n;i++) last[i]=0;
		
		for(int i=1;i<=m;i++){
			int x=find(g[i].x),y=find(g[i].y);
			if(x!=y){
				C.clear();
				for(auto z1:B[x])
					for(auto z2:B[y]){
						bool pd=dfs(z1,z2);
						if(pd) C.push_back(node(z1,z2));
					}
				for(auto z:C){
					int z1=Find(z.x),z2=Find(z.y);
					if(z1!=z2) Fa[z1]=z2,ins(z2,z1,g[i].c);
				}
				fa[y]=x;
				B[n+1].clear();
				for(auto z1:B[x])
					if(Find(z1)==z1) B[n+1].push_back(z1);
				for(auto z1:B[y])
					if(Find(z1)==z1) B[n+1].push_back(z1);
				B[x].clear();
				for(auto z1:B[n+1]) B[x].push_back(z1);
			}
		}
		
		for(int i=1;i<=n;i++)
			for(int j=0;j<=maxn;j++) f[i][j]=p[i][j]=0;
		for(int i=1;i<=n;i++) dep[i]=0;
		
		dep[Find(1)]=1;dfs2(Find(1));
		for(int i=1;i<=m;i++){
			int Max=0,x=g[i].x,y=g[i].y;
			for(int j=maxn;j>=0;j--){
				if(dep[f[x][j]]>=dep[y])
					Max=mymax(Max,p[x][j]),x=f[x][j];
				if(dep[f[y][j]]>=dep[x])
					Max=mymax(Max,p[y][j]),y=f[y][j];
			}
			for(int j=maxn;j>=0;j--)
				if(f[x][j]!=f[y][j])
					Max=mymax(Max,mymax(p[x][j],p[y][j])),x=f[x][j],y=f[y][j];
			if(x!=y) Max=mymax(Max,mymax(p[x][0],p[y][0]));
			Ans[g[i].id]=Max;
		}
		
		for(int i=1;i<=m;i++) printf("%d ",Ans[i]);
		printf("\n");
	}
	
	return 0;
}