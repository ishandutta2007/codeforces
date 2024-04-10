#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const ll inf=2e18;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,id[N],pos[N],w[N],v[N];
ll a[N];
struct Segment_Tree{
	struct node{
		int l,r;
		ll liw[20],liv[20],et[20];
	}tree[N<<2];
	#define ls i<<1
	#define rs i<<1|1
	void Get(int i,int x){
		for(int j=1;j<=18;++j){
			tree[i].liw[j]=tree[i].liv[j]=0,tree[i].et[j]=inf;
			if(w[x]<(1<<(j-1)))tree[i].liw[j]=w[x]*a[x],tree[i].liv[j]=v[x]*a[x];
			else if(w[x]<(1<<j)&&a[x])tree[i].et[j]=w[x];
		}	
	}
	inline void update(int i){
		for(int j=1;j<=18;++j){
			tree[i].liw[j]=tree[ls].liw[j]+tree[rs].liw[j];
			tree[i].liv[j]=tree[ls].liv[j]+tree[rs].liv[j];
			tree[i].et[j]=min(tree[ls].et[j],tree[ls].liw[j]+tree[rs].et[j]);
		}
	}
	void build(int i,int l,int r){
		tree[i].l=l;
		tree[i].r=r;
		if(l==r){
			Get(i,id[l]);
			return;
		}	
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		update(i);
	}
	void Change(int i,int p){
		if(tree[i].l==tree[i].r){
			Get(i,id[p]);
			return;
		}
		int mid=(tree[i].l+tree[i].r)>>1;
		p<=mid?Change(ls,p):Change(rs,p);
		update(i);
	}
	int now;
	ll c;
	void Renew(){
		while(now>1&&c<(1<<now-2))--now;
	}
	ll Query(int i){
		if(tree[i].l==tree[i].r){
			ll num=min(a[id[tree[i].l]],c/w[id[tree[i].l]]);
			c-=num*w[id[tree[i].l]];
			Renew();
			return num*v[id[tree[i].l]];
		}
		if(tree[i].liw[now]<=c){
			ll val=tree[i].liv[now];
			c-=tree[i].liw[now];
			Renew();
			return val;
		}
		if(tree[i].liw[now-1]<=c&&c<tree[i].et[now-1]){
			ll val=tree[i].liv[now-1];
			c-=tree[i].liw[now-1];
			Renew();
			return val;
		}
		return Query(ls)+Query(rs);
	}
}T;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read(),w[i]=read(),v[i]=read();
		id[i]=i;
	}
	sort(id+1,id+n+1,[&](int i,int j){return make_pair(v[i],-w[i])>make_pair(v[j],-w[j]);});
	for(int i=1;i<=n;++i)pos[id[i]]=i;
	T.build(1,1,n);
	while(m--){
		int opt=read();
		if(opt==1||opt==2){
			int d=read(),x=read();
			if(opt==2)d=-d;
			a[x]+=d;
			x=pos[x];
			T.Change(1,x);
		}
		else{
			T.c=read();
			T.now=18;
			T.Renew();
			printf("%lld\n",T.Query(1));
		}
	}
	return 0;
}