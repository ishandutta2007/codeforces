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

const int N=1000005;
char s1[N],s2[N];
int main()
{
	int _;
	read(_);
	while(_--)
	{
		int l1=read_str(s1+1);
		int l2=read_str(s2+1);
		s1[l1+1]='\0';
		s2[l2+1]='\0';
		int pos1=0,pos2=0;
		bool flag=0;
		while(pos1<l1)
		{
			if(s1[pos1+1]==s2[pos2+1])
			{
				++pos1,++pos2;
			}
			else
			{
				flag=1;
				break;
			}
			while(s2[pos2+1]!=s1[pos1+1]&&s2[pos2+1]==s1[pos1]&&pos2<l2)
			{
				++pos2;
			}
		}
		if(flag)
		{
			printf("NO\n");
			continue;
		}
		printf(pos2==l2?"YES\n":"NO\n");
	}
	return 0;
}
//