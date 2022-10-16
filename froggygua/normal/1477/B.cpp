#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int T,n,m,l[N],r[N];
int a[N],b[N];
char s[N];
struct node{
	int cnt,cov,l,r;
	inline void Cov(int x){
		cov=x;
		cnt=(!x?r-l+1:0);
	}
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
inline void update(int i){
	tree[i].cnt=tree[ls].cnt+tree[rs].cnt;
}
inline void pushdown(int i){
	if(~tree[i].cov){
		tree[ls].Cov(tree[i].cov);
		tree[rs].Cov(tree[i].cov);
		tree[i].cov=-1;
	}
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	tree[i].cov=-1;
	if(l==r){
		tree[i].cnt=(b[l]==0);
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
}
void Change(int i,int l,int r,int d){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].Cov(d);
		return;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid)Change(ls,l,r,d);
	if(r>mid)Change(rs,l,r,d);
	update(i);
}
int Query(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return tree[i].cnt;
	}
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1,ans=0;
	if(l<=mid)ans+=Query(ls,l,r);
	if(r>mid)ans+=Query(rs,l,r);
	return ans;
}
void dfs(int i){
	if(tree[i].l==tree[i].r){
		b[tree[i].l]=!tree[i].cnt;
		return;
	}
	pushdown(i);
	dfs(ls),dfs(rs);
}
bool Solve(){
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)a[i]=s[i]-'0';
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)b[i]=s[i]-'0';
	for(int i=1;i<=m;++i){
		l[i]=read(),r[i]=read();
	}
	build(1,1,n);
	for(int i=m;i>=1;--i){
		int c0=Query(1,l[i],r[i]);
		int c1=r[i]-l[i]+1-c0;
		if(c0==c1)return false;
		if(c0<c1){
			Change(1,l[i],r[i],1);
		}
		else{
			Change(1,l[i],r[i],0);
		}
	}
	dfs(1);
	for(int i=1;i<=n;++i){
		if(a[i]^b[i])return false;
	}
	return true;
}
int main(){
	T=read();
	while(T--){
		printf(Solve()?"YES\n":"NO\n");
	}
	return 0;
}