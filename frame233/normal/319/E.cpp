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

const int N=200005;
int fa[N],L[N],R[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	fa[x]=y,chmin(L[y],L[x]),chmax(R[y],R[x]);
}
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
std::vector<int> v[N<<2];
void Update(int L,int R,int l,int r,int id,int cur)
{
	if(L>R) return;
	if(L<=l&&r<=R)
	{
		v[cur].pb(id);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) Update(L,R,l,mid,id,ls(cur));
	if(R>mid) Update(L,R,mid+1,r,id,rs(cur));
}
void Query(int pos,int l,int r,int id,int cur)
{
	for(auto it:v[cur]) merge(it,id);
	if(SZ(v[cur])>1) v[cur].resize(1);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(pos<=mid) Query(pos,l,mid,id,ls(cur));
	else Query(pos,mid+1,r,id,rs(cur));
}
int O[N],X[N],Y[N],t[N],pos;
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i)
	{
		read(O[i],X[i],Y[i]);
		if(O[i]==1) t[++pos]=X[i],t[++pos]=Y[i];
	}
	std::sort(t+1,t+pos+1),pos=std::unique(t+1,t+pos+1)-t-1;
	int opt,x,y,c=0;
	for(int i=1;i<=n;++i)
	{
		opt=O[i],x=X[i],y=Y[i];
		if(opt==1)
		{
			++c,fa[c]=c,L[c]=x,R[c]=y;
			Query(std::lower_bound(t+1,t+pos+1,x)-t,1,pos,c,1);
			Query(std::lower_bound(t+1,t+pos+1,y)-t,1,pos,c,1);
			Update(std::lower_bound(t+1,t+pos+1,x+1)-t,std::upper_bound(t+1,t+pos+1,y-1)-t-1,1,pos,c,1);
		}
		else
		{
			if(find(x)==find(y)) puts("YES");
			else
			{
				int L1=L[find(x)],R1=R[find(x)];
				int L2=L[find(y)],R2=R[find(y)];
				if((L1>L2&&L1<R2)||(R1>L2&&R1<R2)) puts("YES");
				else puts("NO");
			}
		}
	}
	return 0;
}