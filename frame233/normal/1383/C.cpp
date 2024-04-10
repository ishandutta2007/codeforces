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
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
char s[N],t[N];
int to[25],fa[25],S[25];
bool dp[1<<20];
int cnt[1<<20];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void MAIN()
{
	memset(to,0,sizeof(to));memset(dp,0,sizeof(dp));memset(S,0,sizeof(S));
	for(int i=0;i<20;++i) fa[i]=i,dp[1<<i]=true;
	int n;read(n);read_str(s+1),read_str(t+1);
	for(int i=1;i<=n;++i) if(s[i]!=t[i]) to[s[i]-'a']|=1<<(t[i]-'a'),fa[find(s[i]-'a')]=find(t[i]-'a');
	for(int st=0;st<1<<20;++st) for(int i=0;i<20;++i) if((st>>i)&1) dp[st]|=dp[st^(1<<i)]&&!(to[i]&st);
	for(int i=0;i<20;++i) S[find(i)]|=1<<i;
	int ans=40;
	for(int i=0;i<20;++i)
	{
		if(fa[i]!=i) continue;
		int tmp=0;for(int s=S[i];s;s=(s-1)&S[i]) if(dp[s]) chmax(tmp,cnt[s]);
		ans-=tmp+1;
	}
	printf("%d\n",ans);
}
int main()
{
	for(int i=1;i<1<<20;++i) cnt[i]=cnt[i>>1]+(i&1);
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}