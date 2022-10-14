#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOF(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1<<18|1;
vector<int>t[N<<2];
int n,m,q,s[N],a[N],w[N],ans[N];
int big[N<<5],*f[N<<1],*np(big);
#define lc p<<1
#define rc lc|1
#define root 1,1,m
#define lson lc,L,mid
#define rson rc,mid+1,R
V ask(int p,int L,int R,int l,int r,int x){
	if(L==l&&R==r)return void(t[p].push_back(x));
	int mid=L+R>>1;
	if(l>mid)return ask(rson,l,r,x);
	if(r<=mid)return ask(lson,l,r,x);
	ask(lson,l,mid,x),ask(rson,mid+1,r,x);
}
V input(){
	int l,r,x=scanf("%d%d",&n,&m);
	m=1<<32-__builtin_clz(m);
	FOR(i,1,n)scanf("%d",&x),a[x]^=1;
	scanf("%d",&q);
	FOR(i,1,q)scanf("%d%d",&l,&r),ask(root,l,r,i),i[w]=l;
}
V init(){FOR(i,1,m)s[i]=s[i-1]^a[i];}
I ask(int l,int r){return s[r]^s[l-1];}
V solve(int p,int L,int R){
	static int tmp[N];
	int mid=L+R>>1,len=R-L+1,d=len>>1,x,y;
	if(f[p]=np,np+=len,L!=R){
		solve(lson),solve(rson),tmp[0]=ask(mid+1,R)*d;
		FOF(i,0,d)if(a[L+i]^a[L+i+d])tmp[i+1]^=d,tmp[i+1+d]^=d;
		FOF(i,1,len)tmp[i]^=tmp[i-1];
		copy(tmp,tmp+len,f[p]),memset(tmp,0,len+1<<2);
		FOF(i,0,d)x=f[lc][i]^f[rc][i],f[p][i]^=x,f[p][i|d]^=x;
	}
	for(int v:t[p]){
		x=w[v]-1&len-1, ans[v]^=f[p][x];
		if(ask(L+x,R)  )ans[v]^=L-w[v]+x;
		if(ask(L,L+x-1))ans[v]^=L-w[v]+x-len;
	}
}
V work(){
	solve(root);
	FOR(i,1,q)cout<<"AB"[ans[i]==0];
}
int main(){
	input();
	init();
	work();
	return 0;
}