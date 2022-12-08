#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int Max[maxn<<2],Min[maxn<<2],tag[maxn<<2],a[maxn],p[maxn],ans[maxn],n;
void make_tag(int p,int v) {
	tag[p]+=v;
	Max[p]+=v;
	Min[p]+=v;
}
void pushdown(int p) {
	if(tag[p]) {
		make_tag(p<<1,tag[p]);
		make_tag(p<<1|1,tag[p]);
		tag[p]=0;
	}
}
void updata(int p) {
	Min[p]=min(Min[p<<1],Min[p<<1|1]);
	Max[p]=max(Max[p<<1],Max[p<<1|1]);
}
void add(int p,int l,int r,int x,int y,int v) {
	if(x<=l&&r<=y)return make_tag(p,v);
	pushdown(p);
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,v);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,v);
	updata(p);
}
int qryMin(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return Min[p];
	pushdown(p);
	int mid=(l+r)>>1,Min=1e9;
	if(x<=mid)Min=min(Min,qryMin(p<<1,l,mid,x,y));
	if(y>mid)Min=min(Min,qryMin(p<<1|1,mid+1,r,x,y));
	return Min;
}
int qryMax(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return Max[p];
	pushdown(p);
	int mid=(l+r)>>1,Max=-1e9;
	if(x<=mid)Max=max(Max,qryMax(p<<1,l,mid,x,y));
	if(y>mid)Max=max(Max,qryMax(p<<1|1,mid+1,r,x,y));
	return Max;
}
int cmp(int x,int y) {
	return a[x]<a[y];
}
void build(int p,int l,int r) {
	tag[p]=0;
	if(l==r) {
		Min[p]=Max[p]=l;
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	updata(p);
}
#define QMax(L,R) qryMax(1,1,n,L,R)
#define QMin(L,R) qryMin(1,1,n,L,R)
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	sort(a+1,a+n+1);
	build(1,1,n);
	for(int i=1;i<=n;i++) {
		int L=i,R=i;
		while(R<n&&a[R+1]==a[L])R++;
		for(int j=L;j<=R;j++)
			ans[p[j]]=max(ans[p[j]],(QMax(p[j],n)-min(QMin(1,p[j]),0))/2);
		for(int j=L;j<=R;j++)add(1,1,n,p[j],n,-2);
		i=R;
	}
	build(1,1,n);
	for(int i=1;i<=n;i++) {
		int L=i,R=i;
		while(R<n&&a[R+1]==a[L])R++;
		for(int j=L;j<=R;j++)add(1,1,n,p[j],n,-2);
		for(int j=L;j<=R;j++) {
			int t=(max(0,QMax(1,p[j]))-QMin(p[j],n));
			if(t%2==0)t=t/2-1;
			else t=t/2;
			ans[p[j]]=max(ans[p[j]],t);
		}
		i=R;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}