#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n,cnt,cntt,h[500005],root[500005],ans[500005],d[500005],q,val[500005];
struct TreeNode{
	int ls,rs,sum;
}t[10000005];
struct Edge{
	int to,next;
}e[500005];
struct Que{
	int k,id;
};
vector<Que> vec[500005];
int NewNode(){
	return ++cntt;
}
void Add_Edge(int x,int y){
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
void Update(int &p,int l,int r,int x,int v){
	if(!p)p=NewNode();
	if(l==r){
		t[p].sum^=v;
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid)Update(t[p].ls,l,mid,x,v);
	else Update(t[p].rs,mid+1,r,x,v);
}
void Merge(int &p,int q,int l,int r){
	if(!p||!q){
		p=p+q;
		return ;
	}
	if(l==r){
		t[p].sum^=t[q].sum;
		return ;
	}
	int mid=(l+r)/2;
	Merge(t[p].ls,t[q].ls,l,mid);
	Merge(t[p].rs,t[q].rs,mid+1,r);
}
int Query(int p,int l,int r,int x){
	if(l==r){
		return __builtin_popcount(t[p].sum)<2;
	}
	int mid=(l+r)/2;
	if(x<=mid)return Query(t[p].ls,l,mid,x);
	else return Query(t[p].rs,mid+1,r,x);
}
void Solve(int now,int fa){
	Update(root[now],1,n,d[now],val[now]);
	for(int i=h[now];i;i=e[i].next){
		int y=e[i].to;
		if(y==fa)continue;
		Solve(y,now);
		Merge(root[now],root[y],1,n);
	}
	for(Que y:vec[now])ans[y.id]=Query(root[now],1,n,y.k);
}
void DFS(int now,int fa,int dep){
	d[now]=dep;
	for(int i=h[now];i;i=e[i].next){
		int y=e[i].to;
		if(y==fa)continue;
		DFS(y,now,dep+1);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2,x;i<=n;i++){
		scanf("%d",&x);
		Add_Edge(x,i);
	}
	char xxx;
	for(int i=1;i<=n;i++)cin>>xxx,val[i]=1<<(xxx-'a');
	DFS(1,0,1);
	for(int i=1,x,k;i<=q;i++){
		scanf("%d%d",&x,&k);
		vec[x].push_back({k,i});
	}
	Solve(1,0);
	for(int i=1;i<=q;i++)puts(ans[i]?"Yes":"No");
	return 0;
}