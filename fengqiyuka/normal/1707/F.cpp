#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
typedef long long ll;
const int N=1e7+100;
int n,m,ti,w,o,mod;
struct tree{
	int l,r,lc,rc,ty,c,id;
}tr[2*N];int len=0,g[N];

int p1[N],p2[N],a[N];

int mi(int x,int t){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}

void merge(int now,int ty){
	int lc=tr[now].lc,rc=tr[now].rc;
	if(ty){
		if(tr[lc].ty==3||tr[rc].ty==3) tr[now].ty=3;
		else{
			if(tr[lc].ty==1&&tr[rc].ty==1) tr[now].ty=1,tr[now].c=tr[lc].c+tr[rc].c;
			else if(tr[lc].ty==1) tr[now].ty=2,tr[now].id=tr[rc].id,tr[now].c=tr[lc].c+tr[rc].c;
			else if(tr[rc].ty==1) tr[now].ty=2,tr[now].id=tr[lc].id,tr[now].c=tr[lc].c+tr[rc].c;
			else if(tr[lc].id==tr[rc].id) tr[now].ty=2,tr[now].id=tr[lc].id,tr[now].c=tr[lc].c+tr[rc].c;
			else tr[now].ty=3;
		}
	}
	else{
		if(tr[lc].ty==3||tr[rc].ty==3) tr[now].ty=3;
		else{
			if(tr[lc].ty==1&&tr[rc].ty==1) tr[now].ty=1,tr[now].c=tr[lc].c+tr[rc].c+1;
			else if(tr[lc].ty==1) tr[now].ty=1,tr[now].c=tr[lc].c+tr[rc].c;
			else if(tr[rc].ty==1) tr[now].ty=1,tr[now].c=tr[lc].c+tr[rc].c;
			else tr[now].ty=2,tr[now].id=(tr[lc].id^tr[rc].id),tr[now].c=tr[lc].c+tr[rc].c;
		}
	}
}

void build(int l,int r,int ti){
	int now=++len;
	tr[now].l=l;tr[now].r=r;
	tr[now].lc=tr[now].rc=-1;
	if(l<r){
		int mid=(l+r)>>1;
		tr[now].lc=len+1;build(l,mid,ti/2);
		tr[now].rc=len+1;build(mid+1,r,ti/2);
		merge(now,ti&1);
	}
	else{
		if(ti) tr[now].ty=2,tr[now].c=n/o-1,tr[now].id=0;
		else tr[now].ty=1,tr[now].c=n/o-1;//care
	}
}
void Change(int now,int k,int ti){
	if(tr[now].l==tr[now].r){
		int x=g[k];
		if(ti){
			if(p1[x]==n/o){
				if(p2[x]==0) tr[now].ty=2,tr[now].id=p2[x],tr[now].c=0;
				else tr[now].ty=3;
			}
			else{
				tr[now].ty=2;tr[now].id=0;tr[now].c=n/o-p1[x]-1;
			}
		}
		else{
			if(p1[x]==n/o) tr[now].ty=2,tr[now].id=p2[x],tr[now].c=0;
			else tr[now].ty=1,tr[now].c=n/o-p1[x]-1;
		}
		return ;
	}
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(k<=mid) Change(lc,k,ti/2);
	else Change(rc,k,ti/2);
	merge(now,ti&1);
}

int main()
{
	
	scanf("%d%d%d%d",&n,&m,&ti,&w);
	
	o=lowbit(n);ti=std::min(ti,o);
	build(0,o-1,ti);
	
	for(int i=1;i<o;i++) g[i]=g[i/2]/2+(o>>1)*(i&1);
	
	for(int i=1;i<=n;i++) a[i]=-1;
	for(int i=1;i<=m;i++){
		int x,c;
		scanf("%d%d",&x,&c);
		p1[x%o]++;p2[x%o]^=c;
		Change(1,g[x%o],ti);
		a[x]=c;
	}
	
	int q;scanf("%d",&q);
	for(int i=1;i<=q;i++){
		if(i==13){
			i++;i--;
		}
		int x,c;
		scanf("%d%d%d",&x,&c,&mod);
		if(a[x]!=-1) p1[x%o]--,p2[x%o]^=a[x];
		if(c!=-1) p1[x%o]++,p2[x%o]^=c;
		a[x]=c;
		Change(1,g[x%o],ti);
		if(tr[1].ty==3) printf("0\n");
		else if(tr[1].ty==2) printf("%d\n",mi(2,w*tr[1].c));
		else printf("%d\n",(ll)(1<<w)*mi(2,w*tr[1].c)%mod);
	}
	
	return 0;
}