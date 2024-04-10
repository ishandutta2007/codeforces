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

const int N=100005;
const int MAXN=10000005;
bool pr[MAXN];
int _p[MAXN>>3],_pos;
int md[MAXN];
void sieve()
{
	for(int i=2;i<MAXN;++i)
	{
		if(!pr[i])
		{
			_p[++_pos]=i;
			md[i]=i;
		}
		for(int j=1;j<=_pos&&i*_p[j]<MAXN;++j)
		{
			pr[i*_p[j]]=true;
			md[i*_p[j]]=_p[j];
			if(!(i%_p[j])) break;
		}
	}
}
std::vector<int> p[N],d[N];
int c[MAXN],cnt[1<<8],mul[1<<8];
int calc(int id)
{
	int siz=SZ(p[id]),ans=0;
	for(int i=0;i<siz;++i) mul[1<<i]=p[id][i];
	for(int i=1;i<1<<siz;++i)
	{
		cnt[i]=cnt[i>>1]+(i&1);
		mul[i]=mul[i^lowbit(i)]*mul[lowbit(i)];
		if(cnt[i]&1) ans+=c[mul[i]];
		else ans-=c[mul[i]];
	}
	return ans;
}
int a[N];
int _val[11],_cnt[11],pos,cur_id;
void dfs(int dep,int val)
{
	if(dep==pos+1)
	{
		d[cur_id].pb(val);
		return;
	}
	for(int i=0;i<=_cnt[dep];++i)
	{
		dfs(dep+1,val);
		if(i<_cnt[dep]) val*=_val[dep];
	}
}
bool ban[N],vis[N];
int deg[N];
int f(int mid)
{
	while(ban[mid]) --mid;
	if(!mid) return false;
	int qwq=0;
	for(int i=1;i<=mid;++i) if(!ban[i]){++qwq;for(auto it:d[i]) ++c[it];}
	int ans=0;for(int i=1;i<=mid;++i) if(!ban[i]&&calc(i)!=qwq) ++ans;
	for(int i=1;i<=mid;++i) if(!ban[i]) for(auto it:d[i]) --c[it];
	return ans;
}
std::vector<int> getnodes(int mid)
{
	while(ban[mid]) --mid;
	std::vector<int> nd;
	int qwq=0;
	for(int i=1;i<=mid;++i) if(!ban[i]){++qwq;for(auto it:d[i]) ++c[it];}
	for(int i=1;i<=mid;++i) if(!ban[i]&&calc(i)!=qwq) nd.pb(i);
	for(int i=1;i<=mid;++i) if(!ban[i]) for(auto it:d[i]) --c[it];
	return nd;
}
int main()
{
	mul[0]=1;sieve();
	int n,k;read(n,k);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);++c[a[i]];
		int cur=a[i],last=0;
		pos=0;
		while(cur>1)
		{
			if(md[cur]!=last) p[i].pb(md[cur]),_val[++pos]=md[cur],_cnt[pos]=1;
			else ++_cnt[pos];
			last=md[cur];
			cur/=last;
		}
		cur_id=i;dfs(1,1);
	}
	for(int j=1;j<=_pos;++j) for(int i=(MAXN-1)/_p[j];i>=1;--i) c[i]+=c[i*_p[j]];
	std::vector<int> nd;
	for(int i=1;i<=n;++i)
	{
		if((deg[i]=calc(i))<=n-2)
		{
			nd.pb(i);
			for(int j=1;j<=n&&SZ(nd)<3;++j) if(i!=j&&gcd(a[i],a[j])==1) nd.pb(j);
			break;
		}
	}
	if(nd.empty())
	{
		std::vector<int> clique,rest;
		for(int i=1;i<=n;++i) if(deg[i]==n) clique.pb(i);else rest.pb(i);
		if(SZ(clique)>k) clique.resize(k);
		for(int i=1;i<=n&&SZ(clique)<k;++i)
		{
			if(!vis[i]&&deg[i]==n-1)
			{
				clique.pb(i);
				for(auto it:rest) if(gcd(a[it],a[i])==1) vis[it]=true;
			}
		}
		for(auto it:clique) printf("%d ",it);
		printf("\n");
		return 0;
	}
	if(k==3)
	{
		for(auto it:nd) printf("%d ",it);
		printf("\n");
		return 0;
	}
	for(auto it:nd) ban[it]=true;
	for(auto id:nd) for(auto it:d[id]) --c[it];
	std::vector<int> clique;
	for(int i=1;i<=n;++i) if(!ban[i]&&((deg[i]=calc(i))==n-3)) clique.pb(i);
	if(SZ(clique)>=k)
	{
		clique.resize(k);
		for(auto it:clique) printf("%d ",it);
		printf("\n");
		return 0;
	}
	memset(c,0,sizeof(c));
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(f(mid)+3>=k) r=mid;
		else l=mid+1;
	}
	std::vector<int> v1=getnodes(l-1);
	std::vector<int> v2=getnodes(l);
	std::sort(v1.begin(),v1.end());
	std::vector<int> qwq;
	for(auto it:v2)
	{
		auto _=std::lower_bound(v1.begin(),v1.end(),it);
		if(_==v1.end()||*_!=it) qwq.pb(it);
	}
	std::sort(qwq.begin(),qwq.end());
	if(SZ(v1)+3+1==k&&SZ(qwq)!=1) v1.pb(nd[0]),v1.pb(nd[1]);
	else v1.pb(nd[0]),v1.pb(nd[1]),v1.pb(nd[2]);
	while(SZ(v1)<k)
	{
		v1.pb(qwq.back());
		qwq.pop_back();
	}
	for(auto it:v1) printf("%d ",it);
	printf("\n");
	return 0;
}