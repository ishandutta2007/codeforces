#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N];
struct node {
	int cnt[N<<2];
	long long Min[N<<2],tag[N<<2];
	void updata(int p) {
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
	void add(int p,int l,int r,int x,int y,int v) {
		if(x>y)return;
		if(x<=l&&r<=y)return make_tag(p,v);
		push_down(p);
		int mid=(l+r)>>1;
		if(x<=mid)add(p<<1,l,mid,x,y,v);
		if(y>mid)add(p<<1|1,mid+1,r,x,y,v);
		updata(p);
	}
	int qryz(int p,int l,int r,int x,int y) {
		if(x>y)return 0;
		if(x<=l&&r<=y)return Min[p]==0?cnt[p]:0;
		push_down(p);
		int mid=(l+r)>>1,sum=0;
		if(x<=mid)sum+=qryz(p<<1,l,mid,x,y);
		if(y>mid)sum+=qryz(p<<1|1,mid+1,r,x,y);
		return sum;
	}
	int qryf(int p,int l,int r) {
		if(l==r)return l;
		push_down(p);
		int mid=(l+r)>>1;
		if(Min[p<<1]<0)return qryf(p<<1,l,mid);
		else return qryf(p<<1|1,mid+1,r);
	}
	void build(int p,int l,int r) {
		tag[p]=Min[p]=0;
		cnt[p]=r-l+1;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
	}
}oz,ez;
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		int O=n,E=n;
		if(n&1)E--;
		else O--;
		O=(O-1)/2+1;
		E/=2;
		ez.build(1,1,E+1);
		oz.build(1,1,O+1);
		long long ans=0;
		for(int i=n;i>=1;i--) {
			int f=i&1?1:-1,oL,eL;
			if(i&1)oL=i/2+1,eL=(i+1)/2;
			else oL=(i+1)/2+1,eL=i/2;
			oz.add(1,1,O+1,oL,O,a[i]*f);
			ez.add(1,1,E+1,eL,E,-a[i]*f);
			int Min=min(2*oz.qryf(1,1,O+1)-1,2*ez.qryf(1,1,E+1));
			int oR,eR;
			if(Min%2==0)eR=Min/2-1,oR=(Min-1)/2+1;
			else eR=(Min-1)/2,oR=Min/2;
			ans+=oz.qryz(1,1,O+1,oL,oR);
			ans+=ez.qryz(1,1,E+1,eL,eR);
		}
		printf("%lld\n",ans);
	}
	return 0;
}