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
 
const int N=100005;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
std::set<int> S1[N],S2[N];
int main()
{
	int n,m,k;
	read(n,m,k);
	int x,y;
	ll cnt=1;
	for(int i=1;i<=k;++i)
	{
		read(x,y);
		S1[x].insert(y);
		S2[y].insert(x);
		++cnt;
	}
	x=1,y=1;
	int dir=0;
	int maxn=n,minn=1;
	int maxm=m,minm=1;
	int tmp;
	int _cnt=0;
	while((!_cnt||(_cnt==1&&x==1&&y==1))&&minn<=maxn&&minm<=maxm)
	{
		if(!dir)
		{
			std::set<int>::iterator it=S1[x].lower_bound(y);
			if(it==S1[x].end()) tmp=m;
			else tmp=-1+*it;
			chmin(tmp,maxm);
			if(tmp<=y||y>maxm)
			{
				++_cnt;
				dir=dir==3?0:dir+1;
				continue;
			}
//			chmin(maxm,tmp-1);
			if(minn>maxn||minm>maxm)
			{
				++_cnt;
				dir=dir==3?0:dir+1;
				continue;
			}
			_cnt=0;
			cnt+=tmp-y;
			y=tmp;
			chmax(minn,x+1);
		}
		else if(dir==1)
		{
			std::set<int>::iterator it=S2[y].lower_bound(x);
			if(it==S2[y].end()) tmp=n;
			else tmp=-1+*it;
			chmin(tmp,maxn);
			if(tmp<=x||x>maxn)
			{
				++_cnt;
				dir=dir==3?0:dir+1;
				continue;
			}
//			chmin(maxn,tmp-1);
			if(minn>maxn||minm>maxm)
			{
				++_cnt;
				dir=dir==3?0:dir+1;
				continue;
			}
			cnt+=tmp-x;
			_cnt=0;
			x=tmp;
			chmin(maxm,y-1);
		}
		else if(dir==2)
		{
			std::set<int>::iterator it=S1[x].upper_bound(y);
			if(it==S1[x].begin()) tmp=1;
			else tmp=1+*--it;
			chmax(tmp,minm);
			if(y<=tmp||y<minm)
			{
				++_cnt;
				dir=dir==3?0:dir+1;
				continue;
			}
//			chmax(minm,tmp+1);
			if(minn>maxn||minm>maxm)
			{
				++_cnt;
				dir=dir==3?0:dir+1;
				continue;
			}
			cnt+=y-tmp;
			_cnt=0;
			y=tmp;
			chmin(maxn,x-1);
		}
		else
		{
			std::set<int>::iterator it=S2[y].upper_bound(x);
			if(it==S2[y].begin()) tmp=1;
			else tmp=1+*--it;
			chmax(tmp,minn);
			if(x<=tmp||x<minn)
			{
				++_cnt;
				dir=dir==3?0:dir+1;
				continue;
			}
//			chmax(minn,tmp+1);
			if(minn>maxn||minm>maxm)
			{
				++_cnt;
				dir=dir==3?0:dir+1;
				continue;
			}
			cnt+=x-tmp;
			_cnt=0;
			x=tmp;
			chmax(minm,y+1);
		}
		dir=dir==3?0:dir+1;
	}
	fprintf(stderr,"%lld\n",cnt);
	if(cnt==1ll*n*m)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
    return 0;
}