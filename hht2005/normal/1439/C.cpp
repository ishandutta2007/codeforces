#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int MAXL=1<<22;
char i_str[MAXL],*i_s,*i_t;
char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
int read() {
	int x=0,f=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc())
		if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=gc())
		x=x*10+(ch^48);
	return f?-x:x;
}
const int maxn=2e5+10;
int Max[maxn<<2],Min[maxn<<2],f[maxn<<2],a[maxn];
ll sum[maxn<<2];
void tag(int p,int v,int l) {
	f[p]=Min[p]=Max[p]=v;
	sum[p]=1ll*l*v;
}
void pushdown(int p,int l) {
	if(f[p]) {
		tag(p<<1,f[p],l-l/2);
		tag(p<<1|1,f[p],l/2);
		f[p]=0;
	}
}
void pushup(int p) {
	Max[p]=max(Max[p<<1],Max[p<<1|1]);
	Min[p]=min(Min[p<<1],Min[p<<1|1]);
	sum[p]=sum[p<<1]+sum[p<<1|1];
}
void cover(int p,int l,int r,int x,int v) {
	if(Min[p]>=v)return;
	if(r<=x&&Max[p]<=v)return tag(p,v,r-l+1);
	pushdown(p,r-l+1);
	int mid=(l+r)>>1;
	cover(p<<1,l,mid,x,v);
	if(x>mid)cover(p<<1|1,mid+1,r,x,v);
	pushup(p);
}
int qry1(int p,int l,int r,int v) {
	if(l==r)return l;
	pushdown(p,r-l+1);
	int mid=(l+r)>>1;
	if(Min[p<<1]<=v)return qry1(p<<1,l,mid,v);
	else return qry1(p<<1|1,mid+1,r,v);
}
int qry2(int p,int l,int r,ll v) {
	if(l==r)return l-(sum[p]>v);
	pushdown(p,r-l+1);
	int mid=(l+r)>>1;
	if(v<=sum[p<<1])return qry2(p<<1,l,mid,v);
	else return qry2(p<<1|1,mid+1,r,v-sum[p<<1]);
}
ll qry3(int p,int l,int r,int x,int y) {
	if(x>y)return 0;
	if(x<=l&&r<=y)return sum[p];
	pushdown(p,r-l+1);
	int mid=(l+r)>>1;
	ll Sum=0;
	if(x<=mid)Sum+=qry3(p<<1,l,mid,x,y);
	if(y>mid)Sum+=qry3(p<<1|1,mid+1,r,x,y);
	return Sum;
}
void build(int p,int l,int r) {
	if(l==r) {
		Min[p]=Max[p]=sum[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
signed main() {
	int n,q,opt,x,y;
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	build(1,1,n);
	for(int i=1;i<=q;i++) {
		scanf("%lld%lld%lld",&opt,&x,&y);
		if(opt==1)cover(1,1,n,x,y);
		else {
			int cnt=0;
			while(y>=Min[1]) {
				int L=max(qry1(1,1,n,y),x),R=qry2(1,1,n,y+qry3(1,1,n,1,L-1));
				y-=qry3(1,1,n,L,R);
				cnt+=R-L+1;
				if(R==n)break;
			}
			printf("%lld\n",cnt);
		}
	}
	return 0;
}