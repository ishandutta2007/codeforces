#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define N 200040
#define re register
#define il inline
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
int n,m,head[N],cnt=0,e_cnt=0,k,root;
int maxp[N],siz[N],tot=0;
ll d[N],p[N],sum;
bool vis[N];
struct Edge{
	int to,nxt,val;
}edge[N<<1];
void add(int a,int b,int c){
	e_cnt++;
	edge[e_cnt].to=b;
	edge[e_cnt].val=c;
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
		get_dis(v,u,dis+edge[i].val);
	}
}
il ll calc(int u,int dis){
	tot=0;
	get_dis(u,0,dis);
	ll ans=0;
    for(int i=1;i<=tot;i++){
	    int r=d[i]%k;
	    ans+=sum;
	    if(r==0){
		    ans+=p[0]*(d[i]/k);
		    for(int j=1;j<=k;j++){
		    	ans+=p[j]*(d[i]/k+1);
			}
			ans+=d[i]/k;
		}
		else{
			for(int j=0;j<=k-r;j++){
			  	ans+=p[j]*(d[i]/k+1);
			}
			for (int j=k-r+1;j<=k;j++){
				ans+=p[j]*(d[i]/k+2);
			}
			ans+=d[i]/k+1;
		}
	}
	for(int i=1;i<=tot;i++){
	    int r=d[i]%k;
	    p[r]++;
		sum+=d[i]/k;
	}
	return ans;
}
il ll solve(int u){
	vis[u]=true;
	sum=0;
	for(int i=0;i<=20;i++){
		p[i]=0;
	}
	ll ans=0;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[v])continue;
		ans+=calc(v,edge[i].val);
	}
	for(re int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[v])continue;
		root=0;
		get_root(v,0,siz[v]);
		ans+=solve(root);
	}
	return ans;
}
int main(){
	//freopen("jump.in","r",stdin);
	//freopen("jump.out","w",stdout);
	n=read();k=read();
	for(re int i=1;i<=n-1;i++){
		int u,v,w;
		u=read(),v=read(),w=1;
		add(u,v,w);
		add(v,u,w);
	}	
	maxp[0]=n;
	get_root(1,0,n);
	cout<<solve(root)<<endl;
	return 0;
}