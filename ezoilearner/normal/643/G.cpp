#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
constexpr int N=150005;
int n,m,p;
struct Node{
	int num,tag,n[5],c[5];
	Node operator+(const Node&o)const{
		Node res;
		res.num=o.num,res.tag=0;
		rep(i,0,o.num-1)res.n[i]=o.n[i],res.c[i]=o.c[i];
		rep(i,0,num-1){
			int fl=0;
			rep(j,0,res.num-1){
				if(n[i]==res.n[j])res.c[j]+=c[i],fl=1;
				if(fl)break;
			}
			if(fl)continue;
			if(res.num<p){
				res.n[res.num]=n[i],res.c[res.num]=c[i],++res.num;continue;
			}
			int k=0;
			rep(j,1,res.num-1)
				if(res.c[j]<res.c[k])k=j;
			if(c[i]<res.c[k])
				rep(j,0,res.num-1)res.c[j]-=c[i];
			else{
				int tmp=res.c[k];
				res.n[k]=n[i],res.c[k]=c[i];
				rep(j,0,res.num-1)res.c[j]-=tmp;
			}
		}
		return res;
	}
}t[N<<2];
inline void rd(int &x){
    x=0;int f=1;char c;while(!isdigit(c=getchar()))if(c=='-')f=-f;
    do x=x*10+(48^c);while(isdigit(c=getchar()));x*=f;
}
inline void pushup(int x){t[x]=t[x<<1]+t[x<<1|1];}
inline void pushtag(int x,int len,int v){
	t[x].num=1,t[x].tag=t[x].n[0]=v,t[x].c[0]=len;
}
inline void pushdown(int x,int l,int r){
	if(!t[x].tag)return;
	int mid=l+r>>1;
	pushtag(x<<1,mid-l+1,t[x].tag);
	pushtag(x<<1|1,r-mid,t[x].tag);
	t[x].tag=0;
}
inline void build(int x,int l,int r){
	if(l==r){
		rd(t[x].n[0]),t[x].c[0]=t[x].num=1;return;
	}
	int mid=l+r>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	pushup(x);
}
inline void update(int x,int l,int r,int L,int R,int v){
	if(L<=l&&R>=r)return void(pushtag(x,r-l+1,v));
	int mid=l+r>>1;pushdown(x,l,r);
	if(L<=mid)update(x<<1,l,mid,L,R,v);
	if(R>mid)update(x<<1|1,mid+1,r,L,R,v);
	pushup(x);
}
inline Node query(int x,int l,int r,int L,int R){
	if(L<=l&&R>=r)return t[x];
	int mid=l+r>>1;pushdown(x,l,r);
	if(R<=mid)return query(x<<1,l,mid,L,R);
	else if(L>mid)return query(x<<1|1,mid+1,r,L,R);
	return query(x<<1,l,mid,L,R)+query(x<<1|1,mid+1,r,L,R);
}
int main(){
	rd(n),rd(m),rd(p),p=100/p;
	build(1,1,n);
	while(m--){
		int op,l,r,v;
		rd(op),rd(l),rd(r);
		if(op==1)rd(v),update(1,1,n,l,r,v);
		else{
			Node ans=query(1,1,n,l,r);
			printf("%d",ans.num);
			rep(i,0,ans.num-1)printf(" %d",ans.n[i]);
			puts("");
		}
	}
	return 0;
}