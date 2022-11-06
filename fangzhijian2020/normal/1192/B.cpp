#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,x,cnt,h[100005],tot,t1[100005],t2[100005];long long w,z,c[200005],lastans;
long long y;
struct tree{
	long long sum,maxl,maxr,minl,minr,dl,dr,ds,d;
}t[800005];
struct edge{int to,next,id;long long v;}e[200005];
void add(int x,int y,long long z,int num){
	e[++cnt]=(edge){y,h[x],num,z};h[x]=cnt;
}
void pushup(tree &k,tree L,tree R){
	tree l=L,r=R;
	k.sum=l.sum+r.sum;
	k.maxl=max(l.maxl,l.sum+r.maxl);
	k.maxr=max(r.maxr,l.maxr+r.sum);
	k.minl=min(l.minl,l.sum+r.minl);
	k.minr=min(r.minr,l.minr+r.sum);
	k.dl=max(l.dl,max(l.ds+r.maxl,r.dl-l.sum));
	k.dr=max(r.dr,max(r.ds-l.minr,r.sum+l.dr));
	k.ds=max(l.ds+r.sum,r.ds-l.sum);
	k.d=max(max(l.d,r.d),max(l.dr+r.maxl,r.dl-l.minr));
}
void build(int k,int l,int r){
	if(l==r){
		if(c[l]>=0)t[k].sum=t[k].maxl=t[k].maxr=c[l],t[k].minl=t[k].minr=0;
		else t[k].sum=t[k].minl=t[k].minr=c[l],t[k].maxl=t[k].maxr=0;
		t[k].dl=t[k].dr=t[k].ds=t[k].d=abs(c[l]);
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(t[k],t[k<<1],t[k<<1|1]);
}
void change(int k,int l,int r,int x){
	if(l==r){
		if(c[l]>=0)t[k].sum=t[k].maxl=t[k].maxr=c[l],t[k].minl=t[k].minr=0;
		else t[k].sum=t[k].minl=t[k].minr=c[l],t[k].maxl=t[k].maxr=0;
		t[k].dl=t[k].dr=t[k].ds=t[k].d=abs(c[l]);
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x);
	if(x>mid)change(k<<1|1,mid+1,r,x);
	pushup(t[k],t[k<<1],t[k<<1|1]);
}
void dfs(int x,int prt){
	int i,y;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;
		if(y!=prt){
			c[++tot]=e[i].v;
			t1[e[i].id]=tot;
			dfs(y,x);
			c[++tot]=-e[i].v;
			t2[e[i].id]=tot;
		}
	}
}
int main(){
	scanf("%d%d%lld",&n,&q,&w);int m=n;
	for(int i=1;i<n;++i){
		scanf("%d%d%lld",&x,&y,&z);
		add(x,y,z,i);add(y,x,z,i);
	}
	dfs(1,0);n=n-1<<1;build(1,1,n);
	for(int i=1;i<=q;++i){
		scanf("%d%lld",&x,&y);
		x=(x+lastans)%(m-1);
		y=(y+lastans)%w;
		c[t1[x+1]]=y;c[t2[x+1]]=-y;
		change(1,1,n,t1[x+1]);
		change(1,1,n,t2[x+1]);
		printf("%lld\n",lastans=t[1].d);
	}
	return 0;
}