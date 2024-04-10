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
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
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

const int N=1000005;
int p[N],ans[N];
std::vector<int> v[N],e[N];
bool vis[N],mark[N];
int main()
{
	int n;read(n);
	if(n&1)
	{
		printf("Second\n");fflush(stdout);
		for(int i=1;i<=n<<1;++i) read(p[i]),v[p[i]].pb(i);
		for(int i=1;i<=n;++i) e[i].pb(i+n),e[i+n].pb(i),e[v[i][0]].pb(v[i][1]),e[v[i][1]].pb(v[i][0]);
		for(int i=1;i<=n<<1;++i)
		{
			if(!vis[i])
			{
				int cur=i,last=0,qwq=0;
				while(true)
				{
					++qwq;
					if(qwq&1) mark[cur]=true;
					vis[cur]=true;
					int tmp=cur;
					if(e[cur][0]!=last) cur=e[cur][0];
					else cur=e[cur][1];
					last=tmp;
					if(cur==i) break;
				}
			}
		}
		ll sum=0;
		for(int i=1;i<=n<<1;++i) if(mark[i]) sum+=i;
		if(sum%(n+n)) for(int i=1;i<=n<<1;++i) mark[i]^=1;
		for(int i=1;i<=n<<1;++i) if(mark[i]) printf("%d ",i);
		printf("\n");fflush(stdout);
		return 0;
	}
	printf("First\n");fflush(stdout);
	for(int i=2;i<=20;++i)
	{
		int val=1<<i;
		if(n%val)
		{
			int cur=0,j;
			for(j=1;j+(val<<1)-1<=n<<1;j+=val<<1) for(int k=0;k<val;++k) p[j+k]=p[j+k+val]=++cur;
			std::vector<int> v;
			v.pb(n<<1);for(;j<n<<1;++j) v.pb(j);
			for(int j=0;j<val>>1;++j) p[v[j]]=p[v[j+(val>>1)]]=++cur;
			for(int j=1;j<=n<<1;++j) printf("%d ",p[j]);
			printf("\n");fflush(stdout);
			return 0;
		}
	}
	return 0;
}