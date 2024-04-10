#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 300030
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
int n,a,b,c,d,S,len,ans;
ll s[N];
struct show{
	int t,p;
	bool operator <(const show b)const{
		return t<b.t;
	}
}g[N];
struct node{
	int l,r;
	ll mn,add;
	inline void Add(ll d){
		mn+=d;
		add+=d;
	}
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
inline void update(int i){
	tree[i].mn=min(tree[ls].mn,tree[rs].mn);
}
inline void pushdown(int i){
	if(tree[i].add){
		tree[ls].Add(tree[i].add);
		tree[rs].Add(tree[i].add);
		tree[i].add=0;
	}
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	tree[i].add=0;
	if(l==r){
		tree[i].mn=s[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
}
void Change(int i,int l,int r,int d){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].Add(d);
		return;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		Change(ls,l,r,d);
	}
	if(r>mid){
		Change(rs,l,r,d);
	}
	update(i);
}
ll Query(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return tree[i].mn;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	ll mn=1LL*inf*inf;
	if(l<=mid){
		mn=min(mn,Query(ls,l,r));
	}
	if(r>mid){
		mn=min(mn,Query(rs,l,r));
	}
	return mn;
}
int main(){
	n=read(),a=read(),b=read(),c=read()-a,d=read()-b,S=read(),len=read();
	for(int i=1;i<=n;++i){
		g[i].t=read(),g[i].p=read();
	}
	sort(g+1,g+n+1);
	ans=inf;
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+(g[i].p?a:-b);
	}
	build(1,1,n);
	g[0].t=-1;
	for(int l=0,r=1;l<=n;++l){
		if(l>0){
			Change(1,l,n,g[l].p?-c:d);
		}
		while(r<=n&&g[r].t-g[l].t<=len+1){
			Change(1,r,n,g[r].p?c:-d);
			++r;
		}
		if(!r||S+Query(1,1,r-1)>=0){
			ans=min(ans,g[l].t+1);
			break;
		}
	}
	build(1,1,n);
	for(int r=n,l=n;r>=1;--r){
		if(g[r].t<len)break;
		while(l>=1&&g[r].t-g[l].t<=len){
			Change(1,l,n,g[l].p?c:-d);
			--l;
		}
		if(S+Query(1,1,r)>=0){
			ans=min(ans,g[r].t-len+1);
		}
		Change(1,r,n,g[r].p?-c:d);
	}
	printf("%d\n",ans==inf?-1:ans);
	return 0;
}