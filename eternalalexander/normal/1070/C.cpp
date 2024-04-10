#include <bits/stdc++.h>
#define ll long long
#define maxn 1000105
const int lim=1000002;
ll ans;
int n,m,k,l[maxn],r[maxn],p[maxn],c[maxn];
std::vector<int>in[maxn],out[maxn];
struct segmentTree {
	ll sum[maxn<<2];ll cnt[maxn<<2];
	void add(int l,int r,int p,int v,int rt){
		sum[rt]+=(ll)p*v;
		cnt[rt]+=v;
		if (l==r)return;
		int mid=(l+r)>>1;
		if (p<=mid)add(l,mid,p,v,rt<<1);
		else add(mid+1,r,p,v,rt<<1|1);
	}ll query(int l,int r,int k,int rt){
	//	if (k==0)return;
//	printf("query %d<->%d %d\n",l,r,k);
		if (l==r){
		//	printf("%d * %d\n",std::min(cnt[rt],k),l);
			return (ll)std::min(cnt[rt],(ll)k)*l;
		}if (cnt[rt<<1]>=k)return query(l,(l+r)>>1,k,rt<<1);
		else return sum[rt<<1]+query(((l+r)>>1)+1,r,k-cnt[rt<<1],rt<<1|1);
	}
}sgt;

int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d%d",&l[i],&r[i],&c[i],&p[i]);
		in[l[i]].push_back(i);
		out[r[i]].push_back(i);
	}for(int i=1;i<=n;++i){
		for(int j:in[i])sgt.add(1,lim,p[j],c[j],1);
		ans+=sgt.query(1,lim,k,1);
		//printf("%lld ",ans);
		for(int j:out[i])sgt.add(1,lim,p[j],-c[j],1);
	}std::cout<<ans;
}