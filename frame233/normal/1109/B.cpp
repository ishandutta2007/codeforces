// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

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
template <typename _Tp,typename... Args>Finline void read(_Tp& t, Args&... args)
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

const int N=100005;
int cnt[27];
bool check(const std::string &ss)
{
	for(int i=0;i<=(int)ss.length()>>1;++i)
	{
		if(ss[i]!=ss[ss.length()-i-1])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	std::string s;
	std::cin>>s;
	int n=s.length();
	std::string ss;
	for(int i=1;i<n;++i)
	{
		ss=s.substr(i,n-i)+s.substr(0,i);
		if(s!=ss&&check(ss))
		{
			printf("1\n");
			return 0;
		}
	}
	for(int i=1;i<=(int)s.length()>>1;++i)
	{
		ss=s.substr(n-i,i)+s.substr(i,n-(i<<1))+s.substr(0,i);
		if(s!=ss&&check(ss))
		{
			printf("2\n");
			return 0;
		}
	}
	printf("Impossible\n");
	return 0;
}