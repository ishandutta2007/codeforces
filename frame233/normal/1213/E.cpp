// luogu-judger-enable-o2
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
const double eps=1e-8;
 
uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
 
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
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
 
const int N=100005;
std::string s,t;
int n,n3;
void print(const std::string &S)
{
	for(int i=1;i<=n;++i)
	{
		printf("%s",S.c_str());
	}
}
bool check1()
{
	return s!="ab"&&s!="bc"&&s!="ba"&&t!="ab"&&t!="bc"&&t!="ba";
}
void print1()
{
	print("ab");
	print("c");
	exit(0);
}
bool check2()
{
	return s!="ac"&&s!="cb"&&s!="ca"&&t!="ac"&&t!="cb"&&t!="ca";
}
void print2()
{
	print("ac");
	print("b");
	exit(0);
}
 
bool check3()
{
	return s!="ba"&&s!="ac"&&s!="ab"&&t!="ba"&&t!="ac"&&t!="ab";
}
void print3()
{
	print("ba");
	print("c");
	exit(0);
}
bool check4()
{
	return s!="bc"&&s!="cb"&&s!="ca"&&t!="bc"&&t!="cb"&&t!="ca";
}
void print4()
{
	print("bc");
	print("a");
	exit(0);
}
bool check5()
{
	return s!="ca"&&s!="ac"&&s!="ab"&&t!="ca"&&t!="ac"&&t!="ab";
}
void print5()
{
	print("ca");
	print("b");
	exit(0);
}
bool check6()
{
	return s!="cb"&&s!="bc"&&s!="ba"&&t!="cb"&&t!="bc"&&t!="ba";
}
void print6()
{
	print("cb");
	print("a");
	exit(0);
}
bool check7()
{
	return s!="ab"&&s!="bc"&&t!="ab"&&t!="bc";
}
void print7()
{
	print("a");
	print("b");
	print("c");
	exit(0);
}
bool check8()
{
	return s!="ac"&&s!="cb"&&t!="ac"&&t!="cb";
}
void print8()
{
	print("a");
	print("c");
	print("b");
	exit(0);
}
bool check9()
{
	return s!="ba"&&s!="ac"&&t!="ba"&&t!="ac";
}
void print9()
{
	print("b");
	print("a");
	print("c");
	exit(0);
}
bool check10()
{
	return s!="bc"&&s!="ca"&&t!="bc"&&t!="ca";
}
void print10()
{
	print("b");
	print("c");
	print("a");
	exit(0);
}
bool check11()
{
	return s!="ca"&&s!="ab"&&t!="ca"&&t!="ab";
}
void print11()
{
	print("c");
	print("a");
	print("b");
	exit(0);
}
bool check12()
{
	return s!="cb"&&s!="ba"&&t!="cb"&&t!="ba";
}
void print12()
{
	print("c");
	print("b");
	print("a");
	exit(0);
}
bool check13()
{
	return s!="ab"&&s!="bc"&&s!="ca"&&t!="ab"&&t!="bc"&&t!="ca";
}
void print13()
{
	print("abc");
	exit(0);
}
bool check14()
{
	return s!="ac"&&s!="cb"&&s!="ba"&&t!="ac"&&t!="cb"&&t!="ba";
}
void print14()
{
	print("acb");
	exit(0);
}
bool check15()
{
	return s!="ba"&&s!="ac"&&s!="cb"&&t!="ba"&&t!="ac"&&t!="cb";
}
void print15()
{
	print("bac");
	exit(0);
}
bool check16()
{
	return s!="bc"&&s!="ca"&&s!="ab"&&t!="bc"&&t!="ca"&&t!="ab";
}
void print16()
{
	print("bca");
	exit(0);
}
bool check17()
{
	return s!="ca"&&s!="ab"&&s!="bc"&&t!="ca"&&t!="ab"&&t!="bc";
}
void print17()
{
	print("cab");
	exit(0);
}
bool check18()
{
	return s!="cb"&&s!="ba"&&s!="ac"&&t!="cb"&&t!="ba"&&t!="ac";
}
void print18()
{
	print("cba");
	exit(0);
}
int main()
{
	read(n);
	n3=n*3;
	std::cin>>s>>t;
	printf("YES\n");
	if(s[0]!=s[1]&&t[0]!=t[1])
	{
		if(check1()) print1();
		if(check2()) print2();
		if(check3()) print3();
		if(check4()) print4();
		if(check5()) print5();
		if(check6()) print6();
		if(check7()) print7();
		if(check8()) print8();
		if(check9()) print9();
		if(check10()) print10();
		if(check11()) print11();
		if(check12()) print12();
	}
	if(check13()) print13();
	if(check14()) print14();
	if(check15()) print15();
	if(check16()) print16();
	if(check17()) print17();
	if(check18()) print18();
	exit(233);
    return 0;
}