#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma,popcnt")

#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>
 
#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L
 
#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll
 
#include <bitset>
 
#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl


#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <utility>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;

#define IO_FAST 1

const int BufSize=1<<21;
struct FastIO
{
	char ibuf[BufSize+10],*p,*e;
	char obuf[BufSize+10],*q,stk[128];

#if IO_FAST
	FastIO(){q=obuf;}
	~FastIO(){fwrite(obuf,1,q-obuf,stdout);}
 
	int getChar()
	{
		if(p==e)p=ibuf,e=ibuf+fread(ibuf,1,BufSize,stdin);
		return p==e?EOF:*p++;
	}
	void putChar(int c)
	{
		if(q-obuf==BufSize)fwrite(obuf,1,BufSize,stdout),q=obuf;
		*q++=c;
	}
#else
	int getChar(){return getchar();}
	void putChar(int c){putchar(c);}
#endif

	FastIO& operator>>(char& c)
	{
		do{c=getChar();}while(isspace(c));
		return *this;
	}
	FastIO& operator>>(char* s)
	{
		*s=' ';
		while(isspace(*s))*s=getChar();
		while(!isspace(*s))*++s=getChar();
		*s=0;
		return *this;
	}
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}

	FastIO& operator<<(char c)
	{
		putChar(c);
		return *this;
	}
	FastIO& operator<<(char* s)
	{
		while(*s)putChar(*s++);
		return *this;
	}
	FastIO& operator<<(const char* s)
	{
		while(*s)putChar(*s++);
		return *this;
	}
	template<typename T>
	FastIO& operator<<(T x)
	{
		int tp=0;
		if(x<0)x=-x,putChar('-');
		do{stk[++tp]=x%10,x/=10;}while(x);
		while(tp)putChar(stk[tp--]+'0');
		return *this;
	}
}IO;

const int MX=505,MY=660000;

bitset<MX> A[MX][MX],B[MX][MX];
int N,M,Qu;
char S[MX][MX];

int An[MY];
struct Query{int xi,yi,xj,yj,id;}Q[MY],tmpl[MY],tmpr[MY];

void Divide(int L,int R,int l,int r)
{
	if(L>R||l>r)return;
	int m=(l+r)>>1,lc=0,rc=0;
	
//	printf("\n---l=%d r=%d mid=%d---\nQ[]: ",l,r,m);
//	Fr(i,L,R)printf("%d ",Q[i].id);
//	putchar('\n');
	Fl(j,M,1)
	{
		if(S[m][j]=='.')A[m][j]=A[m][j+1],A[m][j][j]=1;
		else A[m][j].reset();
	}
	Fl(i,m-1,l)Fl(j,M,1)
	{
		if(S[i][j]=='.')A[i][j]=A[i+1][j]|A[i][j+1];
		else A[i][j].reset();
	}
	Fr(j,1,M)
	{
		if(S[m][j]=='.')B[m][j]=B[m][j-1],B[m][j][j]=1;
		else B[m][j].reset();
	}
	Fr(i,m+1,r)Fr(j,1,M)
	{
		if(S[i][j]=='.')B[i][j]=B[i-1][j]|B[i][j-1];
		else B[i][j].reset();
	}
	
	/*Fr(i,1,N)Fr(j,1,M)
	{
		printf("(%d,%d) ",i,j);
		Fr(k,1,M)putchar('0'+A[i][j][k]);
		putchar('\n');
	}*/
	Fr(i,L,R)
	{
		int xi=Q[i].xi,yi=Q[i].yi,xj=Q[i].xj,yj=Q[i].yj;
		if(xi<m&&xj<m){tmpl[++lc]=Q[i];continue;}
		if(xi>m&&xj>m){tmpr[++rc]=Q[i];continue;}
		An[Q[i].id]=(A[xi][yi]&B[xj][yj]).any();
	}
	Fr(i,1,lc)Q[L+i-1]=tmpl[i];
	Fr(i,1,rc)Q[L+lc+i-1]=tmpr[i];
	Divide(L,L+lc-1,l,m-1);
	Divide(L+lc,L+lc+rc-1,m+1,r);
}



int main()
{
	IO>>N>>M;
	Fr(i,1,N)IO>>(S[i]+1);
	IO>>Qu;
	Fr(i,1,Qu)IO>>Q[i].xi>>Q[i].yi>>Q[i].xj>>Q[i].yj,Q[i].id=i;
	
	Divide(1,Qu,1,N);
	Fr(i,1,Qu)IO<<(An[i]?"Yes":"No")<<'\n';
	return 0;
}