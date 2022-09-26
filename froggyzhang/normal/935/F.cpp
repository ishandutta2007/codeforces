#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
#define N 100010
const ll inf=0x3f3f3f3f3f3f3f3fll;
inline int read(){
	int x=0,f=1;
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
int n,Q;
ll a[N],tot;
set<int> up,down;
struct node{
	int l,r;
	ll mn;
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
inline ll Abs(ll x){
	return x>=0?x:-x;
}
inline void update(int i){
	tree[i].mn=min(tree[ls].mn,tree[rs].mn);
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	tree[i].mn=inf;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
void Change(int i,int p,ll d){
	if(tree[i].l==tree[i].r){
		tree[i].mn=d;
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(p<=mid){
		Change(ls,p,d);
	}
	else{
		Change(rs,p,d);
	}
	update(i);
}
ll Query(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return tree[i].mn;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	ll ans=inf;
	if(l<=mid)ans=min(ans,Query(ls,l,r));
	if(r>mid)ans=min(ans,Query(rs,l,r));
	return ans;
}
void Del(int u){
	if(u<=1||u>=n)return;
	if(a[u]>=0&&a[u+1]<=0)up.erase(u);
	else if(a[u]<0&&a[u+1]>0)down.erase(u);
	else if(a[u]>=0){
		Change(1,u,inf);
	}
	else{
		Change(1,u,inf);
	}
}
void Insert(int u){
	if(u<=1||u>=n)return;
	if(a[u]>=0&&a[u+1]<=0)up.insert(u);
	else if(a[u]<0&&a[u+1]>0)down.insert(u);
	else if(a[u]>=0){
		Change(1,u,a[u+1]);
	}
	else{
		Change(1,u,-a[u]);
	}
}
ll Ask(int l,int r,int x){
	auto it=up.lower_bound(l);
	if(it!=up.end()&&(*it)<=r)return tot+2*x;
	ll mx=-inf;
	it=down.lower_bound(l);
	if(it!=down.end()&&(*it)<=r){
		int u=(*it);
		mx=max(mx,Abs(a[u]+x)+Abs(a[u+1]-x)-Abs(a[u])-Abs(a[u+1]));
	}
	ll qwq=Query(1,l,r);
	if(qwq^inf)mx=max(mx,max(0LL,2LL*(x-qwq)));
	return tot+mx;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=n;i>=2;--i){
		a[i]=a[i]-a[i-1];
		tot+=Abs(a[i]);
	}
	build(1,1,n);
	for(int i=2;i<n;++i){
		Insert(i);
	}
	Q=read();
	while(Q--){
		int opt=read(),l=read(),r=read(),x=read();
		if(opt==2){
			Del(l-1),Del(l);
			Del(r),Del(r+1);
			tot-=Abs(a[l])+Abs(a[r+1]);
			a[l]+=x;
			a[r+1]-=x;
			tot+=Abs(a[l])+Abs(a[r+1]);
			Insert(l-1),Insert(l);
			Insert(r),Insert(r+1);
		}
		else{
			printf("%lld\n",Ask(l,r,x));
		}
	}
	return 0;
}