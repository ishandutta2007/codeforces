#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
const int maxn=22010,maxm=220010,inf=0x3f3f3f3f;
int hea[maxn],cur[maxn],nxt[maxm],to[maxm],w[maxm],d[maxn],q[maxn],tot,S,T;
int bfs() {
	int h=1,e=1;
	memset(d,0,sizeof(d));
	q[1]=S,d[S]=1;
	while(h<=e) {
		int x=q[h++];
		for(int i=hea[x];i;i=nxt[i])
			if(w[i]&&!d[to[i]])
				d[q[++e]=to[i]]=d[x]+1;
	}
	return d[T];
}
int dfs(int x,int f) {
	if(x==T)return f;
	int sum=0;
	for(int &i=cur[x];i&&f;i=nxt[i])
		if(w[i]&&d[to[i]]==d[x]+1) {
			int t=dfs(to[i],min(w[i],f));
			w[i]-=t;
			w[i^1]+=t;
			sum+=t;
			f-=t;
		}
	return sum;
}
inline void ins(int a,int b,int c) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=c;
}
inline void add(int a,int b,int c) {
	ins(a,b,c);
	ins(b,a,0);
}
int sex[10010];
int main() {
	tot=1;
	int n=read(),m=read(),g=read(),ans=0;
	S=n+m+1,T=S+1;
	for(int i=1;i<=n;i++)sex[i]=read();
	for(int i=1;i<=n;i++) {
		int t=read();
		add(S,i,sex[i]*t);
		add(i,T,(sex[i]^1)*t);
	}
	for(int i=1;i<=m;i++) {
		int sex=read(),w=read(),k=read();
		ans+=w;
		for(int j=1;j<=k;j++)
			if(sex)add(i+n,read(),inf);
			else add(read(),i+n,inf);
		if(sex)add(S,i+n,w+g*read());
		else add(i+n,T,w+g*read());
	}
	while(bfs()) {
		memcpy(cur,hea,sizeof(cur));
		ans-=dfs(S,inf);
	}
	printf("%d\n",ans);
	return 0;
}