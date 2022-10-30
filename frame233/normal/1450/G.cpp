// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=(1<<20)+5;
char s[5005];
int L[N],R[N],cnt[N],t[27],id[27];
bool dp[N];
int main()
{
	memset(id,255,sizeof(id));
	int n,a,b;read(n,a,b);
	read_str(s+1);
	int m=0;
	for(int i=1;i<=n;++i)
	{
		int tmp=s[i]-'a';
		if(id[tmp]==-1) t[m]=tmp,id[tmp]=m,L[1<<m]=i,R[1<<m]=i,++m;
		else R[1<<id[tmp]]=i;
		++cnt[1<<id[tmp]];
	}
	std::vector<int> ans;
	for(int i=0;i<m;++i) if(a*(R[1<<i]-L[1<<i]+1)<=cnt[1<<i]*b) dp[1<<i]=true,((1<<i)==(1<<m)-1)&&(ans.pb(i),0);
	L[0]=n+1,R[0]=0,dp[0]=true;
	for(int st=1;st<1<<m;++st)
	{
		L[st]=min(L[lowbit(st)],L[st^lowbit(st)]),R[st]=max(R[lowbit(st)],R[st^lowbit(st)]),cnt[st]=cnt[lowbit(st)]+cnt[st^lowbit(st)];
		int cur=0;
		for(int i=0;i<m;++i)if((st>>i)&1)
		{
			cur|=1<<i;
			if(dp[cur]&&dp[st^cur]) dp[st]=true;
		}
		if(dp[st])
		{
			for(int i=0;i<m;++i)if(!((st>>i)&1))
			{
				int l=min(L[1<<i],L[st]),r=max(R[1<<i],R[st]);
				if(a*(r-l+1)<=(cnt[st]+cnt[1<<i])*b)
				{
					if((st|(1<<i))==(1<<m)-1) ans.pb(i);
					dp[st|(1<<i)]=true;
				}
			}
		}
	}
	std::sort(ans.begin(),ans.end(),[&](int a,int b)->bool{return t[a]<t[b];}),ans.erase(std::unique(ans.begin(),ans.end()),ans.end());
	printf("%d ",SZ(ans));
	for(auto it:ans) printf("%c ",t[it]+'a');
	printf("\n");
	return 0;
}