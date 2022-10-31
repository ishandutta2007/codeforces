// Author -- Frame
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<bitset>
 
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
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
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
 
const int N=55;
int a[N];
std::bitset<1250005> f[53][27];
bool used[N];
void print(int n,int rest,int x)
{
	if(n)
	{
		if(f[n-1][rest].test(x))
		{
			print(n-1,rest,x);
		}
		else
		{
			print(n-1,rest-1,x-a[n]);
			used[n]=1;
		}
	}
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n<<1;++i) read(a[i]);
	std::sort(a+1,a+(n<<1)+1);
	std::swap(a[1],a[n<<1]);
	std::swap(a[2],a[(n<<1)-1]);
	int len=(n<<1)-2;
	std::sort(a+1,a+len+1);
	int sum=0;
	f[0][0].set(0);
	for(int i=1;i<=len;++i)
	{
		sum+=a[i];
		for(int k=min(i,n-1);k>=1;--k)
		{
			f[i][k]=f[i-1][k]|(f[i-1][k-1]<<a[i]);
		}
		f[i][0].set(0);
	}
	int ans=inf;
	for(int i=sum>>1;i>=0;--i)
	{
		if(f[len][n-1].test(i))
		{
			ans=i;
			break;
		}
	}
	print(len,n-1,ans);
	std::vector<int> v1,v2;
	for(int i=1;i<=len;++i)
	{
		if(used[i])
		{
			v1.push_back(a[i]);
		}
		else
		{
			v2.push_back(a[i]);
		}
	}
	v1.push_back(a[n<<1]);
	v2.push_back(a[(n<<1)-1]);
	std::sort(v1.begin(),v1.end());
	std::sort(v2.begin(),v2.end());
	for(std::vector<int>::iterator it=v1.begin();it!=v1.end();++it)
	{
		printf("%d ",*it);
	}
	printf("\n");
	for(std::vector<int>::reverse_iterator it=v2.rbegin();it!=v2.rend();++it)
	{
		printf("%d ",*it);
	}
	printf("\n");
    return 0;
}