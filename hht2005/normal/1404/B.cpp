#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int hea[maxn],nxt[maxn<<1],to[maxn<<1],d[maxn],A,B,tot,D,DD;
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void dfs(int x,int fa,int dep) {
	if(x==B)DD=dep;
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa) {
			dfs(to[i],x,dep+1);
			D=max(D,d[x]+d[to[i]]+1);
			d[x]=max(d[x],d[to[i]]+1);
		}
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,a,b,da,db;
		scanf("%d%d%d%d%d",&n,&A,&B,&da,&db);
		for(int i=1;i<n;i++) {
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		dfs(A,0,0);
		cerr<<D<<endl;
		if(DD<=da||2*da>=db||2*da>=D)puts("Alice");
		else puts("Bob");
		tot=D=0;
		for(int i=1;i<=n;i++)hea[i]=d[i]=0;
	}
	return 0;
}