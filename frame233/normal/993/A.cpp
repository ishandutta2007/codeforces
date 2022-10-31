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
	static uint seed=416;
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

const int N=100005;
int main()
{
	std::vector<int> v1,v2;
	int x,y;
	for(int t=0;t<4;++t)
	{
		read(x,y);
		v1.pb(x),v2.pb(y);
	}
	std::sort(v1.begin(),v1.end());
	std::sort(v2.begin(),v2.end());
	int x1=v1[0],y1=v2[0];
	int x2=v1.back(),y2=v2.back();
	
	v1.clear();
	v2.clear();
	for(int t=0;t<4;++t)
	{
		read(x,y);
		v1.pb(x),v2.pb(y);
	}
	std::sort(v1.begin(),v1.end());
	std::sort(v2.begin(),v2.end());
	int a1=v1[0];
	int a2=v1.back();
	
	std::vector<pi> v;
	for(int i=a1;i<=a2;++i)
	{
		int dis=min(i-a1,a2-i);
		for(int j=-dis;j<=dis;++j)
		{
			v.pb(mkpr(i,v2[1]+j));
		}
	}
	std::sort(v.begin(),v.end());
	for(int i=-100;i<=100;++i)
	{
		for(int j=-100;j<=100;++j)
		{
			if(i>=x1&&i<=x2&&j>=y1&&j<=y2&&*std::lower_bound(v.begin(),v.end(),mkpr(i,j))==mkpr(i,j))
			{
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}