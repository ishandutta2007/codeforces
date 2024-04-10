#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int a[maxn],p[maxn],tag[maxn<<2],Min[maxn<<2];
int cmp(int x,int y) {
	return a[x]>a[y];
}
void make_tag(int p,int v) {
	tag[p]+=v;
	Min[p]+=v;
}
void pushdown(int p) {
	if(tag[p]) {
		make_tag(p<<1,tag[p]);
		make_tag(p<<1|1,tag[p]);
		tag[p]=0;
	}
}
void add(int p,int l,int r,int x,int y,int v) {
	if(x<=l&&r<=y)return make_tag(p,v);
	pushdown(p);
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,v);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,v);
	Min[p]=min(Min[p<<1],Min[p<<1|1]);
}
signed main() {
	int n,cnt=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",a+i);
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++) {
		add(1,1,n,p[i],n,a[p[i]]);
		cnt++;
		if(Min[1]<0)add(1,1,n,p[i],n,-a[p[i]]),cnt--;
	}
	printf("%lld\n",cnt);
	return 0;
}