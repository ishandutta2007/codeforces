#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int Min[N<<2],cnt[N<<2],tag[N<<2],a[N],sk1[N],sk2[N],top1,top2;
void make_tag(int p,int v) {
	Min[p]+=v;
	tag[p]+=v;
}
void push_down(int p) {
	if(tag[p]) {
		make_tag(p<<1,tag[p]);
		make_tag(p<<1|1,tag[p]);
		tag[p]=0;
	}
}
void push_up(int p) {
	if(Min[p<<1]<Min[p<<1|1]) {
		Min[p]=Min[p<<1];
		cnt[p]=cnt[p<<1];
	} else if(Min[p<<1|1]<Min[p<<1]) {
		Min[p]=Min[p<<1|1];
		cnt[p]=cnt[p<<1|1];
	} else {
		Min[p]=Min[p<<1];
		cnt[p]=cnt[p<<1]+cnt[p<<1|1];
	}
}
void build(int p,int l,int r) {
	tag[p]=Min[p]=0;
	cnt[p]=r-l+1;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}
void add(int p,int l,int r,int x,int y,int v) {
	if(x<=l&&r<=y)return make_tag(p,v);
	push_down(p);
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,v);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,v);
	push_up(p);
}
int main() {
	int n,x,y;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&x,&y);
		a[x]=y;
	}
	build(1,1,n);
	for(int i=1;i<=n;i++) {
		add(1,1,n,1,i,-1);
		while(top1&&a[sk1[top1]]>a[i]) {
			add(1,1,n,sk1[top1-1]+1,sk1[top1],a[sk1[top1]]-a[i]);
			top1--;
		}
		sk1[++top1]=i;
		while(top2&&a[sk2[top2]]<a[i]) {
			add(1,1,n,sk2[top2-1]+1,sk2[top2],a[i]-a[sk2[top2]]);
			top2--;
		}
		sk2[++top2]=i;
		ans+=cnt[1];
	}
	printf("%lld\n",ans);
	return 0;
}