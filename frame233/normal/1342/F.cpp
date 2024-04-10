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
typedef std::pair<int,int> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

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

const int N=20;
int dp[17][1<<15][17];
int opt[17][1<<15][17];
int a[N];
int n;
int sum[1<<15];
std::vector<pi> res;
void print(int i,int st,int j)
{
	if(!i) return;
	if(opt[i][st][j]==-1) print(i-1,st,j);
	else
	{
		int s=opt[i][st][j];
		print(i-1,s,j-1);
		res.pb(mkpr(i,st^s));
	}
}
int tot[N];
void MAIN()
{
	read(n);
	memset(tot,0,sizeof(tot));
	for(int i=1;i<=n;++i) read(a[i]);
	for(int st=0;st<1<<n;++st)
	{
		sum[st]=0;
		for(int i=0;i<n;++i)
		{
			if((st>>i)&1)
			{
				sum[st]+=a[i+1];
			}
		}
	}
	for(int st=0;st<1<<n;++st)
	{
		for(int j=0;j<=n;++j)
		{
			dp[0][st][j]=inf;
		}
	}
	dp[0][0][0]=0;
	for(int i=1;i<=n;++i)
	{
		for(int st=0;st<1<<n;++st)
		{
			for(int j=0;j<i;++j)
			{
				dp[i][st][j]=dp[i-1][st][j];
				opt[i][st][j]=-1;
			}
			dp[i][st][i]=inf;
		}
		for(int st=0;st<1<<n;++st)
		{
			if(!((st>>(i-1))&1)) continue;
			for(int s=(st-1)&st;;s=(s-1)&st)
			{
				if((s>>(i-1))&1) continue;
				for(int j=0;j<i;++j)
				{
					if(sum[st^s]>dp[i-1][s][j])
					{
						if(sum[st^s]<dp[i][st][j+1])
						{
							dp[i][st][j+1]=sum[st^s];
							opt[i][st][j+1]=s;
						}
					}
				}
				if(!s) break;
			}
		}
	}
	int ans=-1;
	for(int i=n;i>=0;--i)
	{
		if(dp[n][(1<<n)-1][i]<inf)
		{
			ans=i;
			break;
		}
	}
	printf("%d\n",n-ans);
	res.clear();
	print(n,(1<<n)-1,ans);
	std::vector<int> v;
	for(int i=1;i<=n;++i) v.pb(a[i]);
	std::vector<pi> tmp;
	auto move=[&](int x,int y)
	{
		if(x==y) return;
		int sum1=0,sum2=0;;
		for(int i=1;i<x;++i) sum1+=tot[i];
		for(int i=1;i<y;++i) sum2+=tot[i];
		++tot[x];
		x-=sum1,y-=sum2;
		tmp.pb(mkpr(x,y));
	};
	for(auto it:res)
	{
		int st=it.second;
		for(int i=0;i<n;++i)
		{
			if((st>>i)&1)
			{
				move(i+1,it.first);
			}
		}
	}
	for(auto it:tmp) printf("%d %d\n",it.first,it.second);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}