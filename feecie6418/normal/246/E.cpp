#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
int n,cnt,cntt,h[100005],root[100005],ans[100005],d[100005],q,val[100005],cnttt,cntttt;
set<int> s[2000005];
map<string,int> mp;
struct TreeNode{
	int ls,rs,id;
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
void Update(int &p,int l,int r,int x,int y){
	if(!p)p=NewNode();
	if(l==r){
		if(!t[p].id)t[p].id=++cntttt;
		s[t[p].id].insert(y);
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid)Update(t[p].ls,l,mid,x,y);
	else Update(t[p].rs,mid+1,r,x,y);
}
void Merge(int &p,int q,int l,int r){
	if(!p||!q){
		p=p+q;
		return ;
	}
	if(l==r){
		if(!t[p].id)t[p].id=t[q].id;
		else {
			if(s[t[p].id].size()<s[t[q].id].size())swap(t[p].id,t[q].id);
			for(set<int>::iterator it=s[t[q].id].begin();it!=s[t[q].id].end();it++)s[t[p].id].insert(*it);
			s[t[q].id].clear();
		}
		return ;
	}
	int mid=(l+r)/2;
	Merge(t[p].ls,t[q].ls,l,mid);
	Merge(t[p].rs,t[q].rs,mid+1,r);
}
int Query(int p,int l,int r,int x){
	if(l==r)return s[t[p].id].size();
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
void DFS(int now,int dep){
	d[now]=dep;
	for(int i=h[now];i;i=e[i].next){
		int y=e[i].to;
		DFS(y,dep+1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		string str;
		cin>>str;
		if(!mp[str])val[i]=mp[str]=++cnttt;
		else val[i]=mp[str];
		scanf("%d",&x);
		Add_Edge(x,i);
	}
	scanf("%d",&q);
	DFS(0,0);
	for(int i=1,x,k;i<=q;i++){
		scanf("%d%d",&x,&k);
		if(d[x]+k<=n)vec[x].push_back({d[x]+k,i});
	}
	Solve(0,0);
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}