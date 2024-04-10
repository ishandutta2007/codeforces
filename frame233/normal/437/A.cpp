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

int main()
{
	std::string s1,s2,s3,s4;
	std::cin>>s1>>s2>>s3>>s4;
	s1=s1.substr(2,s1.length()-2);
	s2=s2.substr(2,s2.length()-2);
	s3=s3.substr(2,s3.length()-2);
	s4=s4.substr(2,s4.length()-2);
	std::cerr<<s1.length()<<" "<<s2.length()<<" "<<s3.length()<<" "<<s4.length()<<std::endl;
	char ans='E';
	if(s1.length()>=max(s2.length(),max(s3.length(),s4.length()))<<1||s1.length()<<1<=min(s2.length(),min(s3.length(),s4.length())))
	{
		if(ans!='E')
		{
			printf("C\n");
			return 0;
		}
		ans='A';
	}
	if(s2.length()>=max(s1.length(),max(s3.length(),s4.length()))<<1||s2.length()<<1<=min(s1.length(),min(s3.length(),s4.length())))
	{
		if(ans!='E')
		{
			printf("C\n");
			return 0;
		}
		ans='B';
	}
	if(s4.length()>=max(s1.length(),max(s2.length(),s3.length()))<<1||s4.length()<<1<=min(s1.length(),min(s2.length(),s3.length())))
	{
		if(ans!='E')
		{
			printf("C\n");
			return 0;
		}
		ans='D';
	}
	if(s3.length()>=max(s1.length(),max(s2.length(),s4.length()))<<1||s3.length()<<1<=min(s1.length(),min(s2.length(),s4.length())))
	{
		if(ans!='E')
		{
			printf("C\n");
			return 0;
		}
		ans='C';
	}
	printf("%c\n",ans=='E'?'C':ans);
    return 0;
}