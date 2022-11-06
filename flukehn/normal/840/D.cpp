#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=3e5+5;
int n,q;
struct ztree{
	struct node{
		int tot;
		node *ls,*rs;
	} pl[N*30], *cur=pl, *rt[N];
	#define mid (L+R>>1)
	void init(){
		rt[0]=cur++;
		rt[0]->ls=rt[0]->rs=rt[0];
	}
	void updata(node *&o,node *x,int L,int R,int v){
		o=cur++,o->tot=x->tot+1;
		o->ls=x->ls,o->rs=x->rs;
		if(L!=R){
			if(v<=mid)updata(o->ls,x->ls,L,mid,v);
			else updata(o->rs,x->rs,mid+1,R,v);
		}
	}
	int query(node *o,node *x,int L,int R,int v){
		if(o->tot-x->tot<v)return -1;
		else if(L==R)return L;
		int temp=-1;
		if(o->ls->tot-x->ls->tot>=v)temp=query(o->ls,x->ls,L,mid,v);
		if(~temp)return temp;
		else return query(o->rs,x->rs,mid+1,R,v);
	}
	void updata(int t,int x){updata(rt[t],rt[t-1],1,n,x);}
	int query(int l,int r,int x){return query(rt[r],rt[l-1],1,n,x);}
}seg;
int main() {
	n=rd(),q=rd();
	seg.init();
	rep(i,1,n){
		int x=rd();
		seg.updata(i,x); 
	}
	while(q--){
		int l=rd(),r=rd(),k=rd(),x=(r-l+1)/k+1;
		printf("%d\n",seg.query(l,r,x));
	}
}