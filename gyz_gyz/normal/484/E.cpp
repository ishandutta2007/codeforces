#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 131072
#define M 5000000
using namespace std;
int b[M],L[M],R[M],l[M],r[M];
int n,m,tot,H,h[N],top[N],x,l1,r1,L1,R1,mid;
struct pr{int h,id;}p[N];
struct pp{int a,l,r,w;
	pp operator + (pp x){pp y;
		if(w&&x.w)y.w=w+x.w;else y.w=0;
		if(w)y.l=w+x.l;else y.l=l;
		if(x.w)y.r=x.w+r;else y.r=x.r;
		y.a=r+x.l;if(a>y.a)y.a=a;
		if(x.a>y.a)y.a=x.a;return y;
	}
}a[M];
inline bool cmp(pr x,pr y){return x.h<y.h;}
inline void nw(int x,int y){
	a[++tot]=a[x];b[tot]=y;
	L[tot]=L[x];R[tot]=R[x];
	l[tot]=l[x];r[tot]=r[x];
}
void f(int x,int y){
	if(L[x]==y&&R[x]==y){a[x].a=a[x].l=a[x].r=a[x].w=0;return;}
	if(R[l[x]]>=y){
		if(b[l[x]]!=b[x]){nw(l[x],b[x]);l[x]=tot;}
		f(l[x],y);
	}else{
		if(b[r[x]]!=b[x]){nw(r[x],b[x]);r[x]=tot;}
		f(r[x],y);
	}
	a[x]=a[l[x]]+a[r[x]];
}
pp q(int x,int l1,int r1){
	if(L[x]==l1&&R[x]==r1)return a[x];
	if(r1<=R[l[x]])return q(l[x],l1,r1);
	if(l1>=L[r[x]])return q(r[x],l1,r1);
	return q(l[x],l1,R[l[x]])+q(r[x],L[r[x]],r1);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&p[i].h);
	rep(i,1,n)p[i].id=i;
	sort(p+1,p+n+1,cmp);
	rep(i,1,n){
		if(i==1||p[i].h!=p[i-1].h)h[++H]=p[i].h;p[i].h=H;
	}
	L[1]=1;R[1]=N;top[0]=1;tot=N*2-1;
	rep(i,1,N-1){
		L[i*2]=L[i];R[i*2]=(L[i]+R[i])/2;
		L[i*2+1]=R[i*2]+1;R[i*2+1]=R[i];
		l[i]=i*2;r[i]=i*2+1;
	}
	rep(i,1,N*2-1)a[i].a=a[i].l=a[i].r=a[i].w=R[i]-L[i]+1;
	rep(i,1,n){int hh=p[i].h;
		if(!top[hh]){
			nw(top[hh-1],hh);top[hh]=tot;
		}
		f(top[hh],p[i].id);
	}
	scanf("%d",&m);
	rep(i,1,m){
		scanf("%d%d%d",&l1,&r1,&x);
		L1=0;R1=H-1;mid=(L1+R1+1)/2;
		for(;L1<R1;mid=(L1+R1+1)/2){
			if(q(top[mid],l1,r1).a>=x)L1=mid;else R1=mid-1;
		}
		printf("%d\n",h[mid+1]);
	}
}