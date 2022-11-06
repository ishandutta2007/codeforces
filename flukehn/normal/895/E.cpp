#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
typedef double ld;
int n;
double a[N];
namespace segtree{
	const int M=N<<2;
	ld b[M],c[M];
	ld d[M];
	int s[M];
	#define m (l+r>>1)
	#define ls x<<1,l,m
	#define rs x<<1|1,m+1,r
	void pu(int x){
		b[x]=b[x*2]+b[x*2+1];
	}
	//void pd(int);
	//void pt(int,int,ld);
	void pt(int x,int y,ld z){
		/*pd(x);
		if(~d[x])d[x]=y;
		c[x]=z;
		if(y==1)b[x]*=z;
		else b[x]+=z*s[x];*/
		if(y==1)c[x]*=z,b[x]*=z,d[x]*=z;
		else b[x]+=z*s[x],d[x]+=z;
	}
	void pd(int x){
		/*if(d[x]<=0)return;
		pt(x*2,d[x],c[x]);
		pt(x*2+1,d[x],c[x]);
		d[x]=c[x]=0;*/
		pt(x*2,1,c[x]),pt(x*2+1,1,c[x]),c[x]=1;
		pt(x*2,2,d[x]),pt(x*2+1,2,d[x]),d[x]=0;
	}
	
	void B(int x,int l,int r){
		s[x]=r-l+1;
		c[x]=1,d[x]=0;
		if(l==r){
			b[x]=a[l];
		//	d[x]=-1;
			return;
		}
		B(ls),B(rs);
		pu(x);
	}
	int ql,qr;
	ld qy,qz,an;
	void ask(int x,int l,int r){
		if(ql<=l&&r<=qr){
			an+=b[x];
			return;
		}
		pd(x);
		if(ql<=m)ask(ls);
		if(qr>m)ask(rs);
	}
	
	void upd(int x,int l,int r){
		
		if(ql<=l&&r<=qr){
			pt(x,qy,qz);
			return;
		}
		pd(x);
		if(ql<=m)upd(ls);
		if(qr>m)upd(rs);
		pu(x);
	}
	
	ld ask(int l,int r){
		ql=l,qr=r;
		an=0;
		ask(1,1,n);
		return an;
	}
	void mul(int l,int r,ld z){
		ql=l,qr=r;
		qy=1,qz=z;
		upd(1,1,n);
	}
	void add(int l,int r,ld z){
		ql=l,qr=r;
		qy=2,qz=z;
		upd(1,1,n);
	}
	#undef m
}
using namespace segtree;
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	int i,x,y,l,r,o,q;
	cin>>n>>q;
	for(i=1;i<=n;++i)
		scanf("%lf",a+i);
	B(1,1,n);
	ld s1,s2;
	while(q--){
		scanf("%d%d%d",&o,&l,&r);
		s1=ask(l,r);
		if(o==2){
			printf("%.6lf\n",s1);
		}else{
			scanf("%d%d",&x,&y);
			s2=ask(x,y);
			mul(l,r,(ld)(r-l)/(r-l+1));
			mul(x,y,(ld)(y-x)/(y-x+1));
			add(l,r,s2/(r-l+1)/(y-x+1));
			add(x,y,s1/(r-l+1)/(y-x+1));
		}
	}
}