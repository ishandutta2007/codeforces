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

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}
const int N=1005;
int ch[N*5][10],node_cnt,s[N],fail[N*5];
bool end[N*5];
void ins(int *a,int len)
{
	int cur=0;
	for(int i=1;i<=len;++i)
	{
		if(!ch[cur][a[i]]) ch[cur][a[i]]=++node_cnt;
		cur=ch[cur][a[i]];
	}
	end[cur]=true;
}
int _q[N*5],_l,_r;
void build()
{
	_l=1,_r=0;
	for(int i=1;i<10;++i) if(ch[0][i]) _q[++_r]=ch[0][i];
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int i=1;i<10;++i)
		{
			if(ch[x][i]) fail[ch[x][i]]=ch[fail[x]][i],_q[++_r]=ch[x][i];
			else ch[x][i]=ch[fail[x]][i];
		}
	}
	for(int i=1;i<=node_cnt;++i) end[i]|=end[fail[i]];
}
int a[25],x;
void dfs(int sum,int dep)
{
	if(sum==x)
	{
		for(int i=1;i<dep;++i)
		{
			int tmp=0;
			for(int j=i;j<dep;++j)
			{
				tmp+=a[j];
				if(tmp!=x&&!(x%tmp)) return;
			}
		}
		ins(a,dep-1);
		return;
	}
	for(int i=1;i<=9&&sum+i<=x;++i)
	{
		a[dep]=i;
		dfs(sum+i,dep+1);
	}
}
char __[N];
int dp[N][N*5];
int main()
{
	int n=read_str(__+1);
	for(int i=1;i<=n;++i) s[i]=__[i]-48;
	read(x);dfs(0,1);
	build();
	memset(dp,63,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<=node_cnt;++j)
		{
			int to=ch[j][s[i+1]];
			if(!end[to]) chmin(dp[i+1][to],dp[i][j]);
			chmin(dp[i+1][j],dp[i][j]+1);
		}
	}
	int ans=inf;
	for(int i=0;i<=node_cnt;++i) chmin(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}