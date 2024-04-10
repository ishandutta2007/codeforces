#include<random>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<climits>
//#define NDEBUG
#include<cassert>
#include<cstring>
#include<complex>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<bitset>
//#define LL __int128
#define LL long long
#define ULL unsigned LL
#define uint unsigned int
//#define int LL
//#define double long double
#define mkp make_pair
#define par pair<int,int>
#define psb push_back
#define epb emplace_back
#define f(x) ((x).first)
#define s(x) ((x).second)
using namespace std;
#define Lbt(x) ((x)&(-(x)))
#define Swap(x,y) (x^=y^=x^=y)
const int Mxxx=1e5;
inline char gc()
{
//	return getchar();
	static char buf[Mxxx],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxxx,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool fl=false)
{
//	return fl?0:putchar(ch),0;
	static char buf[Mxxx],*p1=buf,*p2=buf+Mxxx;
	return (fl||((*p1++=ch)&&p1==p2))&&(fwrite(buf,1,p1-buf,stdout),p1=buf),0;
}
#define output pc('!',true)
inline int read()
{
	char ch=gc();
	int gans=0,gflag=0;
	for(;ch<'0'||'9'<ch;gflag|=ch=='-',ch=gc());
	for(;'0'<=ch&&ch<='9';gans=(gans<<1)+(gans<<3)+(ch^48),ch=gc());
	return gflag?-gans:gans;
}
template<typename T>
inline char read(T&gans)
{
	char ch=gc();
	int gflag=0;gans=0;
	for(;ch<'0'||'9'<ch;gflag|=ch=='-',ch=gc());
	for(;'0'<=ch&&ch<='9';gans=(gans<<1)+(gans<<3)+(ch^48),ch=gc());
	return gans=gflag?-gans:gans,ch;
}
template<typename T>
inline void write(T x)
{
	if(x>9)write(x/10);
	pc(x%10^48);
}
template<typename T>
inline void writenum(T x,char ch)
{
	if(x<0)pc('-'),x=-x;
	write(x);pc(ch);
}
inline void writechar(char x,char ch)
{
	pc(x);pc(ch);
}
template<typename T>
inline T Max(T x,T y)
{
	return x>y?x:y;
}
template<typename T>
inline T Min(T x,T y)
{
	return x<y?x:y;
}
template<typename T>
inline T Abs(T x)
{
	return x<0?-x:x;
}
template<typename T>
inline void ckmx(T&x,T y)
{
	x=Max(x,y);
}
template<typename T>
inline void ckmn(T&x,T y)
{
	x=Min(x,y);
}
const int Mx=200;int n,cst[Mx+5][Mx+5],vst[Mx+5][Mx+5];LL S[Mx+5][Mx+5],F[Mx+5][Mx+5];int G[Mx+5][Mx+5];
inline LL Calc(int a,int b,int c,int d)
{
	if(a>c||b>d)return 0;
	return S[c][d]-S[a-1][d]-S[c][b-1]+S[a-1][b-1];
}
inline LL Calc(int l,int r)
{
	return Calc(l,r+1,r,n)+Calc(l,1,r,l-1);
}
inline LL Slv(int l,int r)
{
	if(l>r)return 0;
	if(vst[l][r])return F[l][r];
	int i;pair<LL,int>mn(LLONG_MAX,0);vst[l][r]=1;
	for(i=l;i<=r;i++)
	{
		ckmn(mn,mkp(Slv(l,i-1)+Slv(i+1,r)+(l<i?Calc(l,i-1):0)+(i<r?Calc(i+1,r):0),i));
	}
	return G[l][r]=s(mn),F[l][r]=f(mn);
}
int ans[Mx+5];
inline void Div(int l,int r,int f=0)
{
	if(l>r)return;
	assert(vst[l][r]);
	int p=G[l][r];
	ans[p]=f;
	Div(l,p-1,p);Div(p+1,r,p);
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	#endif
	int i,j;n=read();
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)cst[i][j]=read(),S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+cst[i][j];
//	writenum(Slv(1,n),10);
//	cerr<<
	Slv(1,n)
//	<<"\n"
	;
	Div(1,n);
	for(i=1;i<=n;i++)writenum(ans[i],i==n?10:32);
	return output;
}
/*
4
0 566 1 0
566 0 239 30
1 239 0 1
0 30 1 0
*/