#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define N 3030
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
int n,head[N],cnt,roots[N],tot,bel[N],now,dfn[N],num;
bool isroot[N];
double ans;
int st[N],top;
struct Edge{
	int to,nxt;
}edge[N<<1]; 
void add(int a,int b){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void get_cir(int u,int in_edge){
	st[++top]=u;
	dfn[u]=++num;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(i==in_edge)continue;
		if(dfn[v]){
			if(dfn[v]>dfn[u])continue;
			for(int j=top;j>=1;--j){
				roots[++tot]=st[j];
				isroot[st[j]]=true;
				if(st[j]==v)break;
			}
		}
		else get_cir(v,i^1);
	}
	--top;
}
void dfs2(int u,int fa,int dep){
//	cout<<"  now:  "<<u<<" "<<dep<<endl;
	ans+=1.0/dep;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa||(isroot[v]&&bel[u]^v))continue;
		dfs2(v,u,dep+1);
	}
}
void dfs3(int u,int fa,int x,int y,int z,int dep){
	ans+=1.0/(x+dep+y)+1.0/(x+dep+z)-1.0/(x+y+z+dep);
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa||isroot[v])continue;
		dfs3(v,u,x,y,z,dep+1);
	}
}
void dfs1(int u,int fa,int dep){
	dfs2(u,0,1);
	for(int i=now%tot+1;i^now;i=i%tot+1){
		dfs3(roots[i],0,dep,abs(now-i)-1,tot-abs(now-i)-1,1);
	}
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(isroot[v]||v==fa)continue;
		dfs1(v,u,dep+1);
	}
}
void init(int u,int fa,int qwq){
	bel[u]=qwq;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa||isroot[v])continue;
		init(v,u,qwq);
	}
}
int main(){
	n=read(),cnt=1;
	for(int i=1;i<=n;++i){
		int u=read()+1,v=read()+1;
		add(u,v),add(v,u);
	}
	get_cir(1,0);
	for(int i=1;i<=tot;++i){
		init(roots[i],0,roots[i]);
	}
	for(int i=1;i<=tot;++i){
		now=i;
		dfs1(roots[i],0,1);
	}
	printf("%.10lf\n",ans);
	return 0;
}