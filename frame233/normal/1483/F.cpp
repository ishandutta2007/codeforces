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
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=1000005;
char s[N];
int ch[N][26],fa[N],fail[N],len[N],_q[N],_l,_r,nd[N],__[N],nc,a[N],c[N],dfn[N],siz[N],id,rev[N];
std::vector<int> e[N];
void add(int x,int C){for(;x<N;x+=lowbit(x))c[x]+=C;}
int ask(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
void dfs(int x){dfn[x]=++id,siz[x]=1;for(auto v:e[x])dfs(v),siz[x]+=siz[v];}
void build()
{
	_l=1,_r=0;for(int i=0;i<26;++i)if(ch[0][i])_q[++_r]=ch[0][i];
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		if(!__[x])__[x]=__[fail[x]];
		for(int i=0;i<26;++i)
		{
			if(ch[x][i])fail[ch[x][i]]=ch[fail[x]][i],_q[++_r]=ch[x][i];
			else ch[x][i]=ch[fail[x]][i];
		}
	}
	for(int i=1;i<=nc;++i)e[fail[i]].pb(i);
}
bool mark[N];
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i)
	{
		int L=read_str(s),cur=0;
		for(int j=0;j<L;++j)
		{
			int tmp=s[j]-97;
			if(!ch[cur][tmp])ch[cur][tmp]=++nc,len[nc]=len[cur]+1,fa[nc]=cur;
			cur=ch[cur][tmp];
		}
		nd[i]=cur,__[cur]=cur,rev[cur]=i;
	}
	build(),dfs(0);
	int ans=0;
	for(int _=1;_<=n;++_)
	{
		int pos=0,mn=inf,x;
		if(x=__[fail[nd[_]]];x)a[++pos]=x;
		for(int cur=fa[nd[_]];cur;cur=fa[cur])if(x=__[cur];x)a[++pos]=x;
		std::sort(a+1,a+pos+1,[&](int A,int B)->bool{return len[A]==len[B]?A<B:len[A]>len[B];});
		int np=std::unique(a+1,a+pos+1)-a-1;
		for(int i=1;i<=np;++i)mark[a[i]]=true;
		if(x=__[fail[nd[_]]];x)len[nd[_]]-len[x]+1>=mn?mark[x]=false:mn=len[nd[_]]-len[x]+1;
		for(int cur=fa[nd[_]];cur;cur=fa[cur])if(x=__[cur];x)len[cur]-len[__[cur]]+1>=mn?mark[__[cur]]=false:mn=len[cur]-len[__[cur]]+1;
		for(int i=1;i<=np;++i)mark[a[i]]&=ask(dfn[a[i]]+siz[a[i]]-1)==ask(dfn[a[i]]-1),add(dfn[a[i]],1);
		for(int i=1;i<=np;++i)add(dfn[a[i]],-1),ans+=mark[a[i]];
	}
	printf("%d\n",ans);
	return 0;
}