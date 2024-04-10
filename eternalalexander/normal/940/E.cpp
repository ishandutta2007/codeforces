#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
int n,c,a[maxn];
ll f[maxn],sum[maxn]={0};
struct segmentTree {
	int max[maxn<<2];
	void build(int l,int r,int rt){
		if (l==r){max[rt]=a[l];return;}
		build(l,(l+r)>>1,rt<<1);
		build(((l+r)>>1)+1,r,rt<<1|1);
		max[rt]=std::min(max[rt<<1],max[rt<<1|1]);
	}int query(int l,int r,int L,int R,int rt){
		if (l>R||r<L)return 1e9+5;
		if (l<=L&&R<=r)return max[rt];
		return std::min(query(l,r,L,(L+R)>>1,rt<<1),query(l,r,((L+R)>>1)+1,R,rt<<1|1));
	}
}sgt;

int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;++i){scanf("%d",&a[i]);sum[i]=sum[i-1]+a[i];}
	sgt.build(1,n,1);
	f[0]=0;
	for(int i=1;i<=n;++i){
		f[i]=f[i-1]+a[i];
		if (i-c>=0)f[i]=std::min(f[i],f[i-c]+sum[i]-sum[i-c]-sgt.query(i-c+1,i,1,n,1));
	}std::cout<<f[n];
	return 0;
}