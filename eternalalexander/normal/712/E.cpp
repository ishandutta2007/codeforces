#include <bits/stdc++.h>
#define maxn 100005
const double eps=1e-8;
int n,q,opt,x,l,r;
double a[maxn];
double read(){
	double x,y;
	scanf("%lf%lf",&x,&y);
	return x/y;
}

struct data {
	double L,R;
	data (double l=-1,double r=-1) {L=l;R=r;}
}sum[maxn<<2];

data merge(data a,data b){
	if(a.L<0)return b;
	if(b.L<0)return a;
	data c;
	double T=1-(1-b.L)*a.R;
	if(T<eps){
		c.L=0;c.R=b.R;
		return c;
	}c.L=a.L*b.L/T;
	c.R=b.R+(1-b.R)*a.R*b.L/T;
	return c;
}

void build(int l,int r,int rt){
	if(l==r){
		sum[rt].L=sum[rt].R=a[l];
		return;
	}build(l,(l+r)>>1,rt<<1);
	build(((l+r)>>1)+1,r,rt<<1|1);
	sum[rt]=merge(sum[rt<<1],sum[rt<<1|1]);
}

void modify(int l,int r,int p,double v,int rt){
	if(l==r){
		a[p]=sum[rt].L=sum[rt].R=v;
		return;
	}int mid=(l+r)>>1;
	if(p<=mid)modify(l,mid,p,v,rt<<1);
	else modify(mid+1,r,p,v,rt<<1|1);
	sum[rt]=merge(sum[rt<<1],sum[rt<<1|1]);
}

data query(int l,int r,int L,int R,int rt){
	if(l>R||r<L)return sum[0];
	if(l<=L&&R<=r)return sum[rt];
	return merge(query(l,r,L,(L+R)>>1,rt<<1),query(l,r,((L+R)>>1)+1,R,rt<<1|1));
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)a[i]=read();
	build(1,n,1);
	while(q--){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d",&x);
			modify(1,n,x,read(),1);
		}else {
			scanf("%d%d",&l,&r);
			printf("%.6f\n",query(l,r,1,n,1).L);
		}
	}
	return 0;
}