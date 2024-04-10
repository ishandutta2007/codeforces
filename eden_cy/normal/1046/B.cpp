#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define EOR(i,x) for(int i=Head[x];~i;i=Nxt[i])
#define M 500005
#define N 100005

int n,m,q;
void chkmi(int &x,int y) {if(x>y) x=y;}

int Head[N],E[M<<1],Nxt[M<<1],tol;
void Edge(int x,int y) {
	E[tol]=y;Nxt[tol]=Head[x];Head[x]=tol++;
}
struct edge{
	int to,cost;
};
vector<edge> G[N<<1];
int dfn[N],low[N],Stk[N];
bool is_cut[N];
int dfn_cnt,Stk_top,bcc_cnt;
void Tarjan(int x,int fr) {
	int chi_cnt=0,y;
	dfn[x]=low[x]=++dfn_cnt;
	Stk[++Stk_top]=x;
	EOR(i,x) if((y=E[i])!=fr) {
		if(!dfn[y]) {
			chi_cnt++;
			Tarjan(y,x);
			chkmi(low[x],low[y]);
			if(dfn[x]<=low[y]) {
				is_cut[x]=true;
				bcc_cnt++;
				while(Stk_top) {
					int k=Stk[Stk_top--];
//					cerr<<bcc_cnt<<" -"<<k<<endl;
					G[bcc_cnt].push_back((edge){k,1});
					G[k].push_back((edge){bcc_cnt,1});
					if(k==y) break;
				}
//				cerr<<bcc_cnt<<" -"<<x<<endl;
				G[bcc_cnt].push_back((edge){x,1});
				G[x].push_back((edge){bcc_cnt,1});
			}
		} else chkmi(low[x],dfn[y]);
	}
	if(!fr) is_cut[x]=chi_cnt>1;
}
int top[M],dep[M],Fa[M],son[M],sz[M];
int dis[M];

void dfs(int x,int f,int d){
	dis[x]=d;
	Fa[x]=f;
	dep[x]=dep[f]+1;
	sz[x]=1;
	for(int i=0;i<(int)G[x].size();i++){
		edge y=G[x][i];
		if(y.to==f)continue;
		dfs(y.to,x,d+y.cost);
		sz[x]+=sz[y.to];
		if(son[x]==0||sz[son[x]]<sz[y.to])son[x]=y.to;
	}
}

void Dfs(int x,int tp){
	top[x]=tp;
	if(son[x])Dfs(son[x],tp);
	for(int i=0;i<(int)G[x].size();i++){
		edge y=G[x][i];
		if(y.to==Fa[x]||y.to==son[x])continue;
		Dfs(y.to,y.to);
	}
}

int LCA(int a,int b){
	while(top[a]!=top[b]){
		if(dep[top[a]]>dep[top[b]])swap(a,b);
		b=Fa[top[b]];
	}
	return dep[a]<dep[b]?a:b;
}

int main() {
	memset(Head,-1,sizeof(Head));
	scanf("%d%d%d",&n,&m,&q);
	bcc_cnt=n;
	FOR(i,1,m){
		int a,b;
		scanf("%d%d",&a,&b);
		Edge(a,b);
		Edge(b,a);
	}
	FOR(i,1,n){
		if(dfn[i])continue;
		Tarjan(i,-1);
	}
//	FOR(i,1,n){
//		EOR(j,i)if(is_cut[i]&&is_cut[E[j]]) G[i].push_back((edge){E[j],2});
//	}
	dfs(1,0,0);
	Dfs(1,1);
	FOR(i,1,q){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",(dis[a]+dis[b]-2*dis[LCA(a,b)])/2);
	}
	return 0;
}