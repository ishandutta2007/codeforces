#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
#define maxn 100010
int head[maxn],v[maxn],nxt[maxn],tot=0;
int siz[maxn];
double f[maxn];
void add_edge(int s,int e){tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;}
void dfs1(int u){
	siz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		dfs1(v[i]);
		siz[u]+=siz[v[i]];
	}
}
void dfs2(int u){
	for(int i=head[u];i;i=nxt[i]){
		f[v[i]]=(siz[u]-siz[v[i]]-1)*0.5+f[u]+1;
		dfs2(v[i]);
	}
}
void rd(int &x){x=0;char ch=getchar();while(ch<'0'||ch>'9')ch=getchar();while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}}
int main(){
	rd(n);
	int x;
	for(int i=2;i<=n;++i){
		rd(x);
		add_edge(x,i);
	}
	dfs1(1);
	f[1]=1.0;
	dfs2(1);
	for(int i=1;i<=n;++i)printf("%.2lf ",f[i]);
	return 0;
}