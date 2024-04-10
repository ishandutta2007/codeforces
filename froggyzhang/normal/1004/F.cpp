#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100010
typedef long long ll;
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
int n,Q,x,a[N];
struct node{
	int l,r;
	ll ans;
	vector<pair<int,int> > pre,suf; //   or  
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
inline void update(int i){
	tree[i].ans=tree[ls].ans+tree[rs].ans;
	int v=0;
	for(int u=tree[ls].suf.size()-1;u>=0;--u){
		while(v<(int)tree[rs].pre.size()&&(tree[rs].pre[v].second|tree[ls].suf[u].second)<x){
			++v;
		}
		if(v==(int)tree[rs].pre.size())break;
		tree[i].ans+=(ll)(tree[i].r-tree[rs].pre[v].first+1)*(tree[ls].suf[u].first-(u==(int)tree[ls].suf.size()-1?tree[i].l-1:tree[ls].suf[u+1].first));
	}
	tree[i].pre=tree[ls].pre;
	for(int u=0;u<(int)tree[rs].pre.size();++u){
		int num=tree[rs].pre[u].second|tree[i].pre.back().second;
		if(num^tree[i].pre.back().second){
			tree[i].pre.push_back({tree[rs].pre[u].first,num});
		}
	}
	tree[i].suf=tree[rs].suf;
	for(int u=0;u<(int)tree[ls].suf.size();++u){
		int num=tree[ls].suf[u].second|tree[i].suf.back().second;
		if(num^tree[i].suf.back().second){
			tree[i].suf.push_back({tree[ls].suf[u].first,num});
		}
	}
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	if(l==r){
		tree[i].pre.push_back({l,a[l]});
		tree[i].suf.push_back({r,a[l]});
		tree[i].ans=(a[l]>=x);
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
}
void Change(int i,int p){
	if(tree[i].l==tree[i].r){
		tree[i].pre[0]=make_pair(p,a[p]);
		tree[i].suf[0]=make_pair(p,a[p]);
		tree[i].ans=(a[p]>=x);
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(p<=mid){
		Change(ls,p);
	}
	else{
		Change(rs,p);
	}
	update(i);
}
ll Query(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return tree[i].ans;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	ll tot=0;
	if(l<=mid){
		tot+=Query(ls,l,r);
	}
	if(r>mid){
		tot+=Query(rs,l,r);
	}
	if(l<=mid&&r>mid){
		int v=0;
		for(int u=tree[ls].suf.size()-1;u>=0;--u){
			if(tree[ls].suf[u].first<l)continue;
			while(v<(int)tree[rs].pre.size()&&(tree[rs].pre[v].second|tree[ls].suf[u].second)<x){
				++v;
			}
			if(v==(int)tree[rs].pre.size()||tree[rs].pre[v].first>r)break;
			tot+=(ll)(min(r,tree[i].r)-tree[rs].pre[v].first+1)*(tree[ls].suf[u].first-max(l-1,(u==(int)tree[ls].suf.size()-1?tree[i].l-1:tree[ls].suf[u+1].first)));
		}
	}
	return tot;
}
int main(){
	n=read(),Q=read(),x=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	build(1,1,n);
	while(Q--){
		int opt=read();
		if(opt==1){
			int p=read();
			a[p]=read();
			Change(1,p);
		}
		else{
			int l=read(),r=read();
			printf("%lld\n",Query(1,l,r));
		}
	}
	return 0;
}