#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200020
typedef long long ll;
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
int n,lim,w,maxp[N],siz[N],root,a[N],d[N],len[N];
int cnt,head[N],vis[N],tot;
int bit[N];
inline int lowbit(int x){
	return x&(-x);
}
void Add(int x,int d){
	while(x<=n){
		bit[x]+=d;
		x+=lowbit(x);
	}
}
int Ask(int x){
	if(x>n)x=n;
	int ans=0;
	while(x){
		ans+=bit[x];
		x-=lowbit(x);
	}
	return ans;
}
struct Edge{
	int to,nxt,val;
}edge[N<<1];
void add(int a,int b,int c){
	cnt++;
	edge[cnt].to=b;
	edge[cnt].val=c;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void get_root(int u,int fa,int total){
	siz[u]=1;
	maxp[u]=0;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa||vis[v])continue;
		get_root(v,u,total);
		siz[u]+=siz[v];
		maxp[u]=max(maxp[u],siz[v]);
	}
	maxp[u]=max(maxp[u],total-siz[u]);
	if(!root||maxp[u]<maxp[root]){
		root=u;
	}
}
void get_dis(int u,int fa,int dis,int dep){
	if(dep>lim)return;
	a[++tot]=u;
	d[u]=dis,len[u]=dep;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa||vis[v])continue;
		get_dis(v,u,dis+edge[i].val,dep+1);
	}
}
bool cmp(int i,int j){
	return d[i]<d[j];
}
ll calc(int u,int dis,int dep){
	tot=0;
	get_dis(u,0,dis,dep);
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		Add(len[a[i]]+1,1);
	}
	int l=1,r=tot;
	ll ans=0;
	while(l<r){
		if(d[a[l]]+d[a[r]]<=w){
			Add(len[a[l]]+1,-1);
			ans+=Ask(lim-len[a[l]]+1);
			++l;
		}
		else{
			Add(len[a[r]]+1,-1);
			--r;
		}
	}
	Add(len[a[l]]+1,-1);
	return ans;
}
ll Solve(int u){
	vis[u]=1;
	ll ans=calc(u,0,0);
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[v])continue;
		ans-=calc(v,edge[i].val,1);
		root=0;
		get_root(v,u,siz[v]);
		ans+=Solve(root);
	}
	return ans;
}
int main(){
	n=read(),lim=read(),w=read();
	for(int i=2;i<=n;i++){
		int fa=read(),w=read();
		add(fa,i,w),add(i,fa,w);
	}
	get_root(1,0,n);
	cout<<Solve(root)<<endl;
	return 0;
}