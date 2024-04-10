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
int k;
struct edge{
	int v,nxt,w;
}c[N<<1];
int front[N],_cnt;
Finline void add(const int &u,const int &v,const int &w)
{
	c[++_cnt]=(edge){v,front[u],w},front[u]=_cnt;
}
int max_len;
bool used[N];
bool flag,qwq;
int n;
int cnt;
int dfs(int x,int fa)
{
	if(flag) return 0;
	int tmp,cur=0;
	int _=0;
	for(int i=front[x];i&&!flag;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			tmp=dfs(c[i].v,x);
			if(c[i].w>max_len)
			{
				if(!used[c[i].v])
				{
					used[c[i].v]=1;
					++cnt;
				}
				if(!used[x])
				{
					used[x]=1;
					++cnt;
				}
			}
			else
			{
				if(tmp+c[i].w>max_len)
				{
					if(cnt<k&&!used[c[i].v])
					{
						used[c[i].v]=1;
						++cnt;
					}
				}
			}
			_+=used[c[i].v];
			chmax(cur,tmp+c[i].w);
		}
	}
	if(flag)
	{
		return 0;
	}
	if(_>2)
	{
		qwq=1;
		flag=1;
		return 0;
	}
	if(_==2)
	{
		if(!used[x])
		{
			used[x]=1;
			++cnt;
		}
		flag=1;
		return 0;
	}
	if(_==1)
	{
		if(cnt<k&&!used[x])
		{
			++cnt;
			used[x]=1;
		}
	}
	return cur;
}
int Dfs(int x,int fa)
{
	int ans=0;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			chmax(ans,Dfs(c[i].v,x)+c[i].w);
		}
	}
	return ans;
}
bool check(int x)
{
	memset(used,0,sizeof(used));
	max_len=x;
	flag=0;
	qwq=0;
	cnt=0;
	dfs(1,0);
	if(qwq) return 0;
	if(cnt>k) return 0;
	int qaq=0,qwqwq=0;
	for(int i=1;i<=n;++i)
	{
		if(used[i])
		{
			int tmp=0;
			for(int _=front[i];_;_=c[_].nxt)
			{
				if(used[c[_].v])
				{
					++tmp;
				}
			}
			qaq+=tmp==1;
			qwqwq+=tmp==2;
		}
	}
	if(qaq>2) return 0;
	if(qaq+qwqwq!=cnt&&cnt>1) return 0;
	int maxx=0;
	for(int i=1;i<=n;++i)
	{
		if(used[i])
		{
			for(int _=front[i];_;_=c[_].nxt)
			{
				if(!used[c[_].v])
				{
					chmax(maxx,Dfs(c[_].v,i)+c[_].w);
				}
			}
		}
	}
	return maxx<=x&&cnt<=k;
}
int main()
{
	read(n,k);
	int x,y,z;
	for(int i=1;i<n;++i)
	{
		read(x,y,z);
		add(x,y,z),add(y,x,z);
	}
	int l=0,r=1e9;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
    return 0;
}