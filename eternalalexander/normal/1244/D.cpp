#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
const ll inf=(ll)1<<(ll)60;
int head[maxn]={0},tail=0,n,degr[maxn]={0},c[maxn][4],u,v,w,col[maxn],rnk[maxn],ref[maxn],dfn=0,flag=0;
ll ans=inf;
struct edge {
	int v,next;
}edges[maxn<<1];
void add_edge(int u,int v){
	edges[++tail].v=v;
	edges[tail].next=head[u];
	head[u]=tail;
}

void dfs(int u,int fa=0){
	rnk[u]=++dfn;ref[dfn]=u;
	for(int i=head[u];i;i=edges[i].next){
		int v=edges[i].v;
		if (v==fa)continue;
		dfs(v,u);
	}
}

void dfs1(int p,int upd,ll tmp=0){
	if (flag)return ;
	if (p==n+1){
		if (!upd)ans=std::min(ans,tmp);
		else 
			if (tmp==ans){flag=1;for(int i=1;i<=n;++i)printf("%d ",col[rnk[i]]);return;}
		return;
	}if (p>2){
		col[p]=6-col[p-1]-col[p-2];
		dfs1(p+1,upd,tmp+c[ref[p]][col[p]]);
	}else {
		for(int i=1;i<=3;++i){
			col[p]=i;
			if (i!=col[p-1]&&i!=col[p-2])dfs1(p+1,upd,tmp+c[ref[p]][col[p]]);
		}
	}
}

int main(){
	int min=1;
	scanf("%d",&n);
	for(int i=1;i<=3;++i)for(int j=1;j<=n;++j)scanf("%d",&c[j][i]);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		degr[u]++;degr[v]++;
		add_edge(u,v);add_edge(v,u);
	}for(int i=1;i<=n;++i){
		if (degr[i]<degr[min])min=i;
		if (degr[i]>2){printf("-1");return 0;}
	}dfs(min);dfs1(1,0);std::cout<<ans<<std::endl;dfs1(1,1);
	
	return 0;
}