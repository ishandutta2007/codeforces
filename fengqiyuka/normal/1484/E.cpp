#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=5e5+100;
struct tree{
	int lc,rc,l,r,c1;ll c2;
}tr[2*N];int len=0,b[N],Sum,h[N];
ll mymax(ll x,ll y) {return (x>y?x:y);}
void build(int l,int r){
	int now=++len;
	tr[now].l=l;tr[now].r=r;
	tr[now].lc=tr[now].rc=-1;
	tr[now].c2=-1e18;tr[now].c1=0;
	if(l<r){
		int mid=(l+r)>>1;
		tr[now].lc=len+1;build(l,mid);
		tr[now].rc=len+1;build(mid+1,r);
		int lc=tr[now].lc,rc=tr[now].rc;
		if(b[tr[lc].c1]<b[tr[rc].c1]) tr[now].c1=tr[lc].c1;
		else tr[now].c1=tr[rc].c1;
	}
	else tr[now].c1=l;
}
int findans(int now,int l,int r){
	if(l==tr[now].l&&r==tr[now].r) return tr[now].c1;
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(r<=mid) return findans(lc,l,r);
	else if(mid<l) return findans(rc,l,r);
	else{
		int t1=findans(lc,l,mid),t2=findans(rc,mid+1,r);
		if(b[t1]<b[t2]) return t1;
		return t2;
	}
}
ll bz[2*N];
void update(int now){
	if(bz[now]!=-1e18){
		int lc=tr[now].lc,rc=tr[now].rc;
		tr[lc].c2=mymax(tr[lc].c2,bz[now]);
		tr[rc].c2=mymax(tr[rc].c2,bz[now]);
		bz[lc]=mymax(bz[lc],bz[now]);
		bz[rc]=mymax(bz[rc],bz[now]);
		bz[now]=-1e18;
	}
}
ll findmax(int now,int l,int r){
	if(l==tr[now].l&&r==tr[now].r) return tr[now].c2;
	update(now);
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(r<=mid) return findmax(lc,l,r);
	else if(mid<l) return findmax(rc,l,r);
	else return mymax(findmax(lc,l,mid),findmax(rc,mid+1,r));
}
void add(int now,int l,int r,ll c){
	if(l==tr[now].l&&r==tr[now].r){
		tr[now].c2=mymax(tr[now].c2,c);
		bz[now]=mymax(bz[now],c);
		return ;
	}
	update(now);
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(r<=mid) add(lc,l,r,c);
	else if(mid<l) add(rc,l,r,c);
	else add(lc,l,mid,c),add(rc,mid+1,r,c);
	tr[now].c2=mymax(tr[lc].c2,tr[rc].c2);
}
void solve(int l,int r){
	if(l==r) return ;
	int t=findans(1,l+1,r);
	solve(l,t-1);
	ll t2=findmax(1,l,t-1)+h[t];
	add(1,t,r,t2);
	solve(t,r);
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	b[0]=2e9;
	build(0,n);
	for(int i=1;i<=len;i++) bz[i]=-1e18;
	add(1,0,0,0);
	solve(0,n);
	ll t=findmax(1,n,n);
	printf("%lld\n",t);
	return 0;
}