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

const int N=400005;
int pr[N],pos;
int rev[3000005];
bool b[3000005];
int a[N];
int ans[N];
int c[3000005];
int used[N];
Finline bool cmp(const int &a,const int &b){return a>b;}
int main()
{
	for(int i=2;i<=2750131;++i)
	{
		if(!b[i])
		{
			pr[++pos]=i;
			rev[i]=pos;
			for(int j=i<<1;j<=2750131;j+=i)
			{
				b[j]=1;
			}
		}
	}
	for(int i=2;i<=2750131;++i)
	{
		for(int j=i<<1;j<=2750131;j+=i)
		{
			c[j]=i;
		}
	}
	pos=0;
	int n;
	read(n);
	for(int i=1;i<=n<<1;++i) read(a[i]);
	std::sort(a+1,a+(n<<1)+1,cmp);
	for(int i=1;i<=(n<<1);++i)
	{
		if(!used[i])
		{
			if(!b[a[i]])
			{
				++used[i];
				int POS=std::lower_bound(a+1,a+(n<<1)+1,rev[a[i]],cmp)-a;
				++used[POS];
				ans[++pos]=a[POS];
			}
			else
			{
				++used[i];
				++used[std::lower_bound(a+1,a+(n<<1)+1,c[a[i]],cmp)-a];
				ans[++pos]=a[i];
			}
		}
		else if(used[i]>1)
		{
			used[i+1]+=used[i]-1;
		}
	}
	for(int i=1;i<=pos;++i) printf("%d ",ans[i]);
	printf("\n");
    return 0;
}
//5 4 3 3 2 2