// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t,Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=105;
double f[N][N][N];
int main()
{
	int r,s,p;
	read(r,s,p);
	f[r][s][p]=1;
	for(int i=r;i>=0;--i)
	{
		for(int j=s;j>=0;--j)
		{
			for(int k=p;k>=0;--k)
			{
				int cnt=(!!i)+(!!j)+(!!k);
				if(cnt<2) continue;
				if(cnt==3)
				{
					f[i-1][j][k]+=f[i][j][k]*(double)(i*k)/(double)(i*j+i*k+j*k);
					f[i][j-1][k]+=f[i][j][k]*(double)(i*j)/(double)(i*j+i*k+j*k);
					f[i][j][k-1]+=f[i][j][k]*(double)(j*k)/(double)(i*j+i*k+j*k);
				}
				else
				{
					if(!i)
					{
						f[i][j][k-1]+=f[i][j][k];
					}
					else if(!j)
					{
						f[i-1][j][k]+=f[i][j][k];
					}
					else
					{
						f[i][j-1][k]+=f[i][j][k];
					}
				}
			}
		}
	}
	double ans1=0,ans2=0,ans3=0;
	for(int i=0;i<=100;++i)
	{
		ans1+=f[i][0][0];
		ans2+=f[0][i][0];
		ans3+=f[0][0][i];
	}
	printf("%.12lf %.12lf %.12lf\n",ans1,ans2,ans3);
	return 0;
}