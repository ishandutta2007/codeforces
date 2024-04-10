#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define EOR(i,x) for(int i=Head[x];~i;i=Nxt[i])
#define INF 0x3f3f3f3f
#define M 200005
#define N 20

typedef long long ll;

bool chkmx(int &x,int y) {return x<y?x=y,true:false;}
bool chkmi(int &x,int y) {return x>y?x=y,true:false;}

int Head[M],E[M<<1],Nxt[M<<1],tol;
void Edge(int x,int y) {
	E[tol]=y;Nxt[tol]=Head[x];Head[x]=tol++;
}

char str[M];
int val[M];
int sz[M],mark[M],mx[M];
int tot,Min,root;

int sum[1<<N];
ll Ans[M];

void dfs_sz(int x,int fr) {
	int y;sz[x]=1;mx[x]=0;
	EOR(i,x) if((y=E[i])!=fr&&!mark[y]) {
		dfs_sz(y,x);
		sz[x]+=sz[y];
		chkmx(mx[x],sz[y]);
	}
}
void dfs_rt(int x,int fr) {
	chkmx(mx[x],tot-sz[x]);
	if(chkmi(Min,mx[x])) root=x;
	EOR(i,x) if(E[i]!=fr&&!mark[E[i]]) dfs_rt(E[i],x);
}
int Get(int x,int fr,int f) {
	int tmp=0,y;
	f^=1<<val[x];
	if(!f||!(f^(f&-f))) tmp=1;
	EOR(i,x) if((y=E[i])!=fr&&!mark[y]) {
		tmp+=Get(y,x,f);
	}
	return tmp;
}
void Add(int x,int fr,int f) {
	int y;f^=1<<val[x];sum[f]++;
	EOR(i,x) if((y=E[i])!=fr&&!mark[y]) Add(y,x,f);
}
void Del(int x,int fr,int f) {
	int y;f^=1<<val[x];sum[f]--;
	EOR(i,x) if((y=E[i])!=fr&&!mark[y]) Del(y,x,f);
}
void calc(int x,int fr,int f) {
	int y;f^=1<<val[x];
	Ans[x]+=sum[f];
	FOR(i,0,19) Ans[x]+=sum[f^(1<<i)];
	EOR(i,x) if((y=E[i])!=fr&&!mark[y]) {
		Ans[x]-=Ans[y];
		calc(y,x,f);
		Ans[x]+=Ans[y];
	}
}
void solve(int x) {
	Add(x,0,0);
	int y;ll tmp=0;
	EOR(i,x) if(!mark[y=E[i]]) {
		Del(y,x,1<<val[x]);
		tmp-=Ans[y];
		calc(y,x,0);
		tmp+=Ans[y];
		Add(y,x,1<<val[x]);
	}
	int cnt=Get(x,0,0);
	Ans[x]+=(tmp-cnt+1)/2+cnt;
	Del(x,0,0);
}
void dfs(int x) {
	dfs_sz(x,0);
	Min=INF;
	tot=sz[x];
	dfs_rt(x,0);
	x=root;
	solve(x);
	mark[x]=1;
	EOR(i,x) if(!mark[E[i]]) dfs(E[i]);
}
int main() {
	memset(Head,-1,sizeof(Head));
	int n;
	scanf("%d",&n);
	FOR(i,2,n) {
		int x,y;
		scanf("%d%d",&x,&y);
		Edge(x,y);
		Edge(y,x);
	}
	scanf("%s",str+1);
	FOR(i,1,n) val[i]=(int)str[i]-'a';
	dfs(1);
	FOR(i,1,n) printf("%lld ",Ans[i]);
	putchar('\n');
	return 0;
}