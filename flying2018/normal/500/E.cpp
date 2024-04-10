#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
#define ll long long
using namespace std;
ll val[N*40];
int ls[N*40],rs[N*40],cnt;
void insert(int &u,ll l,ll r,ll L,ll R)
{
	if(!u) u=++cnt;
	if(val[u]==r-l+1) return;
	if(L<=l && r<=R){val[u]=r-l+1;return;}
	ll mid=(l+r)>>1;
	if(L<=mid) insert(ls[u],l,mid,L,R);
	if(R>mid) insert(rs[u],mid+1,r,L,R);
	val[u]=val[ls[u]]+val[rs[u]];
}
ll answer(int u,ll l,ll r,ll L,ll R)
{
	if(R<L) return 0;
	if(val[u]==r-l+1) return R-L+1;
	if(!val[u] || (L<=l && r<=R)) return val[u];
	int mid=(l+r)>>1;
	if(L>mid) return answer(rs[u],mid+1,r,L,R);
	if(R<=mid) return answer(ls[u],l,mid,L,R);
	return answer(ls[u],l,mid,L,mid)+answer(rs[u],mid+1,r,mid+1,R);
}
ll l[N],r[N];
struct ques{
	ll l,r,id;
	bool operator <(const ques a)const{return l>a.l;}
}q[N];
ll ans[N];
int main()
{
	int n,m;
	scanf("%d",&n);
	ll maxn=0;
	for(int i=1;i<=n;i++) scanf("%lld%lld",&l[i],&r[i]),r[i]+=l[i]-1,maxn=max(maxn,r[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%lld%lld",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1);
	int u=1,root=0;
	for(int i=n;i>=1;i--)
	{
		insert(root,1,maxn,l[i],r[i]);
		for(;q[u].l==i;u++)
		{
			ll d=l[q[u].r]-r[q[u].l];
			if(d<0) ans[q[u].id]=0;
			else ans[q[u].id]=d-answer(root,1,maxn,r[q[u].l],l[q[u].r])+1;
		}
	}
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}