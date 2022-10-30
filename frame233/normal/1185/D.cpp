// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>

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

const int N=200005;
struct node{
	ll x;
	int id;
	Finline bool operator < (const node &o)const{return x<o.x;}
}a[N];
ll b[N];
std::map<ll,int> mp;
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i].x);
		a[i].id=i;
	}
	std::sort(a+1,a+n+1);
	for(int i=2;i<=n;++i)
	{
		b[i-1]=a[i].x-a[i-1].x;
		++mp[b[i-1]];
		if((int)mp.size()>3)
		{
			printf("-1\n");
			return 0;
		}
	}
	if(mp.size()==1)
	{
		printf("%d\n",a[1].id);
		return 0;
	}
	if(mp.size()==2)
	{
		if(mp[b[1]]==1)
		{
			printf("%d\n",a[1].id);
			return 0;
		}
		if(mp[b[n-1]]==1)
		{
			printf("%d\n",a[n].id);
			return 0;
		}
	}
	for(int i=2;i<n;++i)
	{
		if(!--mp[b[i-1]])
		{
			mp.erase(mp.find(b[i-1]));
		}
		if(!--mp[b[i]])
		{
			mp.erase(mp.find(b[i]));
		}
		++mp[b[i]+b[i-1]];
		if(mp.size()==1)
		{
			printf("%d\n",a[i].id);
			return 0;
		}
		++mp[b[i-1]];
		++mp[b[i]];
		if(!--mp[b[i]+b[i-1]])
		{
			mp.erase(mp.find(b[i]+b[i-1]));
		}
	}
	printf("-1\n");
	return 0;
}