#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
#define EOR(i,x) for(int i=Head[x]; ~i; i=Nxt[i])

typedef long long ll;

const int M=(int)3e5+5;

void chkmx(ll &x,ll y) {if(x<y) x=y;}
void chkmi(ll &x,ll y) {if(x>y) x=y;}

inline void rd(int &x) {
	static char c;x=0;
	while(c=getchar(),c<48);
	do x=(x<<3)+(x<<1)+(c^48);
	while(c=getchar(),c>47);
}

int Head[M],E[M<<1],Val[M<<1],Nxt[M<<1],tol;
void Edge(int x,int y,int v) {
	E[tol]=y;Val[tol]=v;Nxt[tol]=Head[x];Head[x]=tol++;
}
struct edge{
	int x,y,v;
}EEE[M];
int Fa[M];
int Find(int x) {return Fa[x]==x?x:Fa[x]=Find(Fa[x]);}

int E_id[M];
void dfs(int x,int fr) {
	EOR(i,x) if(E[i]!=fr) {
		E_id[E[i]]=i^1;dfs(E[i],x);
	}
}

bool del[M];
void DFS(int x,int fr,ll &max_len,ll &len) {
	int y;ll a,b;
	EOR(i,x) if((y=E[i])!=fr && !del[y]) {
		DFS(y,x,a=0,b=0);
		b+=Val[i];
		chkmx(max_len,a);
		chkmx(max_len,b+len);
		chkmx(len,b);
	}
}

int line[M],top;
ll max_len[M],len[M];
ll Tmp[M][2],lmx[M],rmx[M];

int main() {
	memset(Head,-1,sizeof(Head));
	int n;
	rd(n);
	FOR(i,1,n) {
		rd(EEE[i].x);
		rd(EEE[i].y);
		rd(EEE[i].v);
	}
	edge in;
	FOR(i,1,n) Fa[i]=i;
	FOR(i,1,n) {
		int x=Find(EEE[i].x);
		int y=Find(EEE[i].y);
		if(x==y) in=EEE[i];
		else {
			Edge(EEE[i].x,EEE[i].y,EEE[i].v);
			Edge(EEE[i].y,EEE[i].x,EEE[i].v);
			Fa[x]=y;
		}
	}
	
	dfs(in.x,0);
	for(int x=in.y; x!=in.x; x=E[E_id[x]]) line[++top]=x;
	line[++top]=in.x;
	
	FOR(i,1,top) del[line[i]]=true;
	FOR(i,1,top) DFS(line[i],0,max_len[i],len[i]);
	
	ll res,tmp;
	
	tmp=0;
	FOR(i,1,top) {
		Tmp[i][0]=max(Tmp[i-1][0],max(len[i]+tmp,max_len[i]));
		chkmx(tmp,len[i]);
		tmp+=Val[E_id[line[i]]];
	}
	
	tmp=0;
	DOR(i,top,1) {
		Tmp[i][1]=max(Tmp[i+1][1],max(len[i]+tmp,max_len[i]));
		chkmx(tmp,len[i]);
		tmp+=Val[E_id[line[i-1]]];
	}
	
	tmp=0;lmx[1]=len[1];
	FOR(i,2,top) lmx[i]=max(lmx[i-1],len[i]+(tmp+=Val[E_id[line[i-1]]]));
	
	tmp=0;rmx[top]=len[top];
	DOR(i,top-1,1) rmx[i]=max(rmx[i+1],len[i]+(tmp+=Val[E_id[line[i]]]));
	
	res=Tmp[top][0];
	FOR(i,1,top-1) {
		tmp=max(Tmp[i][0],Tmp[i+1][1]);
		chkmx(tmp,lmx[i]+rmx[i+1]+in.v);
		chkmi(res,tmp);
	}
	
	printf("%lld\n",res);
	return 0;
}

// https://codeforc.es/problemset/problem/835/F