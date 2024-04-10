// luogu-judger-enable-o2
// Author -- Frame
 
#pragma GCC optimize(2)
 
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
 
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::sort;
using std::unique;
using std::endl;
using std::cerr;
using std::random_shuffle;
 
typedef long long ll;
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
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
int a[105];
void MAIN()
{
	int n,m,k;
	read(n,m,k);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	ll rest=m;
	for(int i=1;i<n;++i)
	{
		if(a[i]-a[i+1]>=-k)
		{
			int tmp=a[i];
			a[i]=max(0,a[i+1]-k);
			rest+=tmp-a[i];
		}
		else
		{
			int tmp=a[i];
			a[i]=a[i+1]-k;
			rest-=(a[i]-tmp);
			if(rest<0)
			{
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n");
}
int main()
{
	
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}