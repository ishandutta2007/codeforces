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
#define M 200005

typedef long long ll;

bool chkmx(int &x,int y) {return x<y?x=y,true:false;}
bool chkmi(int &x,int y) {return x>y?x=y,true:false;}
int gcd(int x,int y) {return y?gcd(y,x%y):x;}

int Head[M],E[M<<1],Nxt[M<<1],tol;
void Edge(int x,int y) {
	E[tol]=y;Nxt[tol]=Head[x];Head[x]=tol++;
}

char str[M];
int val[M];
int sz[M],mark[M],mx[M];
int tot,Min,root;

map<int,int> cnt;
map<int,int> Tmp;

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
void DFS(int x,int fr,int num) {
	int y;num=gcd(num,val[x]);Tmp[num]++;
	EOR(i,x) if((y=E[i])!=fr&&!mark[y]) DFS(y,x,num);
}
void solve(int x) {
	int y;
	cnt.clear();
	cnt[val[x]]++;
	Ans[val[x]]++;
	map<int,int> :: iterator j,k;
	EOR(i,x) if(!mark[y=E[i]]) {
		Tmp.clear();
		DFS(y,x,val[x]);
		for(j=Tmp.begin();j!=Tmp.end();j++) {
			for(k=cnt.begin();k!=cnt.end();k++) {
				Ans[gcd((*j).first,(*k).first)]+=1ll*(*j).second*(*k).second;
			}
		}
		for(j=Tmp.begin();j!=Tmp.end();j++) {
			cnt[(*j).first]+=(*j).second;
		}
	}
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
	FOR(i,1,n) scanf("%d",&val[i]);
	FOR(i,2,n) {
		int x,y;
		scanf("%d%d",&x,&y);
		Edge(x,y);
		Edge(y,x);
	}
	dfs(1);
	FOR(i,1,200000) if(Ans[i]) {
		printf("%d %lld\n",i,Ans[i]);
	}
	return 0;
}