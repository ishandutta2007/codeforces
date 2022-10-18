#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
int n,q,opt,l,r,a[maxn];
const int mod=95542721;
int pw(int x){return (ll)x*x%mod*x%mod;}
struct segmentTree {
	int sum[maxn<<2][48],det[maxn<<2];
	void update(int rt){
		for(int i=0;i<48;++i)sum[rt][i]=(sum[rt<<1][(i+det[rt<<1])%48]+sum[rt<<1|1][(i+det[rt<<1|1])%48])%mod;
	}void build(int l,int r,int rt){
		if (l==r){
			sum[rt][0]=a[l];
			for(int i=1;i<48;++i)sum[rt][i]=pw(sum[rt][i-1]);
			return;
		}build(l,(l+r)>>1,rt<<1);
		build(((l+r)>>1)+1,r,rt<<1|1);
		update(rt);
	}void pushdown(int rt){
		det[rt<<1]=(det[rt<<1]+det[rt])%48;
		det[rt<<1|1]=(det[rt<<1|1]+det[rt])%48;
		det[rt]=0;
		update(rt); 
	}void modify(int l,int r,int L,int R,int rt){
		if (l>R||r<L)return;
		if (l<=L&&R<=r){
			det[rt]=(det[rt]+1)%48;return;
		}pushdown(rt);
		modify(l,r,L,(L+R)>>1,rt<<1);
		modify(l,r,((L+R)>>1)+1,R,rt<<1|1);
		update(rt);
	}int query(int l,int r,int L,int R,int rt){
		if (l>R||r<L)return 0;
		if (l<=L&&R<=r)return sum[rt][det[rt]];
		pushdown(rt);
		return (query(l,r,L,(L+R)>>1,rt<<1)+query(l,r,((L+R)>>1)+1,R,rt<<1|1))%mod;
	}
}sgt;
		

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){scanf("%d",&a[i]);a[i]%=mod;}
	sgt.build(1,n,1);
	scanf("%d",&q);
	while (q--){
		scanf("%d%d%d",&opt,&l,&r);
		if (opt==1)printf("%d\n",sgt.query(l,r,1,n,1));
		else sgt.modify(l,r,1,n,1);
	}return 0;
}