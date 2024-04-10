#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
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
int n,head[N],root,d[N],cnt,mn,dep[N],tot[N],mx;
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs(v,u);
	}
	if(d[u]==1&&!(dep[u]&1)){
		mn=3;
	}
}
int main(){
	n=read();
	for(int i=1;i<=n-1;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
		++d[u],++d[v];
	}
	for(int i=1;i<=n;++i){
		if(d[i]==1){
			root=i;
			++tot[edge[head[i]].to];
		}
	}
	mn=1;
	dfs(root,0);
	mx=n-1;
	for(int i=1;i<=n;++i){
		if(tot[i]>1)mx-=tot[i]-1;
	}
	printf("%d %d\n",mn,mx);
	getchar(),getchar();
	return 0;
}