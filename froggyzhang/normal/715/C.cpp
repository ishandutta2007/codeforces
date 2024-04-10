#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
#define N 100010
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
int n,maxp[N],siz[N],root,tot,len[N],d[N],cnt,head[N],vis[N];
map<ll,int> mp;
ll x,y,m,p10[N];
ll exgcd(ll a,ll b){
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll g=exgcd(b,a%b);
	ll t=x;
	x=y;
	y=t-a/b*y;
	return g;
}
ll Inv(ll a,ll b){
	x=y=0;
	exgcd(a,b);
	return (x%m+m)%m;
}
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
void get_dis(int u,int fa,ll num1,ll num2,int dep){
	if(dep>0){
		mp[num2%m]++,d[++tot]=num1%m,len[tot]=dep;
	}
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[v]||v==fa)continue;
		get_dis(v,u,(num1*10+edge[i].val)%m,(num2+edge[i].val*p10[dep]%m)%m,dep+1);
	}
}
ll calc(int u,ll num,int dep){
	tot=0;
	mp.clear();
	get_dis(u,0,num,num,dep);
	ll ans=0;
	for(int i=1;i<=tot;i++){
		ll tmp=(m-d[i]*Inv(p10[len[i]],m)%m+m)%m;
		ans+=mp[tmp];
		if(!dep)ans+=(d[i]==0);
	}
	if(!dep)ans+=mp[0];
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
	n=read(),m=read();
	p10[0]=1;
	for(int i=1;i<=n;i++){
		p10[i]=p10[i-1]*10%m;
	}
	for(int i=1;i<=n-1;i++){
		int u=read()+1,v=read()+1,w=read();
		add(u,v,w),add(v,u,w);
	}
	root=0;
	get_root(1,0,n);
	cout<<Solve(root)<<endl;
	return 0;
}