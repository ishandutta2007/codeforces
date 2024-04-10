// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd()
{
	static uint seed=416;
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
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
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
char s[5][N];
int dp[N][1<<3];
bool valid[1<<3][1<<3];
int main()
{
	int n,m;read(n,m);
	if(n>=4) return printf("-1\n"),0;
	if(n==1) return printf("0\n"),0;
	for(int s1=0;s1<8;++s1)
	{
		for(int s2=0;s2<8;++s2)
		{
			valid[s1][s2]=((!!(s1&1)+!!(s1&2)+!!(s2&1)+!!(s2&2))&1);
			if(n>2) valid[s1][s2]&=((!!(s1&4)+!!(s1&2)+!!(s2&4)+!!(s2&2))&1);
		}
	}
	for(int i=0;i<n;++i) read_str(s[i]+1);
	for(int i=1;i<=m;++i)
	{
		int S=0;
		for(int j=0;j<n;++j) if(s[j][i]=='1') S|=1<<j;
		for(int st=0;st<1<<n;++st)
		{
			dp[i][st]=inf;
			for(int s=0;s<1<<n;++s) if(valid[st][s]) chmin(dp[i][st],dp[i-1][s]+__builtin_popcount(st^S));
		}
	}
	int ans=inf;
	for(int st=0;st<1<<n;++st) chmin(ans,dp[m][st]);
	printf("%d\n",ans);
	return 0;
}