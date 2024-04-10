#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,x,y;char c[200005];
struct tree{
	int sum,maxl,maxr,minl,minr,dl,dr,ds,d;
}t[800005];
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
		if(c[l]=='(')t[k].sum=t[k].maxl=t[k].maxr=1,t[k].minl=t[k].minr=0;
		else t[k].sum=t[k].minl=t[k].minr=-1,t[k].maxl=t[k].maxr=0;
		t[k].dl=t[k].dr=t[k].ds=t[k].d=1;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(t[k],t[k<<1],t[k<<1|1]);
}
void change(int k,int l,int r,int x){
	if(l==r){
		if(c[l]=='(')t[k].sum=t[k].maxl=t[k].maxr=1,t[k].minl=t[k].minr=0;
		else t[k].sum=t[k].minl=t[k].minr=-1,t[k].maxl=t[k].maxr=0;
		t[k].dl=t[k].dr=t[k].ds=t[k].d=1;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x);
	if(x>mid)change(k<<1|1,mid+1,r,x);
	pushup(t[k],t[k<<1],t[k<<1|1]);
}
int main(){
	scanf("%d%d%s",&n,&q,c+1);
	n=n-1<<1;build(1,1,n);printf("%d\n",t[1].d);
	for(int i=1;i<=q;++i){
		scanf("%d%d",&x,&y);
		if(c[x]!=c[y]){
			swap(c[x],c[y]);
			change(1,1,n,x);
			change(1,1,n,y);
		}
		printf("%d\n",t[1].d);
	}
	return 0;
}