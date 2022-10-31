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
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
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

const int N=2000005;
char s[N],a[N];
int p[N];
std::vector<int> v1[N];
std::vector<int> v2[N];
Finline int getval1(int x,int val)
{
	return *(std::upper_bound(v1[x].begin(),v1[x].end(),val)-1);
}
Finline int getval2(int x,int val)
{
	return *(std::upper_bound(v2[x].begin(),v2[x].end(),val)-1);
}
void MAIN()
{
	int n=read_str(a+1);
	s[0]='!';
	s[1]='#';
	for(int i=1;i<=n;++i)
	{
		s[i<<1]=a[i];
		s[i<<1|1]='#';
		v1[i].clear();
		v2[i].clear();
		v1[i].push_back(0);
		v2[i].push_back(0);
	}
	int l=n<<1|1;
	s[l+1]='$';
	int maxx=0,mid=0;
	for(int i=1;i<=l;++i)
	{
		if(i<maxx) p[i]=min(maxx-i,p[(mid<<1)-i]);
		else p[i]=1;
		while(s[i+p[i]]==s[i-p[i]]) ++p[i];
		if(i+p[i]>maxx)
		{
			maxx=i+p[i];
			mid=i;
		}
		if(p[i]>1)
		{
			v1[((i-p[i])>>1)+1].push_back(p[i]-1);
			v2[((i+p[i])>>1)-1].push_back(p[i]-1);
		}
	}
	for(int i=1;i<=n;++i)
	{
		std::sort(v1[i].begin(),v1[i].end());
		v1[i].erase(std::unique(v1[i].begin(),v1[i].end()),v1[i].end());
		std::sort(v2[i].begin(),v2[i].end());
		v2[i].erase(std::unique(v2[i].begin(),v2[i].end()),v2[i].end());
	}
	int ans1=getval2(n,n);
	int pos1=0;
	for(int i=1;i<=n>>1;++i)
	{
		if(a[n-i+1]!=a[i]) break;
		int tmp=getval2(n-i,n-(i<<1))+(i<<1);
		if(tmp<=n&&tmp>ans1)
		{
			ans1=tmp,pos1=i;
		}
	}
	int ans2=getval1(1,n);
	int pos2=0;
	for(int i=1;i<=n>>1;++i)
	{
		if(a[n-i+1]!=a[i]) break;
		int tmp=getval1(i+1,n-(i<<1))+(i<<1);
		if(tmp<=n&&tmp>ans2)
		{
			ans2=tmp,pos2=i;
		}
	}
	if(ans1>ans2)
	{
		for(int i=1;i<=pos1;++i)
		{
			printf("%c",a[i]);
		}
		for(int i=n-(ans1-pos1)+1;i<=n;++i)
		{
			printf("%c",a[i]);
		}
		printf("\n");
	}
	else
	{
		for(int i=1;i<=ans2-pos2;++i)
		{
			printf("%c",a[i]);
		}
		for(int i=n-pos2+1;i<=n;++i)
		{
			printf("%c",a[i]);
		}
		printf("\n");
	}
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}