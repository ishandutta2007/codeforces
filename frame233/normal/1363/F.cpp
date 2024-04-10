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

const int N=2005;
char s[N],t[N];
int dp[N][N];
int s1[N][26],s2[N][26],pre[N][26],last[26];
void MAIN()
{
	int n;
	read(n);
	memset(s,0,sizeof(s));
	memset(t,0,sizeof(t));
	memset(s1,0,104*(n+3));
	memset(s2,0,104*(n+3));
	memset(pre,255,104*(n+3));
	read_str(s+1),read_str(t+1);
	memset(last,255,sizeof(last));
	for(int i=1;i<=n;++i)
	{
		last[s[i]-97]=i;
		memcpy(pre[i],last,104);
	}
	for(int i=n;i>=0;--i)
	{
		for(int j=0;j<26;++j)
		{
			s1[i][j]=s1[i+1][j]+(s[i]==j+97);
			s2[i][j]=s2[i+1][j]+(t[i]==j+97);
		}
	}
	for(int i=0;i<=n+1;++i)
	{
		for(int j=0;j<=n+1;++j)
		{
			dp[i][j]=inf;
		}
	}
	dp[n][n]=0;
	for(int i=n;i>=0;--i)
	{
		for(int j=n;j>=1;--j)
		{
			int qwq=t[j]-97;
			if(s1[i+1][qwq]-s2[j+1][qwq]>0) chmin(dp[i][j-1],dp[i][j]);
			int pos=pre[i][qwq];
			if(~pos) chmin(dp[pos-1][j-1],dp[i][j]+i-pos);
		}
	}
	printf("%d\n",dp[0][0]>1e5?-1:dp[0][0]);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}