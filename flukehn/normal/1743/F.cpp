#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int mo=998244353;
const int N=3e5+11;
int L[N],R[N];
int n;
inline int inc(int &x,int y){return x=(x+y>=mo?x+y-mo:x+y);}

const int M=N<<2;
const int H=2;
struct mat{
	int a[H][H];
	int* operator[](int t){
		return a[t];
	}
	const int* operator[](int t)const{
		return a[t];
	}
	mat(int t=0){
		For(i,0,H) For(j,0,H) a[i][j]=t*(i==j);
	}
	mat operator*(const mat&t)const{
		mat r;
		For(i,0,H)For(k,0,H)For(j,0,H)
			inc(r[i][j], 1LL*a[i][k]*t[k][j]%mo);
		return r;
	}
};

mat tg[M];
int istg[M];
mat A,B,I(1);
#define m ((l+r)>>1)
#define ls (x<<1)
#define rs (x<<1|1)
void build(int x,int l,int r){
	tg[x]=I;
	istg[x]=0;
	if(l+1>=r){
	}else{
		build(ls,l,m);
		build(rs,m,r);
	}
}
void pt(int x,mat v){
	istg[x]=1;
	tg[x]=tg[x]*v;
}
void pd(int x){
	if(istg[x]){
		istg[x]=0;
		pt(ls,tg[x]);
		pt(rs,tg[x]);
		tg[x]=I;
	}
}
mat qv;
int ql,qr;
void upd(int x,int l,int r){
	//dbg(x,l,r,ql,qr);
	if(ql<=l&&r<=qr){
		pt(x,qv);
	}else{
		pd(x);
		if(ql<m)upd(ls,l,m);
		if(qr>m)upd(rs,m,r);
	}
}
int ans;
void dfs(int x,int l,int r){
	if(l+1>=r){
		int v=L[0]<=l && l<=R[0];
		inc(ans, tg[x][v][1]);
	}else{
		pd(x);
		dfs(ls,l,m);
		dfs(rs,m,r);
	}
}
#undef ls
#undef rs
#undef m
int solve(){
	For(i,0,n)cin>>L[i]>>R[i];
	int mx=0;
	For(i,0,n)mx=max(mx,R[i]);
	ans=0;
	A[0][0]=3,A[0][1]=0;
	A[1][0]=1,A[1][1]=2;
	B[0][0]=1,B[0][1]=2;
	B[1][0]=1,B[1][1]=2;
	mx++;
	build(1,0,mx);
	For(i,1,n) {
		qv=A;
		if(L[i]>0) ql=0,qr=L[i],upd(1,0,mx);
		if(R[i]+1<mx) ql=R[i]+1,qr=mx,upd(1,0,mx);
		qv=B;
		ql=L[i],qr=R[i]+1;
		upd(1,0,mx);
	}
	dfs(1,0,mx);
	return ans;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	while(cin>>n){
		cout<<solve()<<"\n";
	}
}