#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
int n,cnt,cntt,h[100005],p[100005],root[100005];
long long ans[100005];
struct TreeNode{
	int ls,rs,maxcnt;
	long long maxsum;
}t[3000005];
struct Edge{
	int to,next;
}e[200005];
int NewNode(){
	return ++cntt;
}
void Add_Edge(int x,int y){
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
void Pushup(int p){
	if(!t[p].ls&&!t[p].rs)return ;
	if(t[t[p].ls].maxcnt>t[t[p].rs].maxcnt){
		t[p].maxcnt=t[t[p].ls].maxcnt;
		t[p].maxsum=t[t[p].ls].maxsum;
	}
	else if(t[t[p].ls].maxcnt<t[t[p].rs].maxcnt){
		t[p].maxcnt=t[t[p].rs].maxcnt;
		t[p].maxsum=t[t[p].rs].maxsum;
	}
	else {
		t[p].maxcnt=t[t[p].rs].maxcnt;
		t[p].maxsum=t[t[p].ls].maxsum+t[t[p].rs].maxsum;
	}
}
void Update(int &p,int l,int r,int x){
	if(!p)p=NewNode();
	if(l==r){
		t[p].maxcnt=1;
		t[p].maxsum=l;
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
		t[p].maxcnt+=t[q].maxcnt;
		return ;
	}
	int mid=(l+r)/2;
	Merge(t[p].ls,t[q].ls,l,mid);
	Merge(t[p].rs,t[q].rs,mid+1,r);
	Pushup(p);
}
void Solve(int now,int fa){
	Update(root[now],1,100000,p[now]);
	for(int i=h[now];i;i=e[i].next){
		int y=e[i].to;
		if(y==fa)continue;
		Solve(y,now);
		Merge(root[now],root[y],1,100000);
	}
	ans[now]=t[root[now]].maxsum;
}
int main(){
	//t[0].maxs=-0x3f3f3f3f;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		Add_Edge(x,y);
		Add_Edge(y,x);
	}
	Solve(1,0);
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
	return 0;
}