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

const int N=1005;
int dep[N],a[N],b[N],c[N],d[N];
int cur[N];
int D[N],n;
void query(const std::vector<int> &x,int y,int *a)
{
	if(x.empty())
	{
		for(int i=1;i<=n;++i) a[i]=0;
		return;
	}
	memset(D,0,sizeof(D));
	for(auto it:x) D[it]=y;
	printf("? ");for(int i=1;i<=n;++i) printf("%d%c",D[i]," \n"[i==n]);
	fflush(stdout);char ch;
	for(int i=1;i<=n;++i)
	{
		ch=getchar();while(ch!='0'&&ch!='1') ch=getchar();
		a[i]=ch-48;
	}
}
std::bitset<N> son[85],rev[85],tmp;
int main()
{
	memset(dep,255,sizeof(dep));
	read(n);
	int m=1;while(m<n) m<<=1;
	dep[1]=0;
	while(m>1)
	{
		int last=m;
		m>>=1;
		std::vector<int> v1,v2;
		for(int i=1;i<=n;++i)
		{
			if(dep[i]==-1) continue;
			if(dep[i]&last) v1.pb(i);
			else v2.pb(i);
		}
		query(v1,m,a);
		query(v1,m-1,b);
		query(v2,m,c);
		query(v2,m-1,d);
		for(int i=1;i<=n;++i)
		{
			if(~dep[i]) continue;
			if(cur[i]&(m<<1))
			{
				if(a[i]&&!b[i]) dep[i]=cur[i]|m;
				else if(!a[i]) cur[i]|=m;
			}
			else
			{
				if(c[i]&&!d[i]) dep[i]=cur[i]|m;
				else if(!c[i]) cur[i]|=m;
			}
		}
		last=m;
	}
	std::vector<pi> ans;
	for(int r=0;r<3;++r)
	{
		std::vector<int> nd;
		for(int i=1;i<=n;++i) if(dep[i]%3==r) nd.pb(i);
		int maxB=0;while((1<<maxB)<=SZ(nd)) ++maxB;
		for(int b=0;b<maxB;++b)
		{
			std::vector<int> v;
			for(int i=0;i<SZ(nd);++i) if((i>>b)&1) v.pb(nd[i]);
			query(v,1,a);son[b].reset(),rev[b].reset();
			for(int i=1;i<=n;++i)
			{
				if(dep[i]%3==(r+1)%3)
				{
					if(a[i]) son[b].set(i);
					else rev[b].set(i);
				}
			}
		}
		for(int i=0;i<SZ(nd);++i)
		{
			tmp.reset();
			for(int j=1;j<=n;++j) if(dep[j]==dep[nd[i]]+1) tmp.set(j);
			for(int j=0;j<maxB;++j) if((i>>j)&1) tmp&=son[j];else tmp&=rev[j];
			for(int j=1;j<=n;++j) if(tmp.test(j)) ans.pb(mkpr(nd[i],j));
		}
	}
	printf("!\n");
	for(auto it:ans) printf("%d %d\n",it.first,it.second);
	fflush(stdout);
	return 0;
}