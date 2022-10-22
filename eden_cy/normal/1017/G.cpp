#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
#define EOR(i,x) for(int i=Head[x]; ~i; i=Nxt[i])

inline void rd(int &x) {
	static char c;x=0;
	while(c=getchar(),c<48);
	do x=(x<<3)+(x<<1)+(c^48);
	while(c=getchar(),c>47);
}
inline void pt(int x) {
	if(!x) putchar('0');
	static int Stk[30],tp=0;
	for(; x; x/=10) Stk[tp++]=x%10;
	while(tp) putchar(Stk[--tp]^48);
}
inline void ptn(const int &x) {pt(x);putchar('\n');}

const int M=(int)1e5+50;

int Head[M],E[M<<1],Nxt[M<<1],tol;
void Edge(int x,int y) {
	E[tol]=y;Nxt[tol]=Head[x];Head[x]=tol++;
}
int n,m;
//namespace P_1{
//	int Fa[M];
//	void dfs(int x,int fr) {
//		Fa[x]=fr;
//		EOR(i,x) if(E[i]!=fr) dfs(E[i],x);
//	}
//	bool mark[M];
//	void f1(int x) {
//		if(!mark[x]) {
//			mark[x]=true;
//			return ;
//		}
//		EOR(i,x) if(E[i]!=Fa[x]) f1(E[i]);
//	}
//	void f2(int x) {
//		mark[x]=0;
//		EOR(i,x) if(E[i]!=Fa[x]) f2(E[i]);
//	}
//	void solve() {
//		dfs(1,0);
//		FOR(i,1,m) {
//			int op,x;
//			rd(op);rd(x);
//			if(op==1) {
//				f1(x);
//			} else if(op==2) {
//				f2(x);
//			} else {
//				puts(mark[x]?"Yes":"No");
//			}
//		}
//	}
//}
namespace P_2{
	
	#define lson L,mid,p<<1
	#define rson mid+1,R,p<<1|1
	
