#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 500050
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
int T,n,m,a,b,vis[N],ok,tot;
int cnt,head[N];
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	cnt++;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs(int u,int qwq){
	if(u==qwq)ok=0;
	vis[u]=1;++tot;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[v])continue;
		dfs(v,qwq);
	}
}
int main(){
	T=read();
	while(T--){
		for(int i=1;i<=n;i++)head[i]=0,vis[i]=0;
		for(int i=1;i<=cnt;i++)edge[i].to=edge[i].nxt=0;
		cnt=0;int p=0,q=0;
		n=read(),m=read(),a=read(),b=read();
		for(int i=1;i<=m;i++){
			int u=read(),v=read();
			add(u,v),add(v,u);
		}
		vis[a]=1;
		for(int i=head[a];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(vis[v])continue;
			ok=1;tot=0;
			dfs(v,b);
			if(ok)p+=tot;
		}
		for(int i=1;i<=n;i++)vis[i]=0;
		vis[b]=1;
		for(int i=head[b];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(vis[v])continue;
			ok=1,tot=0;
			dfs(v,a);
			if(ok)q+=tot;
		}
		cout<<1LL*p*q<<endl;
	}
	return 0;
}