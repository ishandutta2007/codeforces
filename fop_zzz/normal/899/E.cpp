#include<bits/stdc++.h>
#define pa pair<int,int>
#define N 200005
using namespace std;
int a[N];
pa b[N];
int n,tot,sum;
struct fks{
	int l,r,len;
	friend bool operator <(const fks &a,const fks &b){
		if (a.len!=b.len) return a.len<b.len;
		return a.l>b.l;
	}
	friend fks operator +(const fks &a,const fks &b){
		return (fks){a.l,b.r,a.len+b.len};
	} 
};
struct node{
	fks best,lbest,rbest;
	int lv,rv,cl,sum;
	void clear(){
		cl=1; lv=-1; rv=-1;
		best.len=0;
		lbest.len=0;
		rbest.len=0;
	}
	void init(int L,int x,int y){
		best=(fks){L,L,y};
		lbest=rbest=best;
		sum=y; lv=rv=x; cl=0;
	}
	friend node operator +(const node &a,const node &b){
		static node c;
		if (a.cl&&b.cl){
			c.cl=1;
			c.clear();
			return c;
		}
		if (b.cl) return a;
		if (a.cl) return b;
		c.cl=0; c.sum=a.sum+b.sum;
		c.lv=a.lv; c.rv=b.rv;
		c.lbest=a.lbest;
		c.rbest=b.rbest;
		c.best=max(a.best,b.best);
		if (a.rv==b.lv){
			if (a.lbest.len==a.sum) c.lbest=max(c.lbest,a.lbest+b.lbest);
			if (b.rbest.len==b.sum) c.rbest=max(c.rbest,a.rbest+b.rbest);
			c.best=max(c.best,a.rbest+b.lbest);
		}
		return c;
	}
}t[N*4];
void pushdown(int k){
	if (t[k].cl==1)
		t[k*2].clear(),
		t[k*2+1].clear();
}
void build(int k,int l,int r){
	if (l==r){
		t[k].init(l,b[l].first,b[l].second);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
	//if (k==1){
		//printf("%d %d %d\n",t[k*2].best.l,t[k*2].best.r,t[k*2].best.len);
		//printf("%d %d %d\n",t[k*2+1].best.l,t[k*2+1].best.r,t[k*2+1].best.len);
	//
}
void clear(int k,int l,int r,int x,int y){
	if (l==x&&r==y){
		t[k].clear();
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) clear(k*2,l,mid,x,y);
	else if (x>mid) clear(k*2+1,mid+1,r,x,y);
	else clear(k*2,l,mid,x,mid),clear(k*2+1,mid+1,r,mid+1,y);
	t[k]=t[k*2]+t[k*2+1]; 
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int s=1;
	for (int i=2;i<=n;i++)
		if (a[i]!=a[i-1])
			b[++tot]=pa(a[i-1],s),s=1;
		else s++;
	b[++tot]=pa(a[n],s);
	n=tot;
	build(1,1,tot);
	while (!t[1].cl){
		int L=t[1].best.l;
		int R=t[1].best.r;
		//printf("%d %d %d\n",L,R,t[1].best.len);
		clear(1,1,tot,L,R);
		sum++;
	}
	printf("%d\n",sum);
}