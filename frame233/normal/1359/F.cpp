// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=0x05ad13b4;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
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
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=25005;
const double eps=1e-8;
Finline int dcmp(const double &a)
{
	return a>eps?1:a<-eps?-1:0;
}
int x[N],y[N],dx[N],dy[N],s[N];
double k[N],b[N];
double v[N];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(x[i],y[i],dx[i],dy[i],s[i]);
		int g=gcd(abs(dx[i]),abs(dy[i]));
		dx[i]/=g,dy[i]/=g;
		k[i]=(double)dy[i]/dx[i];
		b[i]=y[i]-k[i]*x[i];
		v[i]=abs((double)s[i]*((double)dx[i]/sqrt(dx[i]*dx[i]+dy[i]*dy[i])));
	}
	double ans=1e18;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(dcmp(k[i]-k[j])==0)
			{
				if(dcmp(b[i]-b[j])!=0) continue;
				if(dx[i]==dx[j])
				{
					if(dx[i]>0)
					{
						if(x[j]>x[i])
						{
							chmin(ans,(x[j]-x[i])/v[i]);
						}
						else
						{
							chmin(ans,(x[i]-x[j])/v[j]);
						}
					}
					else
					{
						if(x[j]>x[i])
						{
							chmin(ans,(x[j]-x[i])/v[j]);
						}
						else
						{
							chmin(ans,(x[i]-x[j])/v[i]);
						}
					}
				}
				else
				{
					if((x[i]<x[j]&&dx[i]>0)||(x[i]>x[j]&&dx[i]<0))
					{
						chmin(ans,abs(x[i]-x[j])/(v[i]+v[j]));
					}
				}
			}
			else
			{
				double X=(b[i]-b[j])/(k[j]-k[i]);
				if(dcmp(X-x[i])==1&&dx[i]<0) continue;
				if(dcmp(X-x[i])==-1&&dx[i]>0) continue;
				if(dcmp(X-x[j])==1&&dx[j]<0) continue;
				if(dcmp(X-x[j])==-1&&dx[j]>0) continue;
				chmin(ans,max(abs(X-x[i])/v[i],abs(X-x[j])/v[j]));
			}
		}
	}
	if(ans>1e17) printf("No show :(\n");
	else printf("%.12lf\n",ans);
	return 0;
}