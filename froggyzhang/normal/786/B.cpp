#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
#define N 1000200
const int B=500000;
const ll inf=0x3f3f3f3f3f3fll;
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
int n,m,s,vis[N],head[N],cnt,seg[2][N],tt;
ll dis[N];
struct node{
	int l,r;
}tree[N<<1];
#define ls (i<<1)
#define rs (i<<1|1)
struct Edge{
	int to,nxt,val;
}edge[N<<1];
void add(int a,int b,int c){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].val=c;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	if(l==r){
		seg[0][i]=seg[1][i]=l;
		return;
	}
	int mid=(l+r)>>1;
	seg[0][i]=++tt,seg[1][i]=++tt;
	build(ls,l,mid);
	build(rs,mid+1,r);
	add(seg[0][ls],seg[0][i],0),add(seg[0][rs],seg[0][i],0);
	add(seg[1][i],seg[1][ls],0),add(seg[1][i],seg[1][rs],0);
}
void Change(int i,int l,int r,int u,int w,int p){
	if(tree[i].l>=l&&tree[i].r<=r){
		if(p)add(seg[0][i],u,w);
		else add(u,seg[1][i],w);
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		Change(ls,l,r,u,w,p);
	}
	if(r>mid){
		Change(rs,l,r,u,w,p);
	}
}
void Dijkstra(int S){
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
	q.push(make_pair(0,S));
	dis[S]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].val){
				dis[v]=dis[u]+edge[i].val;
				q.push(make_pair(dis[v],v));
			} 
		}
	}
}
int main(){
	n=read(),m=read(),s=read();
	tt=n;
	build(1,1,n);
	for(int i=1;i<=m;++i){
		int opt=read();
		if(opt==1){
			int u=read(),v=read(),w=read();
			add(u,v,w);
		}
		else if(opt==2){
			int u=read(),l=read(),r=read(),w=read();
			Change(1,l,r,u,w,0);
		}
		else{
			int u=read(),l=read(),r=read(),w=read();
			Change(1,l,r,u,w,1);
		}
	}
	Dijkstra(s);
	for(int i=1;i<=n;++i){
		printf("%lld ",dis[i]>inf?-1:dis[i]);
	}
	return 0;
}