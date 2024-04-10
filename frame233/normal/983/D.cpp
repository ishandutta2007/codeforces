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

const int N=200005;
int tx[N],p1,ty[N],p2;
int X1[N],Y1[N],X2[N],Y2[N];
struct node{
	int l,r,opt;
};
std::vector<node> v[N];
template<typename _Tp>
class heap{
public:
	std::priority_queue<_Tp> q1,q2;
	int siz;
	inline bool empty(){return !siz;}
	inline int size(){return siz;}
	inline void push(const _Tp &o){q1.push(o);++siz;}
	inline void pop(const _Tp &o){q2.push(o);--siz;}
	inline _Tp top()
	{
		while(!q2.empty()&&q1.top()==q2.top()) q1.pop(),q2.pop();
		return q1.top();
	}
};
heap<int> q[N<<1];
int node_cnt;
int ls[N<<1],rs[N<<1];
int val1[N<<1],val2[N<<1];
bool ans[N];
inline void pushup(int cur)
{
	val1[cur]=max(val1[ls[cur]],val1[rs[cur]]);
	val2[cur]=min(val2[ls[cur]],val2[rs[cur]]);
	if(!q[cur].empty())
	{
		int x=q[cur].top();
		chmax(val2[cur],x);
		if(!ans[x]) chmax(val1[cur],x);
	}
	if(val1[cur]<val2[cur]) val1[cur]=0;
}
int build(int l,int r)
{
	int cur=++node_cnt;
	if(l==r) return cur;
	int mid=(l+r)>>1;
	ls[cur]=build(l,mid);
	rs[cur]=build(mid+1,r);
	return cur;
}
void Update(int L,int R,int C,int l,int r,int cur)
{
	if(L<=l&&r<=R)
	{
		if(C>0) q[cur].push(C);
		else if(C<0) q[cur].pop(-C);
		pushup(cur);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) Update(L,R,C,l,mid,ls[cur]);
	if(R>mid) Update(L,R,C,mid+1,r,rs[cur]);
	pushup(cur);
}
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i)
	{
		read(X1[i],Y1[i],X2[i],Y2[i]);
//		--Y2[i];
		tx[++p1]=X1[i],tx[++p1]=X2[i];
		ty[++p2]=Y1[i],ty[++p2]=Y2[i];
	}
	std::sort(tx+1,tx+p1+1),p1=std::unique(tx+1,tx+p1+1)-tx-1;
	std::sort(ty+1,ty+p2+1),p2=std::unique(ty+1,ty+p2+1)-ty-1;
	for(int i=1;i<=n;++i)
	{
		int l=Y1[i]=std::lower_bound(ty+1,ty+p2+1,Y1[i])-ty;
		int r=Y2[i]=std::lower_bound(ty+1,ty+p2+1,Y2[i])-ty-1;
		v[X1[i]=std::lower_bound(tx+1,tx+p1+1,X1[i])-tx].pb({l,r,i});
		v[X2[i]=std::lower_bound(tx+1,tx+p1+1,X2[i])-tx].pb({l,r,-i});
	}
	build(1,p2);
	for(int i=1;i<=p1;++i)
	{
		for(auto it:v[i]) Update(it.l,it.r,it.opt,1,p2,1);
		while(val1[1]) ans[val1[1]]=true,Update(Y1[val1[1]],Y2[val1[1]],0,1,p2,1);
	}
	int res=1;for(int i=1;i<=n;++i) if(ans[i]) ++res;
	printf("%d\n",res);
	return 0;
}