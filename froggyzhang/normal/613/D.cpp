#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 200200
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,Q,cnt,head[N],dep[N],top[N],son[N],siz[N],f[N],a[N],num,dfn[N],in[N];
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	cnt++;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs1(int u,int fa,int deep){
	f[u]=fa;
	dep[u]=deep;
	siz[u]=1;
	int maxson=-1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs1(v,u,deep+1);
		siz[u]+=siz[v];
		if(siz[v]>maxson){
			son[u]=v;
			maxson=siz[v];
		}
	}
}
void dfs2(int u,int topf){
	dfn[u]=++num;
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==son[u]||v==f[u])continue;
		dfs2(v,v);
	}
}
int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}

bool cmp(int i,int j){
	return dfn[i]<dfn[j];
}
void Clear(int n){
	for(int i=1;i<=n;i++){
		in[a[i]]=0;
	}
}
int st[N];
int dfs3(int u){
	int ans=0;
	if(in[u]){
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			ans+=dfs3(v);
			if(in[v]){
				++ans,in[v]=0;
			}
		}
	}
	else{
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			ans+=dfs3(v);
			in[u]+=in[v];
			in[v]=0;
		}
		if(in[u]>1){
			in[u]=0,++ans;
		}
	}
	head[u]=0;
	return ans;
}
void Solve(int n){
	sort(a+1,a+n+1,cmp);
	static int top=0;
	st[top=1]=1;
	for(int i=1;i<=n;i++){
		int u=a[i];
		if(u==1)continue;
		int lca=LCA(u,st[top]);
		while(top>1&&dfn[st[top-1]]>=dfn[lca]){
			add(st[top-1],st[top]),--top;
		}
		if(st[top]^lca){
			add(lca,st[top--]),st[++top]=lca;
		}
		st[++top]=u;
	}
	while(top>1)add(st[top-1],st[top]),--top;
	printf("%d\n",dfs3(1));
	in[1]=0;
}
int main(){
	n=read();
	for(int i=1;i<=n-1;i++){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	Q=read();
	memset(head,0,sizeof(head));
	while(Q--){
		int k=read();
		for(int i=1;i<=k;i++){
			a[i]=read();
			in[a[i]]=1;
		}
		bool flag=false;
		for(int i=1;i<=k;i++){
			if(in[f[a[i]]]){
				printf("-1\n");
				flag=true;
				break;
			}
		}
		if(flag){
			Clear(k);continue;
		}
		Solve(k);
	}
	return 0;
}