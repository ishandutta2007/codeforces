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

const int N=1000005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
inline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int bel[N];
std::vector<int> nd[N];
std::vector<pi> opt;
struct Union_set{
	int fa[N],siz[N];
	void init(){for(int i=1;i<N;++i) fa[i]=i,siz[i]=1;}
	int find(int x){while(x!=fa[x])x=fa[x];return x;}
	inline void merge(int x,int y,bool flag)
	{
		x=find(x),y=find(y);
		if(x==y) return;
		if(siz[x]>siz[y]) std::swap(x,y);
		fa[x]=y,siz[y]+=siz[x];
		if(flag) opt.pb({x,y});
	}
	inline void reset()
	{
		while(!opt.empty())
		{
			pi tmp=opt.back();
			opt.pop_back();
			fa[tmp.first]=tmp.first,siz[tmp.second]-=siz[tmp.first];
		}
	}
}S;
bool tag[N];
pi a[N];
int  b[N];
int main()
{
	int n,m,k;read(n,m,k);
	for(int i=1;i<=n;++i) read(bel[i]),nd[bel[i]].pb(i);
	int x,y;
	for(int i=1;i<=m;++i) read(x,y),addedge(x,y),addedge(y,x);
	S.init();
	int cnt=0;
	for(int i=1;i<=k;++i)
	{
		tag[i]=true;
		for(auto it:nd[i])
		{
			for(int _=front[it];_;_=c[_].nxt)
			{
				int v=c[_].v;
				if(bel[v]==i&&v<it)
				{
					if(S.find(it)==S.find(v)||S.find(it+n)==S.find(v+n))
					{
						tag[i]=false;
						break;
					}
					S.merge(it,v+n,false),S.merge(it+n,v,false);
				}
			}
			if(!tag[i]) break;
		}
		if(tag[i]) ++cnt;
	}
	ll ans=0,res=0;
	for(int i=1;i<=k;++i)
	{
		if(!tag[i]) continue;
		int pos=0,p=0;
		for(auto it:nd[i])
		{
			for(int _=front[it];_;_=c[_].nxt)
			{
				int v=c[_].v;
				if(bel[v]==i) continue;
				if(tag[bel[v]])
				{
					b[++p]=bel[v];
					if(bel[v]<i) a[++pos]={it,v};
				}
			}
		}
		std::sort(b+1,b+p+1),p=std::unique(b+1,b+p+1)-b-1;
		std::sort(a+1,a+pos+1,[&](const pi &A,const pi &B)->bool{return bel[A.second]<bel[B.second];});
		res+=cnt-1-p;
		for(int j=1;j<=pos;++j)
		{
			int k=j;
			while(k<pos&&bel[a[k+1].second]==bel[a[j].second]) ++k;
			bool flag=true;
			for(int t=j;t<=k;++t)
			{
				int A=a[t].first,B=a[t].second;
				if(S.find(A)==S.find(B)||S.find(A+n)==S.find(B+n))
				{
					flag=false;
					break;
				}
				S.merge(A,B+n,true),S.merge(A+n,B,true);
			}
			if(flag) ++ans;
			j=k,S.reset();
		}
	}
	assert(res%2==0);
	printf("%lld\n",ans+res/2);
	return 0;
}