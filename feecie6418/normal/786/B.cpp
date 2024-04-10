#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
int n,q,S,tot,ls[2000005],rs[2000005];
long long dis[2000005];
vector<int> g[2000005],val[2000005];
void AddEdge(int x,int y,int z){
	g[x].push_back(y),val[x].push_back(z);
}
struct Node {
	int num;
	long long dist;
	bool operator <(const Node yy) const {
		return dist>yy.dist;
	}
};
void Dijkstra() {
	memset(dis,0x3f,sizeof(dis));
	priority_queue<Node> q;
	dis[S]=0;
	q.push({S,0});
	while(!q.empty()) {
		int now=q.top().num;
		if(q.top().dist!=dis[now]) {
			q.pop();
			continue;
		}
		q.pop();
		for(int i=0; i<g[now].size(); i++) {
			int y=g[now][i],v=val[now][i];
			if(dis[y]>dis[now]+v) {
				dis[y]=dis[now]+v;
				q.push({y,dis[y]});
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%lld ",dis[i]==0x3f3f3f3f3f3f3f3fll?-1:dis[i]);
}
void Build(int &p,int &q,int l,int r) {
	if(!p)p=++tot;
	if(!q)q=++tot;
	if(l==r){
		AddEdge(l,p,0),AddEdge(q,l,0);
		return ;
	}
	int mid=(l+r)/2;
	Build(ls[p],ls[q],l,mid),AddEdge(ls[p],p,0),AddEdge(q,ls[q],0);
	Build(rs[p],rs[q],mid+1,r),AddEdge(rs[p],p,0),AddEdge(q,rs[q],0);
}
void Add(int p,int l,int r,int x,int y,int z,int w,int flag) {
	if(x<=l&&r<=y) {
		if(flag)AddEdge(z,p,w);
		else AddEdge(p,z,w);
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid)Add(ls[p],l,mid,x,y,z,w,flag);
	if(mid<y)Add(rs[p],mid+1,r,x,y,z,w,flag);
}
int main() {
	scanf("%d%d%d",&n,&q,&S),tot=n;
	int root1=0,root2=0;
	Build(root1,root2,1,n);
	while(q--){
		int opt,l,r,x,y;
		scanf("%d%d%d%d",&opt,&x,&l,&r);
		if(opt==1)AddEdge(x,l,r);
		if(opt==2)scanf("%d",&y),Add(root2,1,n,l,r,x,y,1);
		if(opt==3)scanf("%d",&y),Add(root1,1,n,l,r,x,y,0);
	}
	Dijkstra();
}