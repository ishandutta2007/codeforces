#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n,cnt,cntt,h[100005],root[100005],ans[100005],d[100005],p[100005][20],q;
struct TreeNode{
	int ls,rs,sum;
}t[2000005];
struct Edge{
	int to,next;
}e[100005];
struct Que{
	int k,id;
};
vector<Que> vec[100005];
int NewNode(){
	return ++cntt;
}
void Add_Edge(int x,int y){
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
void Update(int &p,int l,int r,int x){
	if(!p)p=NewNode();
	if(l==r){
		t[p].sum++;
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid)Update(t[p].ls,l,mid,x);
	else Update(t[p].rs,mid+1,r,x);
}
void Merge(int &p,int q,int l,int r){
	if(!p||!q){
		p=p+q;
		return ;
	}
	if(l==r){
		t[p].sum+=t[q].sum;
		return ;
	}
	int mid=(l+r)/2;
	Merge(t[p].ls,t[q].ls,l,mid);
	Merge(t[p].rs,t[q].rs,mid+1,r);
}
int Query(int p,int l,int r,int x){
	if(l==r)return t[p].sum;
	int mid=(l+r)/2;
	if(x<=mid)return Query(t[p].ls,l,mid,x);
	else return Query(t[p].rs,mid+1,r,x);
}
void Solve(int now,int fa){
	Update(root[now],1,n,d[now]);
	for(int i=h[now];i;i=e[i].next){
		int y=e[i].to;
		if(y==fa)continue;
		Solve(y,now);
		Merge(root[now],root[y],1,n);
	}
	for(Que y:vec[now])ans[y.id]=Query(root[now],1,n,y.k);
}
int Climb(int x,int k){
	for(int i=16;i>=0;i--)if(k&(1<<i))x=p[x][i];
	return x;
}
void DFS(int now,int dep){
	d[now]=dep;
	for(int i=1;i<=16;i++)p[now][i]=p[p[now][i-1]][i-1];
	for(int i=h[now];i;i=e[i].next){
		int y=e[i].to;
		p[y][0]=now;
		DFS(y,dep+1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		Add_Edge(x,i);
	}
	scanf("%d",&q);
	DFS(0,0);
	for(int i=1,x,k;i<=q;i++){
		scanf("%d%d",&x,&k);
		int p=Climb(x,k);
		if(p)vec[p].push_back({d[p]+k,i});
	}
	Solve(0,0);
	for(int i=1;i<=q;i++)printf("%d ",max(ans[i]-1,0));
	return 0;
}