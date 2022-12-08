#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=40010,maxm=400010,M=1e9;
const ll inf=1e15;
int hea[maxn],cur[maxn],nxt[maxm],to[maxm],d[maxn],q[maxn],h,e,S,T,tot;
ll w[maxm];
void ins(int a,int b,ll ww) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=ww;
}
void add(int a,int b,ll ww) {
	ins(a,b,ww);
	ins(b,a,0);
}
int bfs() {
	memset(d,0,sizeof(d));
	d[S]=1;
	q[h=e=1]=S;
	while(h<=e) {
		int x=q[h++];
		for(int i=hea[x]; i; i=nxt[i])
			if(w[i]&&!d[to[i]]) {
				d[to[i]]=d[x]+1;
				q[++e]=to[i];
			}
	}
	return d[T];
}
ll dfs(int x,ll f) {
	if(x==T)return f;
	ll sum=0;
	for(int &i=cur[x]; i&&f; i=nxt[i])
		if(w[i]&&d[x]+1==d[to[i]]) {
			int t=dfs(to[i],min(w[i],f));
			w[i]-=t,w[i^1]+=t;
			f-=t,sum+=t;
		}
	return sum;
}
ll sw[30];
int a[4000],b[4000],f[maxn],n,m,c;
int bh(int i,int j) {
	return (i-1)*(n+1)+j;
}
void Dfs(int x) {
	f[x]=1;
	for(int i=hea[x];i;i=nxt[i])
		if(w[i]&&!f[to[i]])Dfs(to[i]);
}
int main() {
	tot=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",a+i,b+i,&c);
		sw[a[i]]+=c;
		sw[b[i]]-=c;
	}
	S=n*n+n+1,T=S+1;
	for(int i=1;i<=n;i++) {
		add(S,bh(i,1),inf);
		for(int j=2;j<=n+1;j++)
			add(bh(i,j-1),bh(i,j),1ll*sw[i]*(j-2)+M);
		add(bh(i,n+1),T,inf);
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++)
			add(bh(b[i],j),bh(a[i],j+1),inf);
		add(bh(b[i],n+1),T,inf);
	}
	ll sum=-n*M;
	while(bfs()) {
		memcpy(cur,hea,sizeof(hea));
		sum+=dfs(S,inf);
	}
	Dfs(S);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++)
			if(f[bh(i,j)]&&!f[bh(i,j+1)])
				printf("%d ",j-1);
	}
	puts("");
	return 0;
}