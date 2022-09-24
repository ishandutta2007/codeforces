#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P{
	int to;
	ll val;
};
struct T{
	ll mx,mi,lm,mr,lmr;
}t[800005];
int n,q,st[200005],ed[200005],sign,id[200005],p[200005][20],d[200005],x[200005],y[200005];
vector<P> g[200005];
ll gyh,la=0,w,z[200005],tag[800005],dis[200005];
T operator +(const T &a,const T &b){
	static T ret;
	ret.mx=max(a.mx,b.mx),ret.mi=max(a.mi,b.mi);
	ret.lm=max(max(a.lm,b.lm),a.mx+b.mi),ret.mr=max(max(a.mr,b.mr),b.mx+a.mi);
	ret.lmr=max(max(a.lmr,b.lmr),max(a.lm+b.mx,a.mx+b.mr));
	return ret;
}
void dfs(int x){
	d[x]=d[p[x][0]]+1,st[x]=++sign,id[sign]=x;
	for(int i=1;i<=16;i++)p[x][i]=p[p[x][i-1]][i-1];
	for(P i:g[x]){
		int y=i.to;
		if(y==p[x][0])continue;
		dis[y]=dis[x]+i.val,p[y][0]=x,dfs(y),id[++sign]=x;
	}
	ed[x]=sign;
}
void Build(int p,int l,int r){
	if(l==r)return t[p]={dis[id[l]],-2*dis[id[l]],-dis[id[l]],-dis[id[l]],0},void();
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	t[p]=t[p*2]+t[p*2+1];
}
void Tag(int p,ll x){
	tag[p]+=x,t[p].mx+=x,t[p].mi-=2*x,t[p].lm-=x,t[p].mr-=x;
}
void Pushdown(int p){
	if(tag[p])Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]=0;
}
void Upd(int p,int l,int r,int x,int y,ll z){
	if(x<=l&&r<=y)return Tag(p,z),void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Upd(p*2,l,mid,x,y,z);
	if(mid<y)Upd(p*2+1,mid+1,r,x,y,z);
	t[p]=t[p*2]+t[p*2+1];
}
int main(){
	scanf("%d%d%lld",&n,&q,&w);
	for(int i=1;i<n;i++)scanf("%d%d%lld",&x[i],&y[i],&z[i]),g[x[i]].push_back({y[i],z[i]}),g[y[i]].push_back({x[i],z[i]});
	dfs(1),Build(1,1,sign);
	for(int i=1;i<n;i++)if(p[y[i]][0]==x[i])swap(x[i],y[i]);
	for(int i=1,p;i<=q;i++){
		scanf("%d%lld",&p,&gyh),p=(p+la)%(n-1)+1,gyh=(gyh+la)%w;
		Upd(1,1,sign,st[x[p]],ed[x[p]],gyh-z[p]),z[p]=gyh,printf("%lld\n",la=t[1].lmr);
	}
}