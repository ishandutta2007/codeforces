#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
ll depth[maxn];
int n,u,t,a[maxn],head[maxn]={0},tail=0,cnt=0;
struct edge {
	int v,w,next;
}edges[maxn<<1];
void add_edge(int u,int v,int w){
	edges[++tail].v=v;
	edges[tail].next=head[u];
	edges[tail].w=w;
	head[u]=tail;
}

void dfs(int u,ll lim,int f,int flag=0){
	if (depth[u]-a[u]>lim||flag){cnt++;flag=1;}
	for(int i=head[u];i;i=edges[i].next){
		int v=edges[i].v;
		if (v==f)continue;
		depth[v]=depth[u]+edges[i].w;
		dfs(v,std::min(lim,depth[u]),u,flag);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=2;i<=n;++i){
		scanf("%d%d",&u,&t);
		add_edge(i,u,t);
		add_edge(u,i,t);
	}dfs(1,(ll)1<<(ll)60,0);
	printf("%d",cnt);
	return 0;
}