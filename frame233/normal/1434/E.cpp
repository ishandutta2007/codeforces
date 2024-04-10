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

const int N=100005;
int a[N],n;
int pos[N<<1];
struct vec{
	int a[505],pos;
	inline int size(){return pos;}
	inline void clear(){pos=0;}
	inline void pb(int x){a[pos++]=x;}
	inline int* begin(){return a;}
	inline int* end(){return a+pos;}
}sg[N];
int fa[505][N];
int find(int *fa,int x){return x==fa[x]?x:fa[x]=find(fa,fa[x]);}
bool st[N][505];
int res[N];
inline bool cmp(int a,int b){return a>b;}
int Query(int i,int j)
{
	if(2*a[i]<j) return 0;
	int pos=max(i+1,::pos[2*a[i]-j+1]);
	return std::upper_bound(sg[i].begin(),sg[i].end(),pos,cmp)-sg[i].begin();
}
void upd(int i,int l,int r,int val)
{
	int pos=l;
	while(true)
	{
		pos=find(fa[val],pos);
		if(pos>r) break;
		st[pos][val]=true;
		while(st[pos][res[pos]]) sg[pos].pb(i),++res[pos];
		fa[val][pos]=pos+1;
	}
}

int L[N],R[N];
bool vis[N];
int mex(const std::vector<int> &o)
{
	for(auto it:o) vis[it]=true;
	int ans=0;for(int i=0;;++i) if(!vis[i]){ans=i;break;}
	for(auto it:o) vis[it]=false;
	return ans;
}
int solve()
{
	memset(res,0,sizeof(res));
	read(n);
	std::fill(pos,pos+(N<<1),n+1);
	pos[0]=0;
	for(int i=0;i<N;++i) L[i]=inf,R[i]=0;
	for(int i=0;i<=500;++i) for(int j=0;j<=n+1;++j) fa[i][j]=j;
	for(int i=0;i<=n+1;++i) sg[i].clear();
	for(int i=0;i<=n+1;++i) memset(st[i],0,sizeof(st[i]));
	for(int i=1;i<=n;++i) read(a[i]),pos[a[i]]=i;
	for(int i=200000;i>=0;--i) chmin(pos[i],pos[i+1]),chmax(R[pos[i]],i),chmin(L[pos[i]],i);
	std::vector<int> v;
	for(int i=n;i>=1;--i)
	{
		std::vector<std::tuple<int,int,int>> _;
		for(int j=0;j<=sg[i].size();++j)
		{
			int pl=j<SZ(sg[i])?sg[i].a[j]+1:0,pr=j?sg[i].a[j-1]:n+1;
			if(pl>pr) continue;
			int L=::L[pl],R=::R[pr];
			if(L>R) continue;
			int vl=2*a[i]+1-R,vr=2*a[i]+1-L;
			chmax(vl,0);
			if(vl>vr) continue;
			int l=pos[vl],r=pos[vr+1]-1;
			if(l<=r)
			{
				_.pb({l,r,j});
				if(l<=i&&i<=r) v.pb(j);
			}
		}
		for(auto it:_) upd(i,std::get<0>(it),std::get<1>(it),std::get<2>(it));
	}
	return mex(v);
}
int main()
{
	
	int n;read(n);
	int ans=0;
	while(n--) ans^=solve();
	puts(ans?"YES":"NO");
	return 0;
}