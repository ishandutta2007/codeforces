#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10,M=1e5;
using ll=long long;
struct line {
	ll k,b;
	line() {
		k=0;
		b=1e18;
	}
	line(int K,int B) {
		k=K,b=B;
	}
}L[N*20];
vector<int>S[N];
int rt[N],a[N],b[N],ls[N*20],rs[N*20],tot;
ll f[N];
#define calc(L,x) L.k*x+L.b
void add(int &p,int l,int r,line x) {
	if(!p) {
		L[p=++tot]=x;
		return;
	}
	if(l==r) {
		if(calc(L[p],l)>calc(x,l))
			L[p]=x;
		return;
	}
	int mid=(l+r)>>1;
	if(calc(x,mid)<calc(L[p],mid))
		swap(x,L[p]);
	if(l==r||x.b>1e17)return;
	if(x.k>L[p].k)add(ls[p],l,mid,x);
	if(x.k<L[p].k)add(rs[p],mid+1,r,x);
}
ll qry(int p,int l,int r,int x) {
	if(!p)return 1e17;
	ll v=calc(L[p],x);
	if(l==r)return v;
	int mid=(l+r)>>1;
	if(x<=mid)v=min(v,qry(ls[p],l,mid,x));
	else v=min(v,qry(rs[p],mid+1,r,x));
	return v;
}
int merge(int x,int y,int l,int r) {
	if(!x||!y)return x|y;
	if(l==r)return calc(L[x],l)<calc(L[y],l)?x:y;
	int mid=(l+r)>>1;
	ls[x]=merge(ls[x],ls[y],l,mid);
	rs[x]=merge(rs[x],rs[y],mid+1,r);
	add(x,l,r,L[y]);
	return x;
}
void dfs(int x,int fa) {
	for(int y:S[x])
		if(y!=fa) {
			dfs(y,x);
			rt[x]=merge(rt[x],rt[y],-M,M);
		}
	if(rt[x])f[x]=qry(rt[x],-M,M,a[x]);
	add(rt[x],-M,M,line(b[x],f[x]));
}
signed main() {
	int n,x,y;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(int i=1;i<=n;i++)
		scanf("%lld",b+i);
	for(int i=1;i<n;i++) {
		scanf("%lld%lld",&x,&y);
		S[x].push_back(y);
		S[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		printf("%lld ",f[i]);
	puts("");
	return 0;
}