// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=505;
char s[N][N];
int p[N][N];
int sumR[N][N];
int sumG[N][N];
int sumY[N][N];
int sumB[N][N];
Finline int QueryR(int x1,int y1,int x2,int y2)
{
	return sumR[x2][y2]-sumR[x1-1][y2]-sumR[x2][y1-1]+sumR[x1-1][y1-1];
}
Finline int QueryG(int x1,int y1,int x2,int y2)
{
	return sumG[x2][y2]-sumG[x1-1][y2]-sumG[x2][y1-1]+sumG[x1-1][y1-1];
}
Finline int QueryY(int x1,int y1,int x2,int y2)
{
	return sumY[x2][y2]-sumY[x1-1][y2]-sumY[x2][y1-1]+sumY[x1-1][y1-1];
}
Finline int QueryB(int x1,int y1,int x2,int y2)
{
	return sumB[x2][y2]-sumB[x1-1][y2]-sumB[x2][y1-1]+sumB[x1-1][y1-1];
}
Finline bool check(int x,int y,int k)
{
	return  QueryR(x-k+1,y-k+1,x,y)==k*k&&
			QueryG(x-k+1,y+1,x,y+k)==k*k&&
			QueryY(x+1,y-k+1,x+k,y)==k*k&&
			QueryB(x+1,y+1,x+k,y+k)==k*k;
}
int m1[N][N][10];
int m2[N][N][10];
int Log[N];
Finline int Query1(int x,int y1,int y2)
{
	if(y1>y2) return -inf;
	int k=Log[y2-y1+1];
	return max(m1[x][y1][k],m1[x][y2-(1<<k)+1][k]);
}
Finline int Query2(int x1,int x2,int y)
{
	if(x1>x2) return -inf;
	int k=Log[x2-x1+1];
	return max(m2[x1][y][k],m2[x2-(1<<k)+1][y][k]);
}
int main()
{
	for(int i=2;i<=500;++i) Log[i]=Log[i>>1]+1;
	int n,m,q;
	read(n,m,q);
	for(int i=1;i<=n;++i)
	{
		read_str(s[i]+1);
		for(int j=1;j<=m;++j)
		{
			sumR[i][j]=sumR[i-1][j]+sumR[i][j-1]-sumR[i-1][j-1];
			sumG[i][j]=sumG[i-1][j]+sumG[i][j-1]-sumG[i-1][j-1];
			sumY[i][j]=sumY[i-1][j]+sumY[i][j-1]-sumY[i-1][j-1];
			sumB[i][j]=sumB[i-1][j]+sumB[i][j-1]-sumB[i-1][j-1];
			if(s[i][j]=='R') ++sumR[i][j];
			else if(s[i][j]=='G') ++sumG[i][j];
			else if(s[i][j]=='Y') ++sumY[i][j];
			else ++sumB[i][j];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]=='R')
			{
				int l=0,r=min(min(i,n-i),min(j,m-j));
				while(l<r)
				{
					int mid=(l+r+1)>>1;
					if(check(i,j,mid)) l=mid;
					else r=mid-1;
				}
				p[i][j]=l;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=m;j>=1;--j)
		{
			m1[i][j][0]=p[i][j];
			for(int k=1;k<=9&&j+(1<<(k-1))<=m;++k)
			{
				m1[i][j][k]=max(m1[i][j][k-1],m1[i][j+(1<<(k-1))][k-1]);
			}
		}
	}
	for(int i=n;i>=1;--i)
	{
		for(int j=1;j<=m;++j)
		{
			m2[i][j][0]=p[i][j];
			for(int k=1;k<=9&&i+(1<<(k-1))<=n;++k)
			{
				m2[i][j][k]=max(m2[i][j][k-1],m2[i+(1<<(k-1))][j][k-1]);
			}
		}
	}
	int x1,y1,x2,y2;
	while(q--)
	{
		read(x1,y1,x2,y2);
		int size=(min(y2-y1,x2-x1)+1)>>1;
		--x2,--y2;
		int ans=0;
		for(int i=1;i<=size;++i)
		{
			int res=0;
			chmax(res,Query1(x1+i-1,y1+i-1,y2-i+1));
			chmax(res,Query1(x2-i+1,y1+i-1,y2-i+1));
			chmax(res,Query2(x1+i-1,x2-i+1,y1+i-1));
			chmax(res,Query2(x1+i-1,x2-i+1,y2-i+1));
			chmin(res,i);
			chmax(ans,res);
		}
		printf("%d\n",ans*ans*4);
	}
	return 0;
}