#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n,cnt,cntt,h[1000005],root[1000005],ans[1000005];
int st[4000005],top;
struct TreeNode{
	int ls,rs,maxx,maxp;
	void Clear(){
		ls=rs=maxx=maxp=0;
	}
}t[4000005];
struct Edge{
	int to,next;
}e[2000005];
struct Que{
	int k,id;
};
int NewNode(){
	if(top)return st[top--];
	return ++cntt;
}
void Add_Edge(int x,int y){
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
void Pushup(int p){
	int l=t[p].ls,r=t[p].rs;
	if(t[l].maxx==t[r].maxx){
		t[p].maxx=t[l].maxx,t[p].maxp=t[l].maxp;
		return ;
	}
	if(t[l].maxx>t[r].maxx){
		t[p].maxx=t[l].maxx,t[p].maxp=t[l].maxp;
	}
	else {
		t[p].maxx=t[r].maxx,t[p].maxp=t[r].maxp;
	}
}
void Update(int &p,int l,int r,int x){
	if(!p)p=NewNode();
	if(l==r){
		t[p].maxx++,t[p].maxp=l;
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid)Update(t[p].ls,l,mid,x);
	else Update(t[p].rs,mid+1,r,x);
	Pushup(p);
}
void Merge(int &p,int q,int l,int r){
	if(!p||!q){
		p=p+q;
		return ;
	}
	if(l==r){
		t[p].maxx+=t[q].maxx;
		t[q].Clear(),st[++top]=q;
		return ;
	}
	int mid=(l+r)/2;
	Merge(t[p].ls,t[q].ls,l,mid);
	Merge(t[p].rs,t[q].rs,mid+1,r);
	Pushup(p);
	t[q].Clear(),st[++top]=q;
}
void Solve(int now,int fa,int dep){
    root[now]=++cntt;
	for(int i=h[now];i;i=e[i].next){
		int y=e[i].to;
		if(y==fa)continue;
		Solve(y,now,dep+1);
		Merge(root[now],root[y],1,n);
	}
	Update(root[now],1,n,dep);
	ans[now]=t[root[now]].maxp-dep;
}
int main(){
	scanf("%d",&n);
	for(int i=2,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		Add_Edge(x,y);
		Add_Edge(y,x);
	}
	Solve(1,0,1);
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}