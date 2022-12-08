#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
vector<int>S[N<<2];
bitset<N>f[30],ans;
void add(int p,int l,int r,int x,int y,int k) {
	if(x<=l&&r<=y) {
		S[p].push_back(k);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,k);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,k);
}
void build(int p,int l,int r,int dep) {
	f[dep]=f[dep-1];
	for(int i:S[p])
		f[dep]|=f[dep]<<i;
	if(l==r) {
		ans|=f[dep];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid,dep+1);
	build(p<<1|1,mid+1,r,dep+1);
}
signed main() {
	f[0][0]=1;
	int n,q,l,r,k;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++) {
		scanf("%d%d%d",&l,&r,&k);
		add(1,1,n,l,r,k);
	}
	build(1,1,n,1);
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(ans[i])cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)
		if(ans[i])printf("%d ",i);
	puts("");
	return 0;
}