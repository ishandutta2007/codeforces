#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+100;
int a[N];

struct tree{
	int l,r,lc,rc;ll c1,c2,c3;
}tr[2*N];int len;

ll mymax(ll x,ll y) {return (x>y?x:y);}

void build(int l,int r){
	int now=++len;
	tr[now].l=l;tr[now].r=r;
	tr[now].lc=tr[now].rc=-1;
	tr[now].c1=tr[now].c2=tr[now].c3=-1e18;
	if(l<r){
		int mid=(l+r)>>1;
		tr[now].lc=len+1;build(l,mid);
		tr[now].rc=len+1;build(mid+1,r);
	}
}
void Change(int now,int k,ll c1,ll c2,ll c3){
	if(tr[now].l==tr[now].r){
		tr[now].c1=mymax(tr[now].c1,c1);
		tr[now].c2=mymax(tr[now].c2,c2);
		tr[now].c3=mymax(tr[now].c3,c3);
		return ;
	}
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(k<=mid) Change(lc,k,c1,c2,c3);
	else Change(rc,k,c1,c2,c3);
	tr[now].c1=mymax(tr[lc].c1,tr[rc].c1);
	tr[now].c2=mymax(tr[lc].c2,tr[rc].c2);
	tr[now].c3=mymax(tr[lc].c3,tr[rc].c3);
}
ll findans(int now,int l,int r,int ty){
	if(l>r) return -1e18;
	if(l==tr[now].l&&r==tr[now].r){
		if(ty==1) return tr[now].c1;
		if(ty==2) return tr[now].c2;
		if(ty==3) return tr[now].c3;
	}
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(r<=mid) return findans(lc,l,r,ty);
	else if(mid<l) return findans(rc,l,r,ty);
	else return mymax(findans(lc,l,mid,ty),findans(rc,mid+1,r,ty));
}

ll qz[N];int h[N];
map<ll,int> B;
bool cmp(int n1,int n2) {return (qz[n1]<qz[n2]);}

int main()
{
	
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		qz[0]=0;for(int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
		for(int i=0;i<=n;i++) h[i]=i;	
		sort(h,h+n+1,cmp);
		int Sum=0;
		for(int i=0;i<=n;i++){
			if(i==0||qz[h[i]]!=qz[h[i-1]]) Sum++;
			B[qz[h[i]]]=Sum;
		}
		for(int i=0;i<=n;i++) qz[i]=B[qz[i]];
		
		len=0;build(1,Sum);
		
		Change(1,qz[0],0,0,0);
		for(int i=1;i<=n;i++){
			ll t1=findans(1,1,qz[i]-1,1);
			ll t2=findans(1,qz[i]+1,Sum,3);
			ll t3=findans(1,qz[i],qz[i],2);
			ll t=mymax(mymax(t3,t1+i),t2-i);
			if(i==n) printf("%lld\n",t);
			Change(1,qz[i],t-i,t,t+i);
		}
	}
	
	return 0;
}