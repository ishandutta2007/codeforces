#include <bits/stdc++.h>
#define MAXN 200010
#define LL long long
using namespace std;

namespace Seg{
	struct node{
		int lc,rc,s;
	}a[10000000];
	
	int size;

	int add(int x,int cl,int cr,int pos){
		int y=++size;
		a[y].s=a[x].s+1;
		if(cl==cr) return y;
		int mid=(cl+cr)>>1;
		if(pos<=mid){
			a[y].lc=add(a[x].lc,cl,mid,pos);
			a[y].rc=a[x].rc;
		}else{
			a[y].lc=a[x].lc;
			a[y].rc=add(a[x].rc,mid+1,cr,pos);
		}
		return y;
	}

	int sum(int x,int cl,int cr,int l,int r){
		if(l>r) return 0;
		if(l<=cl && cr<=r) return a[x].s;
		int mid=(cl+cr)>>1;
		if(r<=mid) return sum(a[x].lc,cl,mid,l,r);
		if(l>mid) return sum(a[x].rc,mid+1,cr,l,r);
		return sum(a[x].lc,cl,mid,l,r)+sum(a[x].rc,mid+1,cr,l,r);
	}
}

int n,m;
int p[MAXN];
int rt[MAXN];

LL query(){
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	LL s1=Seg::sum(rt[x1-1],1,n,1,y1-1),s2=Seg::sum(rt[x1-1],1,n,y1,y2),s3=Seg::sum(rt[x1-1],1,n,y2+1,n);
	LL s4=Seg::sum(rt[x2],1,n,1,y1-1),s5=Seg::sum(rt[x2],1,n,y1,y2),s6=Seg::sum(rt[x2],1,n,y2+1,n);
	LL s7=Seg::sum(rt[n],1,n,1,y1-1),s8=Seg::sum(rt[n],1,n,y1,y2),s9=Seg::sum(rt[n],1,n,y2+1,n);
	s7-=s4; s4-=s1;
	s8-=s5; s5-=s2;
	s9-=s6; s6-=s3;
	LL res=s5*(n-1);
	res+=s6*(n-s3-s6-s9);
	res+=s4*(n-s1-s4-s7);
	res+=s2*(n-s1-s2-s3);
	res+=s8*(n-s7-s8-s9);
	res+=s9*(s1+s2+s4+s5);
	res+=s7*(s2+s3+s5+s6);
	res+=s1*(s5+s6+s8+s9);
	res+=s3*(s4+s5+s7+s8);
	res/=2;
	return res;
}

int main(){
#ifdef DEBUG
	freopen("C.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",p+i);
	for(int i=1;i<=n;i++) rt[i]=Seg::add(rt[i-1],1,n,p[i]);
	while(m--) printf("%lld\n",query());
	return 0;
}