#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC target("avx")
#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(ll x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(ll x,char ch)
{
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],A,B,mx[22][200002],L[200002],pos[200002];
char s[1000002];
vector<int>D[200002];
inline int ask(re int l,re int r){
	re int tmp=L[r-l+1];
	return max(mx[tmp][l],mx[tmp][r-(1<<tmp)+1]);
}
struct node{
	int l,r,o;
	bool operator <(const node A)const{return l>A.l;}
};
vector<node>QQ[200002],Qry[200002];
inline void ins(re int l1,re int r1,re int l2,re int r2){
	QQ[l1].push_back((node){l2,r2,1}),QQ[r1+1].push_back((node){l2,r2,-1});
}
ll ans[1000002];
struct Mat{
	int a00,a01;ll a02;int a11;ll a12;int a22;
	Mat operator +(const Mat A)const{
		Mat B;
		B.a00=a00+A.a00;
		B.a01=a01+A.a01;
		B.a02=a02+A.a02;
		B.a11=a11+A.a11;
		B.a12=a12+A.a12;
		B.a22=a22+A.a22;
		return B;
	}
}T[800002],TG[800002],I,XX;
inline Mat mul(Mat A,Mat B,re int len=3){
	Mat C;
	C.a00=A.a00*B.a00;
	C.a01=A.a00*B.a01+A.a01*B.a11;
	C.a02=A.a00*B.a02+A.a01*B.a12+A.a02*B.a22;
	C.a11=A.a11*B.a11;
	C.a12=A.a11*B.a12+A.a12*B.a22;
	C.a22=A.a22*B.a22;
	return C;
}
inline void build(re int p,re int l,re int r){
	TG[p]=I,T[p].a00=1;
	if(l==r)return;
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	T[p]=T[p<<1]+T[p<<1|1];
}
inline void Mul(re int p,Mat &x){T[p]=mul(T[p],x,1),TG[p]=mul(TG[p],x);}
inline void pd(re int p){
	if(TG[p].a01||TG[p].a12||TG[p].a02){
		Mul(p<<1,TG[p]),Mul(p<<1|1,TG[p]);
		TG[p]=I;
	}
}
inline void mul(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y)return Mul(p,XX);
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)mul(p<<1,l,mid,x,y);
	if(y>mid)mul(p<<1|1,mid+1,r,x,y);
	T[p]=T[p<<1]+T[p<<1|1];
}
inline void build(re int l,re int r){
	if(l==r)return;
	re int val=ask(l,r),pp=pos[val];
	vector<node>X;
	for(auto x:D[val]){
		if(x>=val/x)continue;
		re int p1=pos[x],p2=pos[val/x];
		if(p1<l||p2<l||p1>r||p2>r)continue;
		re int mn=min(p1,min(p2,pp)),mx=max(p1,max(p2,pp));
		X.push_back((node){mn,mx});
	}
	X.push_back((node){l-1,n+1});
	sort(X.begin(),X.end()); 
	re int Mn=n+1,lst=pp+1;
	for(re int i=0;i<X.size();++i){
		Mn=min(Mn,X[i].r);
		if(i+1!=X.size()&&X[i].l!=X[i+1].l)ins(X[i+1].l+1,X[i].l,Mn,r),lst=X[i].l;
	}
	if(pp^l)build(l,pp-1);
	if(pp^r)build(pp+1,r);
}
inline ll ask(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y)return T[p].a02;
	pd(p);
	re int mid=l+r>>1;re ll ss=0;
	if(x<=mid)ss+=ask(p<<1,l,mid,x,y);
	if(y>mid)ss+=ask(p<<1|1,mid+1,r,x,y);
	return ss;
}
int main(){
	srand(time(0)),n=read(),m=read(),I.a00=I.a11=I.a22=1;
	for(re int i=1;i<=n;++i)for(re int j=i;j<=n;j+=i)D[j].push_back(i);
	for(re int i=1;i<=n;++i)a[i]=mx[0][i]=read(),pos[a[i]]=i;
	for(re int i=2;i<=n;++i)L[i]=L[i>>1]+1;
	for(re int i=1;i<=20;++i)
		for(re int j=1;j+(1<<i)-1<=n;++j)
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<i-1)]);
	build(1,n),build(1,1,n);
	for(re int i=1;i<=m;++i){  
		re int l=read(),r=read();
		Qry[r].push_back((node){l,r,i});
		Qry[l-1].push_back((node){l,r,-i});
	}
	for(re int i=1;i<=n;++i){
		for(auto o:QQ[i]){
			XX=I,XX.a01=o.o;
			mul(1,1,n,o.l,o.r);
		}
		XX=I,XX.a12=1,mul(1,1,n,1,n);
		for(auto o:Qry[i]){
			if(o.o>0)ans[o.o]+=ask(1,1,n,o.l,o.r);
			else ans[-o.o]-=ask(1,1,n,o.l,o.r);
		}
	}
	for(re int i=1;i<=m;++i)printnum(ans[i],'\n');pc('o',1);
}