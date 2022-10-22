#include<map>
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

typedef long long ll;

bool chkmi(int &x,int y) {return x>y?x=y,true:false;}
bool chkmx(int &x,int y) {return x<y?x=y,true:false;}

int Head[M],Nxt[M<<1],E[M<<1],Val[M<<1],tol;
void Edge(int x,int y,int v) {
	E[tol]=y;Val[tol]=v;Nxt[tol]=Head[x];Head[x]=tol++;
}

int Mod;
ll H[M];

struct node{
	ll x,y;
};
node extgcd(ll x,ll y) {
	if(!y) return (node){1,0};
	else {
		node tmp=extgcd(y,x%y);
		return (node){tmp.y,tmp.x-x/y*tmp.y};
	}
}
ll Get(ll x,ll y) {
//	extgcd(x,Mod);
//	cerr<<"----"<<endl;
	return (extgcd(x,Mod).x*(-y)%Mod+Mod)%Mod;
}

int sz[M],mx[M],mark[M];
int tot,Min,root;
void dfs_sz(int x,int fr) {
	sz[x]=1;mx[x]=0;
	EOR(i,x) if(!mark[E[i]]&&E[i]!=fr) {
		dfs_sz(E[i],x);
		sz[x]+=sz[E[i]];
		chkmx(mx[x],sz[E[i]]);
	}
}
void dfs_rt(int x,int fr) {
	chkmx(mx[x],tot-sz[x]);
	if(chkmi(Min,mx[x])) root=x;
	EOR(i,x) if(!mark[E[i]]&&E[i]!=fr) dfs_rt(E[i],x);
}
ll res;
map<int,int> cnt[2];
int Que[2][M];
int top1,top2;
void DFS(int x,int fr,ll num1,ll num2,int len) {
	if(!num1) res++;
	if(!num2) res++;
	int tmp=Get(H[len],num2);
	res+=cnt[0][num1];
	res+=cnt[1][tmp];
	Que[0][++top1]=tmp;
	Que[1][++top2]=num1;
	EOR(i,x) if(!mark[E[i]]&&E[i]!=fr) {
		DFS(E[i],x,(num1+Val[i]*H[len])%Mod,(num2*10+Val[i])%Mod,len+1);
	}
}
void solve(int x) {
	cnt[0].clear();
	cnt[1].clear();
	EOR(i,x) {
		if(mark[E[i]]) continue;
		top1=top2=0;
		DFS(E[i],x,Val[i]%Mod,Val[i]%Mod,1);
		FOR(i,1,top1) cnt[0][Que[0][i]]++;
		FOR(i,1,top2) cnt[1][Que[1][i]]++;
	}
}
void dfs(int x) {
	dfs_sz(x,0);
	Min=INF;
	tot=sz[x];
	dfs_rt(x,0);
	x=root;
	mark[x]=1;
	solve(x);
	EOR(i,x) if(!mark[E[i]]) dfs(E[i]);
}
int main() {
	memset(Head,-1,sizeof(Head));
	int n;
	scanf("%d%d",&n,&Mod);
	H[0]=1%Mod;
	FOR(i,1,n) H[i]=H[i-1]*10%Mod;
	FOR(i,2,n) {
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		x++;y++;
		Edge(x,y,v);
		Edge(y,x,v);
	}
	dfs(1);
	printf("%lld\n",res);
	return 0;
}