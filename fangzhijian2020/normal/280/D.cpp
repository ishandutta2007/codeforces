#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,opt,x,y,z,top,l[25],r[25];
inline int read(){
	int res=0,bj=0;char ch=getchar();
	while(ch<'0'||ch>'9')bj|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
	return bj?-res:res;
}
void print(int x){
	if(x>9)print(x/10);
	putchar(x%10^48);
}
struct node{
	int l,r,sum;
	inline node(int L=0,int R=0,int Sum=0){l=L;r=R;sum=Sum;}
	inline node operator+(const node &a)const{
		return node(l,a.r,sum+a.sum);
	}
	inline void rev(){sum=-sum;}
	inline bool operator<(const node &a)const{
		return sum<a.sum;
	}
};
struct tree{
	node sum,maxx,minn,maxl,maxr,minl,minr;char lazy;
	inline void reverse(){
		sum.rev();maxx.rev();minn.rev();
		maxl.rev();maxr.rev();
		minl.rev();minr.rev();
		swap(maxl,minl);swap(maxr,minr);
		swap(maxx,minn);lazy^=1;
	}
	inline void pushup(const tree &l,const tree &r){
		sum=l.sum+r.sum;
		maxx=max(max(l.maxx,r.maxx),l.maxr+r.maxl);
		minn=min(min(l.minn,r.minn),l.minr+r.minl);
		maxl=max(l.maxl,l.sum+r.maxl);
		maxr=max(r.maxr,l.maxr+r.sum);
		minl=min(l.minl,l.sum+r.minl);
		minr=min(r.minr,l.minr+r.sum);
	}
}t[400005];
void pushdown(int k){
	if(t[k].lazy){
		t[k<<1].reverse();
		t[k<<1|1].reverse();
		t[k].lazy=0;
	}
}
void build(int k,int l,int r){
	if(l==r){
		x=read();t[k].sum=node(l,r,x);
		t[k].maxx=t[k].maxl=t[k].maxr=t[k].sum;
		t[k].minn=t[k].minl=t[k].minr=t[k].sum;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	t[k].pushup(t[k<<1],t[k<<1|1]);
}
void change(int k,int l,int r,int x){
	if(l==r){
		y=read();t[k].sum=node(l,r,y);
		t[k].maxx=t[k].maxl=t[k].maxr=t[k].sum;
		t[k].minn=t[k].minl=t[k].minr=t[k].sum;
		return;
	}
	int mid=l+r>>1;pushdown(k);
	if(x<=mid)change(k<<1,l,mid,x);
	else change(k<<1|1,mid+1,r,x);
	t[k].pushup(t[k<<1],t[k<<1|1]); 
}
void change(int k,int l,int r,int L,int R){
	if(L<=l&&r<=R){t[k].reverse();return;}
	int mid=l+r>>1;pushdown(k);
	if(L<=mid)change(k<<1,l,mid,L,R);
	if(R>mid)change(k<<1|1,mid+1,r,L,R);
	t[k].pushup(t[k<<1],t[k<<1|1]); 
}
tree query(int k,int l,int r,int L,int R){
	if(L<=l&&r<=R)return t[k];
	int mid=l+r>>1;tree ans;pushdown(k);
	if(R<=mid)return query(k<<1,l,mid,L,R);
	else if(L>mid)return query(k<<1|1,mid+1,r,L,R);
	else ans.pushup(query(k<<1,l,mid,L,R),query(k<<1|1,mid+1,r,L,R));
	return ans;
}
int main(){
	n=read();build(1,1,n);m=read();
	for(int i=1;i<=m;++i){
		opt=read();
		if(!opt){
			x=read();
			change(1,1,n,x);
		}
		else{
			x=read();y=read();z=read();
			int sum=0;
			for(int j=1;j<=z;++j){
				node ans=query(1,1,n,x,y).maxx;
				if(ans.sum>0){
					sum+=ans.sum;
					l[j]=ans.l;r[j]=ans.r;
					change(1,1,n,l[j],r[j]);
				}
				else{
					z=j-1;break;
				}
			}
			if(sum)print(sum),puts("");
			else puts("0");
			for(int j=1;j<=z;++j){
				change(1,1,n,l[j],r[j]);
			}
		}
	}
	return 0;
}