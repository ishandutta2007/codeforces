// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>

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

const int N=100005;
int a[N],b[N];
struct node{
	int x,num;
	Finline bool operator < (const node &o)const{return x<o.x;}
};
std::multiset<node> s;
std::set<int> S;
int main()
{
	int n,m;
	read(n,m);
	ll ans=0;
	s.insert((node){-inf,inf});
	s.insert((node){inf,inf});
	int maxx=0;
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		chmax(maxx,a[i]);
		ans+=a[i];
		s.insert((node){a[i],m-1});
		S.insert(a[i]);
	}
	ans*=m;
	for(int i=1;i<=m;++i)
	{
		read(b[i]);
		if(b[i]<maxx)
		{
			printf("-1\n");
			return 0;
		}
		if(S.find(b[i])!=S.end())
		{
			continue;
		}
		std::multiset<node>::iterator it=--s.upper_bound((node){b[i],0});
		if(it==s.begin())
		{
			printf("-1\n");
			return 0;
		}
		ans+=(b[i]-it->x);
		if(it->num>1)
		{
			node tmp=*it;
			--tmp.num;
			s.erase(it);
			s.insert(tmp);
		}
		else
		{
			s.erase(it);
		}
	}
	printf("%lld\n",ans);
    return 0;
}