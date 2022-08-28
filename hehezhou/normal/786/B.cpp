#include<bits/stdc++.h>
using namespace std;
struct node{
	int lson,rson;
}t[800010];
int tot,cnt,head[800010],root1,root2;
struct edge{
	int u,v,w,next;
}e[3000010];
void addedge(int u,int v,int w){
	e[++tot]=edge{u,v,w,head[u]};
	head[u]=tot;
}
int id1[100010],id2[100010];
void build1(int &x,int l,int r){
	x=++cnt;
	if(l==r){
		id1[l]=x;
		return;
	}
	int mid=(l+r)>>1;
	build1(t[x].lson,l,mid);
	build1(t[x].rson,mid+1,r);
	addedge(t[x].lson,x,0);
	addedge(t[x].rson,x,0);
}
void build2(int &x,int l,int r){
	x=++cnt;
	if(l==r){
		id2[l]=x;
		return;
	}
	int mid=(l+r)>>1;
	build2(t[x].lson,l,mid);
	build2(t[x].rson,mid+1,r);
	addedge(x,t[x].lson,0);
	addedge(x,t[x].rson,0);
}
int a[30],top;
void get_range(int x,int l,int r,int L,int R){
	if(l>R||L>r)return;
	if(L<=l&&r<=R){
		a[++top]=x;
		return;
	}
	int mid=(l+r)>>1;
	get_range(t[x].lson,l,mid,L,R);
	get_range(t[x].rson,mid+1,r,L,R);
}
long long dis[800010];
queue<int>q;
int inque[800010];
void spfa(int s){
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	inque[s]=1;
	q.push(s);
	while(!q.empty()){
		int now=q.front();q.pop();
		inque[now]=0;
		for(int i=head[now];i;i=e[i].next){
			if(dis[e[i].v]>dis[now]+e[i].w){
				dis[e[i].v]=dis[now]+e[i].w;
				if(!inque[e[i].v])q.push(e[i].v),inque[e[i].v]=1;
			}
		}
	}
}
int n,m,s;
int main(){
	scanf("%d%d%d",&n,&m,&s);
	build1(root1,1,n);
	build2(root2,1,n);
	for(int i=1;i<=n;i++)addedge(id1[i],id2[i],0),addedge(id2[i],id1[i],0);
	for(int i=1;i<=m;i++){
		int opt,v,l,r,w,u;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d",&u,&v,&w);
			addedge(id1[u],id2[v],w);
		}else if(opt==2){
			scanf("%d%d%d%d",&u,&l,&r,&w);
			top=0;
			get_range(root2,1,n,l,r);
			for(int i=1;i<=top;i++)addedge(id1[u],a[i],w);
		}else{
			scanf("%d%d%d%d",&u,&l,&r,&w);
			top=0;
			get_range(root1,1,n,l,r);
			for(int i=1;i<=top;i++)addedge(a[i],id2[u],w);
		}
	}
//	for(int i=1;i<=tot;i++)printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
	spfa(id1[s]);
	for(int i=1;i<=n;i++)printf("%lld ",dis[id1[i]]<=10000000000000ll?dis[id1[i]]:-1);
	return 0;
}