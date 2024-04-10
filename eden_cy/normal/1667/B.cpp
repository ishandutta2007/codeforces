#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)

typedef long long ll;

const int N=5e5+50;

ll a[N],b[N];
struct segment {
	int mx[N<<2];
	#define ls p<<1
	#define rs p<<1|1
	#define lson L,mid,ls
	#define rson mid+1,R,rs
	void build(int L,int R,int p) {
		mx[p]=-1e9;
		if(L==R) return ;
		int mid=L+R>>1;
		build(lson);
		build(rson);
	}
	void upd(int L,int R,int p,int x,int v) {
		mx[p]=max(mx[p],v);
		if(L==R) return ;
		int mid=L+R>>1;
		if(x<=mid) upd(lson,x,v);
		else upd(rson,x,v);
	}
	int qry(int L,int R,int p,int l,int r) {
		if(L==l && R==r) return mx[p];
		int mid=L+R>>1;
		if(r<=mid) return qry(lson,l,r);
		else if(l>mid) return qry(rson,l,r);
		else return max(qry(lson,l,mid),qry(rson,mid+1,r));
	}
} T[2];
int f[N],g[N];
void solve() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%lld",&a[i]);
	FOR(i,1,n) a[i]+=a[i-1];
	FOR(i,0,n) b[i]=a[i];
	sort(b,b+n+1);
	int m=unique(b,b+n+1)-b;
	FOR(i,0,n) a[i]=lower_bound(b,b+m,a[i])-b+1;
	
	T[0].build(1,m,1);
	T[1].build(1,m,1);
	
	f[0]=0;
	FOR(i,1,n) f[i]=-1e9;
	FOR(i,1,m) g[i]=-1e9;
	g[a[0]]=0;
	
	T[0].upd(1,m,1,a[0],f[0]-0);
	T[1].upd(1,m,1,a[0],f[0]+0);
	
	FOR(i,1,n) {
		if(a[i]>1) f[i]=max(f[i],T[0].qry(1,m,1,1,a[i]-1)+i);
		if(a[i]<m) f[i]=max(f[i],T[1].qry(1,m,1,a[i]+1,m)-i);
		f[i]=g[a[i]]=max(f[i],g[a[i]]);
		T[0].upd(1,m,1,a[i],f[i]-i);
		T[1].upd(1,m,1,a[i],f[i]+i);
	}
	printf("%d\n",f[n]);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}