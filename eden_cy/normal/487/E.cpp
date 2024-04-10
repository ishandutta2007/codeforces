#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define EOR(i,x) for(int i=Head[x];~i;i=Nxt[i])
#define INF 0x3f3f3f3f
#define M 100005

void chkmi(int &x,int y) {if(x>y) x=y;}
void chkmx(int &x,int y) {if(x<y) x=y;}

int Head[M],E[M<<1],Nxt[M<<1],tol;
void Edge(int x,int y) {
	E[tol]=y;Nxt[tol]=Head[x];Head[x]=tol++;
}

struct Heap{
	priority_queue<int,vector<int>,greater<int> > Q;
	priority_queue<int,vector<int>,greater<int> > P;
	void pop(int x) {P.push(x);}
	void push(int x) {Q.push(x);}
	int top() {
		while(!P.empty()&&Q.top()==P.top()) Q.pop(),P.pop();
		return Q.top();
	}
}Heap[M<<1];

int n,m,q;
vector<int> G[M<<1];
vector<int> col[M];
int dfn[M],low[M],Stk[M];
bool is_cut[M];
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
					G[bcc_cnt].push_back(k);
					G[k].push_back(bcc_cnt);
					if(k==y) break;
				}
				G[bcc_cnt].push_back(x);
				G[x].push_back(bcc_cnt);
			}
		} else chkmi(low[x],dfn[y]);
	}
	if(!fr) is_cut[x]=chi_cnt>1;
}
int dep[M<<1],Fa[M<<1],Top[M<<1],sz[M<<1],son[M<<1];
int SgId[M<<1],SgId_cnt;
void dfs(int x,int fr) {
	dep[x]=dep[fr]+1;Fa[x]=fr;sz[x]=1;son[x]=0;
	FOR(i,0,G[x].size()-1) {
		int y=G[x][i];
		if(y==fr) continue;
		dfs(y,x);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]]) son[x]=y;
	}
}
void DFS(int x,int tp) {
	Top[x]=tp;SgId[x]=++SgId_cnt;
	if(son[x]) DFS(son[x],tp);
	FOR(i,0,G[x].size()-1) {
		int y=G[x][i];
		if(y==Fa[x]||y==son[x]) continue;
		DFS(y,y);
	}
}
int val[M];

#define lson L,mid,p<<1
#define rson mid+1,R,p<<1|1

int mn[M<<3],num[M<<1];
void build(int L,int R,int p) {
	if(L==R) {
		mn[p]=num[L];
		return ;
	}
	int mid=L+R>>1;
	build(lson);
	build(rson);
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
}
void Update(int L,int R,int p,int x,int v) {
	if(L==R) {
		mn[p]=v;
		return ;
	}
	int mid=L+R>>1;
	if(x<=mid) Update(lson,x,v);
	else Update(rson,x,v);
	mn[p]=min(mn[p<<1],mn[p<<1|1]);
}
int Query(int L,int R,int p,int l,int r) {
	if(L==l&&R==r) return mn[p];
	int mid=L+R>>1;
	if(r<=mid) return Query(lson,l,r);
	else if(l>mid) return Query(rson,l,r);
	else return min(Query(lson,l,mid),Query(rson,mid+1,r));
}

int LCA_Query(int x,int y) {
	int res=INF;
	while(Top[x]!=Top[y]) {
		if(dep[Top[x]]<dep[Top[y]]) swap(x,y);
		chkmi(res,Query(1,bcc_cnt,1,SgId[Top[x]],SgId[x]));
		x=Fa[Top[x]];
	}
	if(dep[x]<dep[y]) swap(x,y);
	chkmi(res,Query(1,bcc_cnt,1,SgId[y],SgId[x]));
	if(y>n) chkmi(res,val[Fa[y]]);
	return res;
}
char op[5];
int main() {
	memset(Head,-1,sizeof(Head));
	scanf("%d%d%d",&n,&m,&q);
	FOR(i,1,n) scanf("%d",&val[i]);
	FOR(i,1,m) {
		int x,y;
		scanf("%d%d",&x,&y);
		Edge(x,y);
		Edge(y,x);
	}
	bcc_cnt=n;
	Tarjan(1,0);
	dfs(1,0);
	DFS(1,1);
	FOR(i,1,n) FOR(j,0,G[i].size()-1) if(Fa[i]==G[i][j]) Heap[G[i][j]].push(val[i]);
	FOR(i,1,n) num[SgId[i]]=val[i];
	FOR(i,n+1,bcc_cnt) num[SgId[i]]=Heap[i].top();
	build(1,bcc_cnt,1);
	FOR(i,1,q) {
		int x,y;
		scanf("%s%d%d",op,&x,&y);
		if(op[0]=='C') {
			if(Fa[x]) Heap[Fa[x]].pop(val[x]);
			val[x]=y;
			if(Fa[x]) {
				Heap[Fa[x]].push(val[x]);
				Update(1,bcc_cnt,1,SgId[Fa[x]],Heap[Fa[x]].top());
			}
			Update(1,bcc_cnt,1,SgId[x],val[x]);
		} else printf("%d\n",LCA_Query(x,y));
	}
	return 0;
}