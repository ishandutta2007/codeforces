#include <bits/stdc++.h>
#define maxn 200005
int n,m,u[maxn],v[maxn],dis[maxn],p[maxn],mark[maxn],hd[maxn],tl,l;
std::map<int,int>rc[maxn];
struct edge {
	int v,id,nxt;
}E[maxn<<1];
void add_edge(int u,int v,int id){
	E[++tl].v=v;
	E[tl].id=id;
	E[tl].nxt=hd[u];
	hd[u]=tl;
}
void bfs1(){
	int ans=l-1;
	std::queue<std::pair<int,int> >q[3];
	std::memset(dis,-1,sizeof(dis));
	dis[p[l]]=0;
	for(int i=hd[p[l]];i;i=E[i].nxt)
		q[mark[E[i].id]+1].push(std::make_pair(i,1));
	while(!q[1].empty()||!q[2].empty()){
		std::pair<int,int> id;
		if(q[1].empty()){
			id=q[2].front();q[2].pop();
		}else if(q[2].empty()){
			id=q[1].front();q[1].pop();
		}else {
			std::pair<int,int>a=q[1].front(),b=q[2].front();
			if(a.second==b.second){id=b;q[2].pop();}
			if(a.second<b.second){id=a;q[1].pop();}
			if(a.second>b.second){id=b;q[2].pop();}
		}int x=u[id.first],y=v[id.first];
		if(dis[y]!=-1)continue;
		dis[y]=dis[x]+1;if(mark[id.first])ans--;
	//	printf("%d->%d\n",x,y);
		for(int i=hd[y];i;i=E[i].nxt)
			if(dis[E[i].v]==-1)q[mark[E[i].id]+1].push(std::make_pair(i,dis[y]+1));
	}printf("%d ",ans);
}
void bfs2(){
	int ans=l-1;
	std::queue<std::pair<int,int> >q[3];
	std::memset(dis,-1,sizeof(dis));
	dis[p[l]]=0;
	for(int i=hd[p[l]];i;i=E[i].nxt)
		q[mark[E[i].id]+1].push(std::make_pair(i,1));
	while(!q[1].empty()||!q[2].empty()){
		std::pair<int,int> id;
		if(q[1].empty()){
			id=q[2].front();q[2].pop();
		}else if(q[2].empty()){
			id=q[1].front();q[1].pop();
		}else {
			std::pair<int,int>a=q[1].front(),b=q[2].front();
			if(a.second==b.second){id=a;q[1].pop();}
			if(a.second<b.second){id=a;q[1].pop();}
			if(a.second>b.second){id=b;q[2].pop();}
		}int x=u[id.first],y=v[id.first];
		if(dis[y]!=-1)continue;
		dis[y]=dis[x]+1;if(mark[id.first])ans--;
	//	printf("%d->%d\n",x,y);
		for(int i=hd[y];i;i=E[i].nxt)
			if(dis[E[i].v]==-1)q[mark[E[i].id]+1].push(std::make_pair(i,dis[y]+1));
	}printf("%d ",ans);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u[i],&v[i]);
		std::swap(u[i],v[i]);
		add_edge(u[i],v[i],i);
		rc[u[i]][v[i]]=i;
	}scanf("%d",&l);
	for(int i=1;i<=l;++i){
		scanf("%d",&p[i]);
		if(i>1)
			mark[rc[p[i]][p[i-1]]]=1;
	}bfs1();bfs2();
	return 0;
}