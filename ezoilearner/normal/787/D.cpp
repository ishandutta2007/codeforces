#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=9223372036854775807ll;
int n,m,s;
#define V 900010
#define E 11000010
int head[V],v[E],w[E],nxt[E],tot=0;
void add_edge(int s,int e,int t){tot++;v[tot]=e;w[tot]=t;nxt[tot]=head[s];head[s]=tot;}
// 
struct Node{
	int ls,rs;
}tree[V];
int cnt;
int root1,root2;
vector<int> ans[2];
void Build1(int &k,int l,int r){
	k=++cnt;
	for(int i=l;i<=r;++i)add_edge(i,k,0);
	if(l==r)return;
	int mid=(l+r)>>1;
	Build1(tree[k].ls,l,mid);
	Build1(tree[k].rs,mid+1,r);
}
void Build2(int &k,int l,int r){
	k=++cnt;
	for(int i=l;i<=r;++i)add_edge(k,i,0);
	if(l==r)return;
	int mid=(l+r)>>1;
	Build2(tree[k].ls,l,mid);
	Build2(tree[k].rs,mid+1,r); 
}
void Query(int k,int l,int r,int L,int R,int id){
	if(l==L&&r==R){ans[id].push_back(k);return;}
	int mid=(l+r)>>1;
	if(R<=mid)Query(tree[k].ls,l,mid,L,R,id);
	else if(mid<L)Query(tree[k].rs,mid+1,r,L,R,id);
	else{
		Query(tree[k].ls,l,mid,L,mid,id);
		Query(tree[k].rs,mid+1,r,mid+1,R,id);
	}
}
//Dijkstra
struct HeapNode{
	int u;
	ll d;
	bool operator <(const HeapNode &z)const{return d>z.d;}
};
ll dis[V];
priority_queue<HeapNode> Q;
void Dijkstra(){
	for(int i=1;i<=cnt;++i)dis[i]=inf;
	dis[s]=0;
	Q.push((HeapNode){s,0});
	while(!Q.empty()){
		HeapNode node=Q.top();
		Q.pop();
		if(node.d!=dis[node.u])continue;
		for(int i=head[node.u];i;i=nxt[i])
		if(dis[node.u]+w[i]<dis[v[i]]){
			dis[v[i]]=dis[node.u]+w[i];
			Q.push((HeapNode){v[i],dis[v[i]]});
		}
	}
}
void rd(int &x){x=0;char ch=getchar();while(ch<'0'||ch>'9')ch=getchar();while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}}
int main(){
	rd(n);rd(m);rd(s);
	cnt=n;
	Build1(root1,1,n);
	Build2(root2,1,n);
	int opt,u,v,l,r,w;
	for(int i=1;i<=m;++i){
		rd(opt);
		ans[0].clear();ans[1].clear();
		if(opt==1){
			rd(u);rd(v);
			Query(root1,1,n,u,u,0);
			Query(root2,1,n,v,v,1);
		}else if(opt==2){
			rd(u);rd(l);rd(r);
			Query(root1,1,n,u,u,0);
			Query(root2,1,n,l,r,1);
		}else{
			rd(v);rd(l);rd(r);
			Query(root1,1,n,l,r,0);
			Query(root2,1,n,v,v,1);
		}
		rd(w);
		for(int i=0;i<ans[0].size();++i)
		for(int j=0;j<ans[1].size();++j)
		add_edge(ans[0][i],ans[1][j],w);
	}
	Dijkstra();
	for(int i=1;i<=n;++i)
	if(dis[i]!=inf)printf("%lld ",dis[i]);
	else printf("-1 ");
	return 0;
}