#include <cstdio>
#include <cstring>
#include <algorithm>
#define MN 105
#define MM 1000005
#define mod 1000000007
using namespace std;
struct matr
{
	int ar[MN][MN],h,l;
	friend matr operator*(const matr& a,const matr& b)
	{
		matr c;
		register int i,j,k;
		c.h=a.h; c.l=b.l;
		for (i=0;i<c.h;++i)
			for (j=0;j<c.l;++j)
				for (c.ar[i][j]=k=0;k<a.l;++k)
					c.ar[i][j]=(1LL*a.ar[i][k]*b.ar[k][j]+c.ar[i][j])%mod;
		return c;
	}
}st,mov,one;
int n,m,p,ans;
int a[MM],b[MM],c[MM];

inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}

matr mi(matr a,int y)
{
	matr z=one;
	for (;y;y>>=1,a=a*a) if (y&1) z=z*a;
	return z;
}

int main()
{
	register int i,j,lt;
	n=read(); m=read(); p=read();
	for (i=0;i<p;++i) one.ar[i][i]=1;
	for (i=1;i<=n;++i) a[i]=read()%p;
	for (i=1;i<=n;++i) b[i]=read()%p;
	for (i=1;i<=n;++i) c[i]=read()%p;
	for (i=1;i<=n;++i) ++mov.ar[(p-b[i])%p][0],++st.ar[0][a[i]];
//	for (i=0;i<p;++i) printf("%d ",st.ar[0][i]); puts("");	
	for (i=1;i<p;++i)
		for (mov.ar[0][i]=mov.ar[p-1][i-1],j=1;j<p;++j) mov.ar[j][i]=mov.ar[j-1][i-1];
	mov.h=mov.l=one.h=one.l=p; st.h=1; st.l=p;
	mov=mi(mov,m-2);
	st=st*mov;
	for (i=1;i<=n;++i)
	{
		lt=(b[i]+c[i])%p; lt=(p-lt)%p;
		ans+=st.ar[0][lt];
		if (ans>=mod) ans-=mod;
	}
	printf("%d",ans);
}