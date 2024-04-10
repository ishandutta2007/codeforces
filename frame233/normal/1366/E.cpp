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

const int N=400005;
const int mod=998244353;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int a[N],b[N];
int t[N],pos,id[N];
int minn[N],L[N],R[N];
int dp[N];
int main()
{
	int n,m;
	read(n,m);
	for(int i=1;i<=n;++i) read(a[i]),t[++pos]=a[i];
	for(int i=1;i<=m;++i) read(b[i]),t[++pos]=b[i];
	std::sort(t+1,t+pos+1);
	pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i) a[i]=std::lower_bound(t+1,t+pos+1,a[i])-t;
	for(int i=1;i<=m;++i) b[i]=std::lower_bound(t+1,t+pos+1,b[i])-t,id[b[i]]=i;
	minn[n+1]=inf;
	for(int i=n;i>=1;--i) minn[i]=min(minn[i+1],a[i]);
	memset(L,63,sizeof(L));
	for(int i=1;i<=n;++i)
	{
		chmin(L[minn[i]],i);
		chmax(R[minn[i]],i);
	}
	dp[0]=1;
	dp[1]=mod-1;
	int ans=0;
	if(minn[1]!=b[1])
	{
		printf("0\n");
		return 0;
	}
	if(m==1)
	{
		printf("1\n");
		return 0;
	}
	for(int i=0;i<n;++i)
	{
		if(i) add(dp[i],dp[i-1]);
		if(id[minn[i+1]]==m)
		{
			add(ans,dp[i]);
			continue;
		}
		int tmp=id[minn[i+1]];
		if(!tmp) continue;
		int l=L[b[tmp+1]]-1,r=R[b[tmp+1]]-1;
		chmax(l,i+1);
		if(l>r) continue;
		add(dp[l],dp[i]);
		sub(dp[r+1],dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}