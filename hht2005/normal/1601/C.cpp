#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],b[N],p[N],Min[4*N],tag[4*N];
void build(int p,int l,int r) {
	tag[p]=0;
	if(l==r) {
		Min[p]=l;
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	Min[p]=min(Min[p<<1],Min[p<<1|1]);
}
int cmp(int x,int y) {
	return a[x]<a[y];
}
void make_tag(int p,int v) {
	tag[p]+=v;
	Min[p]+=v;
}
void push_down(int p) {
	if(tag[p]) {
		make_tag(p<<1,tag[p]);
		make_tag(p<<1|1,tag[p]);
		tag[p]=0;
	}
}
void add(int p,int l,int r,int x,int y,int v) {
	if(x<=l&&r<=y)return make_tag(p,v);
	push_down(p);
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,v);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,v);
	Min[p]=min(Min[p<<1],Min[p<<1|1]);
}
int c[N],sum[N],n;
void add(int x,int v) {
	for(int i=x;i<=n;i+=i&-i)
		sum[i]+=v;
}
int qry(int x) {
	int ans=0;
	for(int i=x;i;i-=i&-i)
		ans+=sum[i];
	return ans;
}
int main() {
	int t,m;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) {
			scanf("%d",a+i);
			c[i]=a[i];
			p[i]=i;
		}
		sort(c+1,c+n+1);
		int cnt=unique(c+1,c+n+1)-c-1;
		long long ans=0;
		for(int i=1;i<=n;i++)sum[i]=0;
		for(int i=1;i<=n;i++) {
			int t=lower_bound(c+1,c+cnt+1,a[i])-c;
			ans+=i-1-qry(t);
			add(t,1);
		}
		for(int i=1;i<=m;i++)
			scanf("%d",b+i);
		sort(b+1,b+m+1);
		sort(p+1,p+n+1,cmp);
		build(1,0,n);
		for(int i=1,j=1,k=1;i<=m;i++) {
			while(j<=n&&a[p[j]]<=b[i])add(1,0,n,p[j++],n,-1);
			while(k<=n&&a[p[k]]<b[i])add(1,0,n,0,p[k++]-1,1);
			ans+=Min[1];
		}
		printf("%lld\n",ans);
	}
	return 0;
}