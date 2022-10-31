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
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int n,maxx,root;
int siz[N];
ll ans;
void getrt(int x,int fa)
{
	int tmp=0;siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa)
		{
			getrt(v,x);siz[x]+=siz[v];
			chmax(tmp,siz[v]);
		}
	}
	chmax(tmp,n-siz[x]);
	ans+=min(siz[x],n-siz[x]);
	if(tmp<maxx) maxx=tmp,root=x;
}
std::vector<int> qwq,nd[N];
void dfs(int x,int fa)
{
	qwq.pb(x);
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa) dfs(v,x);
	}
}
struct node{
	int val,id;
	Finline bool operator < (const node &o)const
	{
		return val<o.val;
	}
};
std::priority_queue<node> q;
int p[N];
int main()
{
	read(n);
	int x,y;
	for(int i=1;i<n;++i) read(x,y),addedge(x,y),addedge(y,x);
	maxx=inf,root=0,getrt(1,0);
	int pos=0;
	for(int i=front[root];i;i=c[i].nxt)
	{
		qwq.clear();
		dfs(c[i].v,root);
		nd[++pos]=qwq;
		q.push((node){SZ(qwq),pos});
	}
	int A=0,B=0;
	if(!(n&1))
	{
		qwq.clear();qwq.pb(root);
		nd[++pos]=qwq;q.push((node){SZ(qwq),pos});
	}
	while(SZ(q)>=2)
	{
		node x=q.top();q.pop();
		node y=q.top();q.pop();
		int a=x.id,b=y.id;A=nd[a].back(),B=nd[b].back();
		p[A]=B,p[B]=A;
		nd[a].pop_back(),nd[b].pop_back();
		if(!nd[a].empty()) q.push((node){SZ(nd[a]),a});
		if(!nd[b].empty()) q.push((node){SZ(nd[b]),b});
	}
	if(n&1) p[A]=root,p[root]=B,p[B]=A;
	printf("%lld\n",ans<<1);
	for(int i=1;i<=n;++i) printf("%d ",p[i]);
	printf("\n");
	return 0;
}