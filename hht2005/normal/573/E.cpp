#include<bits/stdc++.h>
using namespace std;
const int N=100010;
using ll=long long;
using pii=pair<int,int>;
int ls[N],rs[N],siz[N],rk[N],a[N],rt,tot;
ll val[N],A[N],D[N];
void make_tag(int p,ll a,ll d) {
	A[p]+=a;
	D[p]+=d;
	val[p]=val[p]+siz[ls[p]]*d+a;
}
void push_down(int p) {
	if(D[p]||A[p]) {
		make_tag(ls[p],A[p],D[p]);
		make_tag(rs[p],A[p]+(siz[ls[p]]+1)*D[p],D[p]);
		D[p]=A[p]=0;
	}
}
void updata(int p) {
	siz[p]=siz[ls[p]]+siz[rs[p]]+1;
	// cerr<<ls[p]<<':'<<rs[p]<<' '<<siz[p]<<' '<<p<<endl;
}
int merge(int x,int y) {
	if(!x||!y)return x+y;
	push_down(x);
	push_down(y);
	if(rk[x]<rk[y]) {
		ls[y]=merge(x,ls[y]);
		updata(y);
		return y;
	} else {
		rs[x]=merge(rs[x],y);
		updata(x);
		return x;
	}
}
pii split(int p,int k) {
	// cerr<<p<<'S'<<k<<endl;
	if(k==0)return make_pair(0,p);
	if(k==siz[p])return make_pair(p,0);
	push_down(p);
	pii t;
	if(k<=siz[ls[p]]) {
		t=split(ls[p],k);
		ls[p]=t.second;
		t.second=p;
	} else {
		t=split(rs[p],k-siz[ls[p]]-1);
		rs[p]=t.first;
		t.first=p;
	}
	// if(p==0)cerr<<"!!!"<<endl;
	updata(p);
	return t;
}
int New(ll x) {
	val[++tot]=x;
	siz[tot]=1;
	rk[tot]=rand();
	return tot;
}
ll qry(int p,int k) {
	// cerr<<p<<' '<<k<<endl;
	if(siz[p]<k)return -1e18;
	push_down(p);
	if(k<=siz[ls[p]])return qry(ls[p],k);
	if(k==siz[ls[p]]+1)return val[p];
	return qry(rs[p],k-siz[ls[p]]-1);
}
void add(int x,ll val) {
	ll fij=qry(rt,x);
	pii t=split(rt,x);
	// cerr<<siz[rt]<<'-'<<x<<' '<<tot<<endl;
	t.second=merge(New(fij),t.second);
	make_tag(t.second,1ll*val*x,val);
	rt=merge(t.first,t.second);
	// for(int i=1;i<=tot;i++)
	// 	cerr<<":"<<siz[i]<<endl;
}
ll get(int p) {
	if(!p)return 0;
	push_down(p);
	ll ans=val[p];
	ans=max(ans,get(ls[p]));
	// printf("%lld %d %d\n",val[p],ls[p],rs[p]);
	ans=max(ans,get(rs[p]));
	return ans;
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	rt=New(0);
	for(int i=1;i<=n;i++) {
		int l=1,r=i-1;
		while(l<=r) {
			int mid=(l+r)>>1;
			ll v1=qry(rt,mid+1);//cerr<<endl;
			ll v2=qry(rt,mid)+1ll*a[i]*mid;//cerr<<endl;
			// cerr<<v1<<' '<<v2<<endl;
			if(v1>v2)l=mid+1;
			else r=mid-1;
		}
		// cerr<<l<<endl;
		add(l,a[i]);
		// cerr<<endl;
	}
	printf("%lld\n",get(rt));
	return 0;
}