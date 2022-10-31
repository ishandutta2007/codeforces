// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>

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

const int N=300005;
int dp[6][6][6][105][3];
int len[6][6][6];
std::map<int,int> mp;
bool used[5];
Finline int mex(int a,int b)
{
	used[0]=used[1]=0;
	used[a]=used[b]=1;
	if(!used[0]) return 0;
	if(!used[1]) return 1;
	return 2;
}
Finline int mex(int a,int b,int c)
{
	used[0]=used[1]=used[2]=0;
	used[a]=used[b]=used[c]=1;
	if(!used[0]) return 0;
	if(!used[1]) return 1;
	if(!used[2]) return 2;
	return 3;
}
int calc(int x,int y,int z)
{
	mp.clear();
	int full=(1<<24)-1;
	int st=0;
	for(int i=1;i<=5;++i)
	{
		dp[x][y][z][i][0]=mex(dp[x][y][z][max(0,i-x)][0],dp[x][y][z][max(0,i-y)][1],dp[x][y][z][max(0,i-z)][2]);
		dp[x][y][z][i][1]=mex(dp[x][y][z][max(0,i-x)][0],dp[x][y][z][max(0,i-z)][2]);
		dp[x][y][z][i][2]=mex(dp[x][y][z][max(0,i-x)][0],dp[x][y][z][max(0,i-y)][1]);
		st=st<<6|(dp[x][y][z][i][0]<<4)|(dp[x][y][z][i][1]<<2)|dp[x][y][z][i][2];
		mp[st]=i;
	}
	int ans=0;
	for(int i=6;i<105;++i)
	{
		dp[x][y][z][i][0]=mex(dp[x][y][z][i-x][0],dp[x][y][z][i-y][1],dp[x][y][z][i-z][2]);
		dp[x][y][z][i][1]=mex(dp[x][y][z][i-x][0],dp[x][y][z][i-z][2]);
		dp[x][y][z][i][2]=mex(dp[x][y][z][i-x][0],dp[x][y][z][i-y][1]);
		st&=full;
		st=st<<6|(dp[x][y][z][i][0]<<4)|(dp[x][y][z][i][1]<<2)|dp[x][y][z][i][2];
		if(!ans&&mp.find(st)!=mp.end())
		{
			ans=i-mp[st];
		}
		mp[st]=i;
	}
	return ans;
}
int a[N];
void MAIN()
{
	int n,x,y,z;
	read(n,x,y,z);
	ll qwq;
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		read(qwq);
		if(qwq>60)
		{
			qwq=(qwq-60)%len[x][y][z]+60;
		}
		a[i]=qwq;
		ans^=dp[x][y][z][qwq][0];
	}
	int res=0;
	for(int i=1;i<=n;++i)
	{
		ans^=dp[x][y][z][a[i]][0];
		if(!(ans^dp[x][y][z][max(0,a[i]-x)][0])) ++res;
		if(!(ans^dp[x][y][z][max(0,a[i]-y)][1])) ++res;
		if(!(ans^dp[x][y][z][max(0,a[i]-z)][2])) ++res;
		ans^=dp[x][y][z][a[i]][0];
	}
	printf("%d\n",res);
}
int main()
{
	for(int x=1;x<=5;++x)
	{
		for(int y=1;y<=5;++y)
		{
			for(int z=1;z<=5;++z)
			{
				len[x][y][z]=calc(x,y,z);
			}
		}
	}
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}