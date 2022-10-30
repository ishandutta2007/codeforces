#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)	
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
typedef std::pair<int,int> pi;
const int N=50005,M=100005,NC=M*300;
std::vector<int> v[N];
int ans[N],n,m,X[M],Y[M];
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int mn[NC],ls[NC],rs[NC],nc,rt[N<<2];
void upd(int y,int t,int l,int r,int &u){
	if(!u)u=++nc,mn[u]=t;
	else chmin(mn[u],t);
	if(l==r)return;
	int mid=(l+r)>>1;
	y<=mid?upd(y,t,l,mid,ls[u]):upd(y,t,mid+1,r,rs[u]);
}
int _ask(int L,int R,int l,int r,int u){
	if(!u)return 1e9;
	if(L<=l&&r<=R)return mn[u];
	int mid=(l+r)>>1;
	if(L<=mid&&R>mid)return std::min(_ask(L,R,l,mid,ls[u]),_ask(L,R,mid+1,r,rs[u]));
	return L<=mid?_ask(L,R,l,mid,ls[u]):_ask(L,R,mid+1,r,rs[u]);
}
void ins(int x,int y,int t,int l,int r,int u){
	upd(y,t,1,n,rt[u]);
	if(l==r)return;
	int mid=(l+r)>>1;
	x<=mid?ins(x,y,t,l,mid,ls(u)):ins(x,y,t,mid+1,r,rs(u));
}
int ask(int L1,int R1,int L2,int R2,int l,int r,int u){
	if(L1<=l&&r<=R1)return _ask(L2,R2,1,n,rt[u]);
	int mid=(l+r)>>1;
	if(L1<=mid&&R1>mid)return std::min(ask(L1,R1,L2,R2,l,mid,ls(u)),ask(L1,R1,L2,R2,mid+1,r,rs(u)));
	return L1<=mid?ask(L1,R1,L2,R2,l,mid,ls(u)):ask(L1,R1,L2,R2,mid+1,r,rs(u));
}
int solve(int l1,int r1,int l2,int r2){
	if(l1>r1||l2>r2)return 0;
	int o=ask(l1,r1,l2,r2,1,n,1);
	if(o>m)return 0;
	return Y[o]-X[o]+1+solve(l1,X[o]-1,l2,X[o]-1)+solve(Y[o]+1,r1,Y[o]+1,r2);
}
int main(){
	read(n,m);
	for(int i=1,x,y;i<=m;++i)read(x,y),v[y-x+1].pb(i),X[i]=x,Y[i]=y;
	for(int i=n;i>=1;--i){
		for(auto it:v[i])ins(X[it],Y[it],it,1,n,1);
		ans[i]=solve(1,n,1,n);
	}
	for(int i=1;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}