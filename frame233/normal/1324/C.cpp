// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

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
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
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

const int N=200005;
char s[N];
int n;
std::set<int> S;
bool vis[N];
int _q[N],_l,_r;
bool check(int d)
{
	S.clear();
	vis[0]=true;
	memset(vis,0,n+3);
	for(int i=1;i<=n+1;++i) S.insert(i);
	_q[_l=_r=1]=0;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		if(x==n+1) return true;
		if(s[x]=='R')
		{
			auto pos=S.upper_bound(x+d);
			auto cur=S.lower_bound(x);
			for(auto it=cur;it!=pos;++it)
			{
				vis[*it]=true;
				_q[++_r]=*it;
			}
			S.erase(cur,pos);
		}
		else
		{
			auto pos=S.lower_bound(x-d);
			auto cur=S.upper_bound(x);
			for(auto it=pos;it!=cur;++it)
			{
				vis[*it]=true;
				_q[++_r]=*it;
			}
			S.erase(pos,cur);
		}
	}
	return false;
}
void MAIN()
{
	n=read_str(s+1);
	s[0]='R';
	int l=1,r=n+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}