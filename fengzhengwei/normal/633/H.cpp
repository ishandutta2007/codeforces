#pragma GCC optimize(2) 
#pragma GCC target("avx,sse2,sse3,sse4,mmx") 
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Mxdt=100000;
inline char gc() {
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj) {
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
inline int read() {
	int res=0;
	char ch=gc();
	while(ch<'0')ch=gc();
	while(ch>='0')res=(res<<3)+(res<<1)+(ch^48),ch=gc();
	return res;
}
void print(int x) {
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch) {
	if(x<0)pc('-',false),x=-x;
	print(x),pc(ch,false);
}
int n,m;
const int xx=3e4+5;
int a[xx],lsh[xx];
int B;
int bel(int x){return (x-1)/B+1;}
struct node
{
	int l,r,id;
	bool operator<(const node&w)const{return bel(l)==bel(w.l)?bel(l)&1?r<w.r:r>w.r:l<w.l;}
}e[xx];
struct matrix
{
	int a,b,c,d;
	void set()
	{
		/*
		a,b
		c,d
		*/
		a=d=1;
		b=c=0;
	}
	void operator*(const matrix&w)
	{
		matrix s;
		s.a=(a*w.a+b*w.c)%m;
		s.b=(a*w.b+b*w.d)%m;
		s.c=(c*w.a+d*w.c)%m;
		s.d=(c*w.b+d*w.d)%m;
		a=s.a;b=s.b;c=s.c;d=s.d;
	}
}zy,nzy,ad[xx<<2],sum[xx<<2];
int f[xx],vis[xx<<2];
int ss[xx];
int lb(int x){return x&(-x);}
void adds(int x,int y){for(;x<=n;x+=lb(x))ss[x]+=y;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=ss[x];return ans;}
void build(int k,int l,int r)
{
	ad[k].set();
	if(l==r)return;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void add(int k,const matrix&w)
{
	ad[k]*w;
	sum[k]*w;
	vis[k]=1;
}
void pd(int k)
{
	if(!vis[k])return;
	add(k<<1,ad[k]);
	add(k<<1|1,ad[k]);
	ad[k].set();
	vis[k]=0;
}
void update(int k)
{
	sum[k].a=(sum[k<<1].a+sum[k<<1|1].a)%m;
	sum[k].b=(sum[k<<1].b+sum[k<<1|1].b)%m;
}
void change(int k,int l,int r,int a,int x,int y,int op)
{
	sum[k].a+=op*x+m;sum[k].b+=op*y+m;
	sum[k].a%=m;sum[k].b%=m;
	if(l==r)return;
	pd(k);
	int mid=l+r>>1;
	if(a<=mid)change(k<<1,l,mid,a,x,y,op);
	else change(k<<1|1,mid+1,r,a,x,y,op);
}
void change(int k,int l,int r,int x,int y,const matrix&a)
{
	if(x>y)return;
	if(x<=l&&r<=y)return add(k,a);
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x,y,a);
	if(mid<y)change(k<<1|1,mid+1,r,x,y,a);
	update(k);
}
int t[xx];
void add(int x)
{
	t[a[x]]++;
	if(t[a[x]]==1)
	{
//		cout<<a[x]<<"sss\n";
		adds(a[x],1);
		int s=ask(a[x]);
		change(1,1,n,a[x],f[s-1]*lsh[a[x]]%m,f[s]*lsh[a[x]]%m,1);
//		cout<<sum[1].a[1][1]<<" "<<sum[1].a[1][2]<<" "<<f[s]<<" "<<lsh[a[x]]<<"\n";
		change(1,1,n,a[x]+1,n,zy);
//		cout<<sum[1].a[1][1]<<" "<<sum[1].a[1][2]<<" "<<f[s]<<" "<<lsh[a[x]]<<"\n";
	}
}
void erase(int x)
{
	t[a[x]]--;
	if(t[a[x]]==0)
	{
//		cout<<a[x]<<"aaa\n";
		change(1,1,n,a[x]+1,n,nzy);
		int s=ask(a[x]);
		change(1,1,n,a[x],f[s-1]*lsh[a[x]]%m,f[s]*lsh[a[x]]%m,-1);
		adds(a[x],-1);
//		cout<<sum[1].a[1][1]<<" "<<sum[1].a[1][2]<<" "<<f[s]<<" "<<lsh[a[x]]<<"\n";
	}
}
int res[xx];
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	zy.b=zy.c=zy.d=1;
	n=read();m=read();
	nzy.b=nzy.c=1;nzy.a=m-1;
	f[1]=1;
	for(int i=1;i<=n;i++)a[i]=lsh[i]=read();
	for(int i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%m;
	sort(lsh+1,lsh+n+1);
	int sss=unique(lsh+1,lsh+n+1)-lsh-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(lsh+1,lsh+sss+1,a[i])-lsh;
	for(int i=1;i<=n;i++)lsh[i]%=m;
	int q=read();
	for(int i=1;i<=q;i++)
	{
		e[i].l=read();
		e[i].r=read();
		e[i].id=i;
	}
	B=sqrt(n);
	sort(e+1,e+q+1);
	int l=1,r=0;
	build(1,1,n);
//	return 0;
	for(int i=1;i<=q;i++)
	{
		while(r<e[i].r)add(++r);
		while(l>e[i].l)add(--l);
//		cout<<l<<" "<<r<<"\n";
		while(r>e[i].r)erase(r--);
		while(l<e[i].l)erase(l++);
		res[e[i].id]=sum[1].b;
	}
	for(int i=1;i<=q;i++)printnum(res[i],'\n');
	return pc('0',1);
}