	struct node{
		int rmx,tot;
	}sum[M<<2];
	bool clr[M<<2];
	node Merge(node l,node r) {
		node tmp;
		tmp.rmx=max(r.rmx,r.tot+l.rmx);
		tmp.tot=l.tot+r.tot;
		return tmp;
	}
	void build(int L,int R,int p) {
		sum[p]=(node){-1,-(R-L+1)};
		if(L==R) return ;
		int mid=L+R>>1;
		build(lson);
		build(rson);
	}
	void Down(int L,int R,int p) {
		if(!clr[p]) return ;
		int mid=L+R>>1;
		clr[p<<1]=clr[p<<1|1]=true;
		sum[p<<1]=(node){-1,-(mid-L+1)};
		sum[p<<1|1]=(node){-1,-(R-mid)};
		clr[p]=false;
	}
	void Update(int L,int R,int p,int x,int v) {
		if(L==R) {
			sum[p].rmx+=v;
			sum[p].tot+=v;
			return ;
		}
		Down(L,R,p);
		int mid=L+R>>1;
		if(x<=mid) Update(lson,x,v);
		else Update(rson,x,v);
		sum[p]=Merge(sum[p<<1],sum[p<<1|1]);
	}
	void Modify(int L,int R,int p,int l,int r) {
		if(L==l && R==r) {
			clr[p]=true;
			sum[p]=(node){-1,-(R-L+1)};
			return ;
		}
		Down(L,R,p);
		int mid=L+R>>1;
		if(r<=mid) Modify(lson,l,r);
		else if(l>mid) Modify(rson,l,r);
		else {
			Modify(lson,l,mid);
			Modify(rson,mid+1,r);
		}
		sum[p]=Merge(sum[p<<1],sum[p<<1|1]);
	}
	node Query(int L,int R,int p,int l,int r) {
		if(L==l && R==r) return sum[p];
		Down(L,R,p);
		int mid=L+R>>1;
		if(r<=mid) return Query(lson,l,r);
		else if(l>mid) return Query(rson,l,r);
		else return Merge(Query(lson,l,mid),Query(rson,mid+1,r));
	}
	int Fa[M],Top[M],son[M],sz[M];
	int SgId[M],Lt[M],Rt[M],tid;
	void dfs(int x,int fr) {
		int y;Fa[x]=fr;son[x]=0;sz[x]=1;
		EOR(i,x) if((y=E[i])!=fr) {
			dfs(y,x);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y;
		}
	}
	void rdfs(int x,int tp) {
		Top[x]=tp;
		SgId[x]=Lt[x]=++tid;
		if(son[x]) rdfs(son[x],tp);
		EOR(i,x) if(E[i]!=Fa[x] && E[i]!=son[x]) rdfs(E[i],E[i]);
		Rt[x]=tid;
	}
	int solve(int x) {
		node tmp=Query(1,n,1,SgId[Top[x]],SgId[x]);
		for(x=Fa[Top[x]]; x; x=Fa[Top[x]]) {
			node t=Query(1,n,1,SgId[Top[x]],SgId[x]);
			tmp=Merge(Query(1,n,1,SgId[Top[x]],SgId[x]),tmp);
		}
		return tmp.rmx;
	}
	void solve() {
		dfs(1,0);
		rdfs(1,1);
		build(1,n,1);
		FOR(i,1,m) {
			int op,x;
			rd(op);rd(x);
			if(op==1) {
				Update(1,n,1,SgId[x],1);
			} else if(op==2) {
				int t=solve(x);
				Update(1,n,1,SgId[x],-t-1);
				if(Lt[x]<Rt[x]) Modify(1,n,1,Lt[x]+1,Rt[x]);
			} else {
				int res=solve(x);
				puts(res>=0?"black":"white");
			}
		}
	}
}
//namespace P_3{
//	#define lson L,mid,p<<1
//	#define rson mid+1,R,p<<1|1
//	
//	const int INF=(int)0x3f3f3f3f;
//	
//	bool clr[M<<2];
//	int pos[M<<2];
//	void build(int L,int R,int p) {
//		pos[p]=L;
//		if(L==R) return ;
//		int mid=L+R>>1;
//		build(lson);
//		build(rson);
//	}
//	void Down(int L,int R,int p) {
//		if(!clr[p]) return ;
//		clr[p<<1]=clr[p<<1|1]=true;
//		int mid=L+R>>1;
//		pos[p<<1]=L;
//		pos[p<<1|1]=mid+1;
//		clr[p]=false;
//	}
//	void Update(int L,int R,int p,int x) {
//		if(L==R) {
//			pos[p]=INF;
//			return ;
//		}
//		Down(L,R,p);
//		int mid=L+R>>1;
//		if(x<=mid) Update(lson,x);
//		else Update(rson,x);
//		pos[p]=min(pos[p<<1],pos[p<<1|1]);
//	}
//	void Modify(int L,int R,int p,int l,int r) {
//		if(L==l && R==r) {
//			clr[p]=true;
//			pos[p]=L;
//			return ;
//		}
//		Down(L,R,p);
//		int mid=L+R>>1;
//		if(r<=mid) Modify(lson,l,r);
//		else if(l>mid) Modify(rson,l,r);
//		else {
//			Modify(lson,l,mid);
//			Modify(rson,mid+1,r);
//		}
//		pos[p]=min(pos[p<<1],pos[p<<1|1]);
//	}
//	int Query(int L,int R,int p,int x) {
//		if(L==R) {
//			if(pos[p]==INF) return 1;
//			else return 0;
//		}
//		Down(L,R,p);
//		int mid=L+R>>1;
//		if(x<=mid) return Query(lson,x);
//		else return Query(rson,x);
//	}
//	int Find(int L,int R,int p,int l,int r) {
//		if(L==l && R==r) return pos[p];
//		Down(L,R,p);
//		int mid=L+R>>1;
//		if(r<=mid) return Find(lson,l,r);
//		else if(l>mid) return Find(rson,l,r);
//		else return min(Find(lson,l,mid),Find(rson,mid+1,r));
//	}
//	void solve() {
//		build(1,n,1);
//		FOR(i,1,m) {
//			int op,x;
//			rd(op);rd(x);
//			if(op==1) {
//				int s=Find(1,n,1,x,n);
//				if(s!=INF) Update(1,n,1,s);
//			} else if(op==2) {
//				Modify(1,n,1,x,n);
//			} else {
//				bool res=Query(1,n,1,x);
//				puts(res?"Yes":"No");
//			}
//		}
//	}
//}
int main() {
//	printf("%lf\n",(sizeof(P_1)+sizeof(P_2)+sizeof(P_3))/1024.0/1024);
//	freopen("plague.in","r",stdin);
//	freopen("plague.out","w",stdout);
	
	memset(Head,-1,sizeof(Head));
	rd(n);rd(m);
	bool f=true;
	FOR(i,1,n-1) {
		int x;rd(x);
		if(x!=i) f=false;
		Edge(i+1,x);
		Edge(x,i+1);
	}
//	if(f) 
//		P_3::solve();
//	else if(1ll*n*m<=(int)1e7) 
//		P_1::solve();
//	else 
		P_2::solve();
	return 0;
}