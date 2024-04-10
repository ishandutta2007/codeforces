// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

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

const int N=505;
int a[N];
std::vector<int> v1,v2;
std::vector<std::pair<int,int> > ans;
int main()
{
	int n;
	read(n);
	int cnt=-1;
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		--a[i];
		if(a[i])
		{
			++cnt;
			v2.push_back(i);
		}
		else
		{
			v1.push_back(i);
		}
	}
	if(!~cnt)
	{
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<(int)v2.size();++i)
	{
		ans.push_back(std::make_pair(v2[i-1],v2[i]));
	}
	for(auto it:v2)
	{
		--a[it];
	}
	int fst=v2[0],lst=*--v2.end();
	if((int)v1.size()>=1)
	{
		ans.push_back(std::make_pair(fst,*v1.begin()));
		++cnt;
	}
	if((int)v1.size()>=2)
	{
		ans.push_back(std::make_pair(lst,*++v1.begin()));
		++cnt;
	}
	int pos=0;
	for(int i=2;i<(int)v1.size();++i)
	{
		while(pos<(int)v2.size()&&!a[v2[pos]]) ++pos;
		if(pos==(int)v2.size())
		{
			printf("NO\n");
			return 0;
		}
		--a[v2[pos]];
		ans.push_back(std::make_pair(v2[pos],v1[i]));
	}
	printf("YES %d\n%d\n",cnt,ans.size());
	for(auto it:ans)
	{
		printf("%d %d\n",it.first,it.second);
	}
	return 0;
}