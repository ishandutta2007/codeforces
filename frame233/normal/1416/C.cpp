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
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=300005;
int a[N],siz[N*30];
int ch[N*30][2];
ll cnt[35][2];
int node_cnt;
void insert(int x)
{
	int cur=0;
	for(int i=30;i>=0;--i)
	{
		int tmp=(x>>i)&1;
		if(!ch[cur][tmp]) ch[cur][tmp]=++node_cnt;
		
		cnt[i][tmp]+=siz[ch[cur][!tmp]];
		
		cur=ch[cur][tmp];
		++siz[cur];
	}
}
int main()
{
	int n;read(n);
	int x;
	for(int i=1;i<=n;++i) read(x),insert(x);
	ll ans1=0;
	int ans2=0;
	for(int i=30;i>=0;--i)
	{
		if(cnt[i][0]<=cnt[i][1]) ans1+=cnt[i][0];
		else ans1+=cnt[i][1],ans2|=1<<i;
	}
	printf("%lld %d\n",ans1,ans2);
	return 0;
}