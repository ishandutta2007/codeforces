// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
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
struct node{
	std::string s;
	Finline bool operator < (const node &o)const{return s.length()<o.s.length();}
};
std::priority_queue<node> q;
std::set<std::string> mp;
int main()
{
	int n,k;
	read(n,k);
	std::string s;
	std::cin>>s;
	q.push((node){s});
	int ans=0;
	while(!q.empty())
	{
		node x=q.top();
		q.pop();
		ans+=s.length()-x.s.length();
		--k;
		if(!k)
		{
			printf("%d\n",ans);
			return 0;
		}
		for(int i=0;i<(int)x.s.length();++i)
		{
			std::string tmp=x.s.substr(0,i)+x.s.substr(i+1,x.s.length()-i-1);
			if(mp.find(tmp)==mp.end())
			{
				mp.insert(tmp);
				q.push((node){tmp});
			}
		}
	}
	printf("-1\n");
	return 0;
}