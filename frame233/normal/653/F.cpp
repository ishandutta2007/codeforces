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

const int N=1000005;
const int D=500000;
char s[N];
int last[N],P[N];
int F[N][20];
int dp[N];
struct SAM{
	struct Node{
		int fa,len;
		int ch[2];
	}f[N];
	int node_cnt,last;
	Finline SAM():node_cnt(1),last(1){}
	void insert(int c,int pos)
	{
		int cur=++node_cnt;
		f[cur].len=f[last].len+1;
		dp[cur]=pos;
		int p=last;
		while(p&&!f[p].ch[c])
		{
			f[p].ch[c]=cur;
			p=f[p].fa;
		}
		if(!p)
		{
			f[cur].fa=1;
		}
		else
		{
			int q=f[p].ch[c];
			if(f[q].len==f[p].len+1)
			{
				f[cur].fa=q;
			}
			else
			{
				int clone=++node_cnt;
				f[clone]=f[q];
				f[clone].len=f[p].len+1;
				f[cur].fa=f[q].fa=clone;
				while(p&&f[p].ch[c]==q)
				{
					f[p].ch[c]=clone;
					p=f[p].fa;
				}
			}
		}
		last=cur;
	}
	ll solve()
	{
		int maxx=0;
		for(int i=1;i<=node_cnt;++i) chmax(maxx,f[i].len);
		static int tax[N],A[N];
		memset(tax,0,4*(maxx+3));
		for(int i=1;i<=node_cnt;++i) ++tax[f[i].len];
		for(int i=1;i<=maxx;++i) tax[i]+=tax[i-1];
		for(int i=1;i<=node_cnt;++i) A[tax[f[i].len]--]=i;
		for(int i=node_cnt;i>1;--i)
		{
			chmax(dp[f[A[i]].fa],dp[A[i]]);
		}
		ll ans=0;
		for(int i=1;i<=node_cnt;++i)
		{
			int pos=dp[i];
			for(int j=19;j>=0;--j)
			{
				if(~F[pos][j]&&dp[i]-F[pos][j]<=f[i].len)
				{
					pos=F[pos][j];
					ans+=1<<j;
				}
			}
			pos=dp[i];
			for(int j=19;j>=0;--j)
			{
				if(~F[pos][j]&&dp[i]-F[pos][j]<=f[f[i].fa].len)
				{
					pos=F[pos][j];
					ans-=1<<j;
				}
			}
		}
		return ans;
	}
}sam;
int sum[N];
int main()
{
	int n;
	read(n);
	read_str(s+1);
	for(int i=1;i<=n;++i)
	{
		sam.insert(s[i]==')',i);
	}
	memset(P,255,sizeof(P));
	memset(last,255,sizeof(last));
	memset(F[0],255,sizeof(F[0]));
	P[D]=0;
	for(int i=1;i<=n;++i)
	{
		sum[i]=sum[i-1]+(s[i]=='('?1:-1);
		if(s[i]==')') last[i]=P[sum[i]+D];
		P[sum[i]+D]=i;
	}
	for(int i=1;i<=n;++i)
	{
		F[i][0]=last[i];
		for(int j=1;j<20;++j)
		{
			if(~F[i][j-1])
			{
				F[i][j]=F[F[i][j-1]][j-1];
			}
			else
			{
				F[i][j]=-1;
			}
		}
	}
	printf("%lld\n",sam.solve());
    return 0;
}