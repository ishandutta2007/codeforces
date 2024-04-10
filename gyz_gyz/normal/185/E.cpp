#include<cstdio>
#include<algorithm>
#include<set>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define inf 200000002
#define mx 268435456
#define N 200000
#define M 2000000
using namespace std;
int n,m,k,ll,rr,mid,x1,y1,x2,y2,tot;bool u;
int a[M],L[M],R[M],l[M],r[M],L1[M],R1[M],l1[M],r1[M];
struct pr{int x,y,s;}t[N],p[N];set<int>se[M];
bool cmp(const pr &x,const pr &y){return x.x<y.x;}
bool cmp0(const pr &x,const pr &y){return x.s>y.s;}
void f(int x,int y,int z){if(z<a[x])a[x]=z;
	if(L[x]==y&&R[x]==y)return;	
	if(y<=(L[x]+R[x])/2){
		if(!l[x]){
			l[x]=++tot;a[tot]=inf*2;l[tot]=r[tot]=0;
			L[tot]=L[x];R[tot]=(L[x]+R[x])/2;
		}f(l[x],y,z);
	}else{
		if(!r[x]){
			r[x]=++tot;a[tot]=inf*2;l[tot]=r[tot]=0;
			L[tot]=(L[x]+R[x])/2+1;R[tot]=R[x];
		}f(r[x],y,z);
	}
}
int q(int x,int l0,int r0){if(!x)return inf*4;
	if(L[x]==l0&&R[x]==r0)return a[x];
	if((L[x]+R[x])/2>=r0)return q(l[x],l0,r0);
	if((L[x]+R[x])/2<l0)return q(r[x],l0,r0);
	return min(q(l[x],l0,(L[x]+R[x])/2),
	q(r[x],(L[x]+R[x])/2+1,r0));
}
void nw(int l,int r){
	tot++;l1[tot]=r1[tot]=0;L1[tot]=l;R1[tot]=r;
}
void ins(int x,int y,int z){se[x].insert(z);
	if(L1[x]==y&&R1[x]==y)return;
	if(y<=(L1[x]+R1[x])/2){
		if(!l1[x]){
			l1[x]=++tot;l1[tot]=r1[tot]=0;
			L1[tot]=L1[x];R1[tot]=(L1[x]+R1[x])/2;
		}ins(l1[x],y,z);
	}else{
		if(!r1[x]){
			r1[x]=++tot;l1[tot]=r1[tot]=0;
			L1[tot]=(L1[x]+R1[x])/2+1;R1[tot]=R1[x];
		}ins(r1[x],y,z);
	}
}
bool qr(int x,int l0,int r0,int L0,int R0){if(!x)return 0;
	if(L1[x]==l0&&R1[x]==r0)return 
		se[x].lower_bound(L0)!=se[x].upper_bound(R0);
	if((L1[x]+R1[x])/2>=r0)return qr(l1[x],l0,r0,L0,R0);
	if((L1[x]+R1[x])/2<l0)return qr(r1[x],l0,r0,L0,R0);
	return qr(l1[x],l0,(L1[x]+R1[x])/2,L0,R0)||
	qr(r1[x],(L1[x]+R1[x])/2+1,r0,L0,R0);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d%d",&t[i].x,&t[i].y);
	rep(i,1,m)scanf("%d%d",&p[i].x,&p[i].y);
	rep(i,1,n)t[i].x+=inf/2,t[i].y+=inf/2,t[i].s=inf*2;
	rep(i,1,m)p[i].x+=inf/2,p[i].y+=inf/2;	
	sort(t+1,t+n+1,cmp);sort(p+1,p+m+1,cmp);
	l[1]=r[1]=0;k=tot=1;a[1]=inf*4;L[1]=1;R[1]=mx;
	rep(i,1,n){
		for(;k<=m&&p[k].x<=t[i].x;k++)f(1,p[k].y,-p[k].x-p[k].y);
		t[i].s=min(t[i].s,t[i].x+t[i].y+q(1,1,t[i].y));
	}
	l[1]=r[1]=0;k=tot=1;a[1]=inf*4;L[1]=1;R[1]=mx;
	rep(i,1,n){
		for(;k<=m&&p[k].x<=t[i].x;k++)f(1,p[k].y,-p[k].x+p[k].y);
		t[i].s=min(t[i].s,t[i].x-t[i].y+q(1,t[i].y,inf));
	}
	l[1]=r[1]=0;k=m;tot=1;a[1]=inf*4;L[1]=1;R[1]=mx;
	dep(i,n,1){
		for(;k>0&&p[k].x>=t[i].x;k--)f(1,p[k].y,p[k].x-p[k].y);
		t[i].s=min(t[i].s,-t[i].x+t[i].y+q(1,1,t[i].y));
	}
	l[1]=r[1]=0;k=m;tot=1;a[1]=inf*4;L[1]=1;R[1]=mx;
	dep(i,n,1){
		for(;k>0&&p[k].x>=t[i].x;k--)f(1,p[k].y,p[k].x+p[k].y);
		t[i].s=min(t[i].s,-t[i].x-t[i].y+q(1,t[i].y,inf));
	}
	tot=1;L1[1]=1;R1[1]=mx*2;
	sort(t+1,t+n+1,cmp0);ll=0;rr=inf*2;
	rep(i,1,m)ins(1,p[i].x-p[i].y+inf,p[i].x+p[i].y);
	for(mid=(ll+rr)/2;ll<rr;mid=(ll+rr)/2){
		x1=1;y1=1;x2=inf*2;y2=inf*2;u=0;
		rep(i,1,n){
			int X=t[i].x-t[i].y+inf,Y=t[i].x+t[i].y;
			if(X-mid>x1)x1=X-mid;if(Y-mid>y1)y1=Y-mid;
			if(X+mid<x2)x2=X+mid;if(Y+mid<y2)y2=Y+mid;
			if(x1>x2||y1>y2)break;
			if(t[i+1].s>mid)continue;
			if(i==n||qr(1,max(x1-mid+t[i+1].s,1),
			min(x2+mid-t[i+1].s,inf*2),
			max(y1-mid+t[i+1].s,1),
			min(y2+mid-t[i+1].s,inf*2))){u=1;break;}
		}
		if(u)rr=mid;else ll=mid+1;
	}
	printf("%d\n",mid);
}