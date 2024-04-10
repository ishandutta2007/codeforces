#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 50040
#define re register
#define il inline
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
int n,m,head[N],cnt=0,e_cnt=0,k,root;
int maxp[N],siz[N],d[N],tot=0;
bool vis[N];
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	e_cnt++;
	edge[e_cnt].to=b;
	edge[e_cnt].nxt=head[a];
	head[a]=e_cnt;
}
void get_root(int u,int fa,int total){
	siz[u]=1;
	maxp[u]=0;
	for(re int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa||vis[v])continue;
		get_root(v,u,total);
		siz[u]+=siz[v];
		maxp[u]=max(siz[v],maxp[u]);
	}
	maxp[u]=max(maxp[u],total-siz[u]);
	if(!root||maxp[u]<maxp[root]){
		root=u;
	}
}
il void get_dis(int u,int fa,int dis){
	d[++tot]=dis;
	for(re int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa||vis[v])continue;
		get_dis(v,u,dis+1);
	}
}
il int calc(int u,int dis){
	tot=0;
	get_dis(u,0,dis);
	sort(d+1,d+tot+1);
	int l=1,r=tot,ans=0;
	while(l<r){
		if(d[l]+d[r]>k)r--;
		else ans+=r-l,l++;
	}
	l=1,r=tot;
	while(l<r){
		if(d[l]+d[r]>k-1)r--;
		else ans-=r-l,l++;
	}
	return ans;
}
il int solve(int u){
	vis[u]=true;
	int ans=calc(u,0);
	for(re int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[v])continue;
		ans-=calc(v,1);
		root=0;
		get_root(v,0,siz[v]);
		ans+=solve(root);
	}
	return ans;
}
int main(){
	//freopen("distance.in","r",stdin);
	//freopen("distance.out","w",stdout);
	n=read();k=read();
	for(re int i=1;i<=n-1;i++){
		int u,v;
		u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	maxp[0]=n;
	get_root(1,0,n);
	cout<<solve(root)<<endl;
	return 0;
}