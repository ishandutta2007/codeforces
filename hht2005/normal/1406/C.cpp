#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int hea[maxn],nxt[maxn<<1],to[maxn<<1],siz[maxn],Min,A,B,X,Y,tot,n;
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void dfs(int x,int fa) {
	siz[x]=1;
	int Max=0;
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa) {
			dfs(to[i],x);
			Max=max(Max,siz[to[i]]);
			siz[x]+=siz[to[i]];
		}
	Max=max(Max,n-siz[x]);
	if(Min>Max) {
		Min=Max;
		A=x,B=0;
	} else if(Min==Max)B=x;
}
void dfs1(int x,int fa) {
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa) {
			X=x,Y=to[i];
			dfs1(to[i],x);
		}
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int a,b;
		scanf("%d",&n);
		for(int i=1;i<n;i++) {
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		Min=1e9,A=0,B=0;
		dfs(1,0);
		if(!B) {
			printf("%d %d\n",a,b);
			printf("%d %d\n",a,b);
		} else {
			dfs1(A,B);
			printf("%d %d\n",X,Y);
			printf("%d %d\n",Y,B);
		}
		for(int i=1;i<=n;i++)hea[i]=0;
		tot=0;
	}
	return 0;
}