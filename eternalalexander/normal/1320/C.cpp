#include <bits/stdc++.h>
#define maxn 1000005
#define ll long long
const ll inf=1e11;
const int lim=1000000;
int n,m,p,x[maxn],y[maxn],z[maxn],rk[maxn],W[maxn];
ll ans=-inf;
ll A[maxn];
struct node {
	int v,w;
}a[maxn],b[maxn];
bool operator < (node a,node b){
	return a.v<b.v;
}int cmp(int a,int b){return x[a]<x[b];}
struct dgta{
	ll max[maxn<<2],tag[maxn<<2];
	void pushdown(int rt){
		max[rt<<1]+=tag[rt];max[rt<<1|1]+=tag[rt];
		tag[rt<<1]+=tag[rt];tag[rt<<1|1]+=tag[rt];
		tag[rt]=0;
	}
	void build(int l,int r,int rt){
		tag[rt]=0;
		if(l==r){max[rt]=A[l];return;}
		build(l,(l+r)>>1,rt<<1);
		build(((l+r)>>1)+1,r,rt<<1|1);
		max[rt]=std::max(max[rt<<1],max[rt<<1|1]);
	}void add(int l,int r,int L,int R,ll v,int rt){
		if(l>R||r<L||l>r)return;
		if(l<=L&&R<=r){tag[rt]+=v;max[rt]+=v;return;}
		pushdown(rt);
		add(l,r,L,(L+R)>>1,v,rt<<1);
		add(l,r,((L+R)>>1)+1,R,v,rt<<1|1);
		max[rt]=std::max(max[rt<<1],max[rt<<1|1]);
	}
}sgt;
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&a[i].v,&a[i].w);
	for(int i=1;i<=m;++i)
		scanf("%d%d",&b[i].v,&b[i].w);
	std::sort(a+1,a+n+1);
	std::sort(b+1,b+m+1);std::reverse(b+1,b+m+1);
	for(int i=1;i<=p;++i){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		rk[i]=i;
	}std::sort(rk+1,rk+p+1,cmp);
	int p1=0;ll min=inf;
	for(int i=lim;i>=1;--i){
		while(p1<m&&b[p1+1].v>=i){
			p1++;min=std::min(min,(ll)b[p1].w);
		}A[i]=-min;
	}//for(int i=1;i<=lim;++i)printf("%lld ",A[i]);printf("\n");
	sgt.build(1,lim,1);
	p1=0;W[n]=a[n].w;
	for(int i=n-1;i>=1;i--)W[i]=std::min(W[i+1],a[i].w);
	//for(int i=1;i<=n;++i)printf(">%d ",W[i]);printf("\n");
	for(int i=1;i<=n;++i){
		while(p1<p&&x[rk[p1+1]]<a[i].v){
			
			p1++;//printf("+%d %d\n",y[rk[p1]],z[rk[p1]]);
			sgt.add(y[rk[p1]]+1,lim,1,lim,z[rk[p1]],1);
		}//printf("%d %lld\n",i,sgt.max[1]);
		ans=std::max(ans,sgt.max[1]-W[i]);
	}std::cout<<ans;
	return 0;
}