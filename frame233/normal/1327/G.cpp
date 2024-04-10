// Author -- Frame

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

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

const int N=1005;
std::vector<int> v[1<<14],_v[15];
struct ACAM{
	int ch[N][14];
	int fail[N];
	ll val[N],c[N];
	int node_cnt;
	int _q[N],_l,_r;
	void insert(char *s,int len,int qwq)
	{
		int tmp,cur=0;
		for(int i=1;i<=len;++i)
		{
			tmp=s[i]-97;
			if(!ch[cur][tmp]) ch[cur][tmp]=++node_cnt;
			cur=ch[cur][tmp];
		}
		c[cur]+=qwq;
	}
	void build()
	{
		_l=1,_r=0;
		for(int i=0;i<14;++i)
		{
			if(ch[0][i])
			{
				_q[++_r]=ch[0][i];
			}
		}
		while(_l!=_r+1)
		{
			int x=_q[_l++];
			for(int i=0;i<14;++i)
			{
				if(ch[x][i])
				{
					fail[ch[x][i]]=ch[fail[x]][i];
					_q[++_r]=ch[x][i];
				}
				else
				{
					ch[x][i]=ch[fail[x]][i];
				}
			}
		}
		for(int i=1;i<=node_cnt;++i)
		{
			for(int cur=i;cur;cur=fail[cur])
			{
				val[i]+=c[cur];
			}
		}
	}
	std::pair<int,ll> walk(int cur,char *s,int k)
	{
		ll ans=0;
		for(register int i=0;i<k;++i)
		{
			cur=ch[cur][s[i]-97];
			ans+=val[cur];
		}
		return std::make_pair(cur,ans);
	}
	ll f[1005][1<<14],g[1005][1<<14];
	ll dp(char *s,int len)
	{
		memset(f,-63,sizeof(f));
		memset(g,-63,sizeof(g));
		int pos=0;
		while(pos<len&&s[pos+1]!='?') ++pos;
		std::pair<int,ll> tmp=walk(0,s+1,pos);
		g[tmp.first][0]=tmp.second;
		int cnt=0;
		for(int i=pos+1;i<=len;++i)
		{
			memset(f,-63,sizeof(f));
			for(register int j=0;j<=node_cnt;++j)
			{
				for(auto st:_v[cnt])
				{
					for(int k:v[st])
					{
						chmax(f[ch[j][k]][st|(1<<k)],g[j][st]+val[ch[j][k]]);
					}
				}
			}
			++cnt;
			memset(g,-63,sizeof(g));
			pos=i;
			while(pos<len&&s[pos+1]!='?') ++pos;
			for(int j=0;j<=node_cnt;++j)
			{
				tmp=walk(j,s+i+1,pos-i);
				for(auto st:_v[cnt])
				{
					chmax(g[tmp.first][st],f[j][st]+tmp.second);
				}
			}
			i=pos;
		}
		ll ans=-INF;
		for(int i=0;i<=node_cnt;++i)
		{
			for(int st=0;st<1<<14;++st)
			{
				chmax(ans,g[i][st]);
			}
		}
		return ans;
	}
}tr;
char s[400005];
int main()
{
	for(int i=0;i<1<<14;++i)
	{
		for(int j=0;j<14;++j)
		{
			if(!((i>>j)&1))
			{
				v[i].push_back(j);
			}
		}
		_v[__builtin_popcount(i)].push_back(i);
	}
	int k;
	read(k);
	int x;
	for(int i=1;i<=k;++i)
	{
		int len=read_str(s+1);
		read(x);
		tr.insert(s,len,x);
	}
	tr.build();
	int len=read_str(s+1);
	printf("%lld\n",tr.dp(s,len));
	return 0;
}