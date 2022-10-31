// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=0x05ad13b4;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
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
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=1000005;
const int mod=1000000007;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
char s[N],t[N];
int dp[N+1];
int link[N+2],g[N+3],d[N+4];
int ch[N][26];
int len[N],fail[N];
int node_cnt,last;
Finline void init()
{
	node_cnt=last=1;
	len[0]=0,len[1]=-1;
	fail[0]=fail[1]=1;
}
int getfail(int cur,int n)
{
	while(s[n-len[cur]-1]!=s[n]) cur=fail[cur];
	return cur;
}
void insert(int x)
{
	int c=s[x]-97;
	int nd=getfail(last,x);
	if(!ch[nd][c])
	{
		int cur=++node_cnt;
		len[cur]=len[nd]+2;
		int tmp=getfail(fail[nd],x);
		fail[cur]=ch[tmp][c];
		d[cur]=len[cur]-len[fail[cur]];
		link[cur]=d[cur]==d[fail[cur]]?link[fail[cur]]:fail[cur];
		ch[nd][c]=cur;
	}
	last=ch[nd][c];
}
int main()
{
	init();
	int n=read_str(t+1);
	for(int i=1;i<=n>>1;++i)
	{
		s[(i<<1)-1]=t[i];
		s[i<<1]=t[n-i+1];
	}
	dp[0]=1;
	for(int i=1;i<=n;++i)
	{
		insert(i);
		for(int x=last;x>1;x=link[x])
		{
			g[x]=dp[i-len[link[x]]-d[x]];
			if(link[x]!=fail[x]) add(g[x],g[fail[x]]);
			if(!(i&1)) add(dp[i],g[x]);
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}