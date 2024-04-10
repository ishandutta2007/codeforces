// Author -- xyr2005

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

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=400005;
char s[N];
struct SAM{
	int ch[N][26],fa[N],len[N],nd[N],rev[N];
	int node_cnt,last;
	SAM():node_cnt(1),last(1){}
	void insert(int c,int id)
	{
		int cur=++node_cnt;len[cur]=len[last]+1,nd[id]=cur,rev[cur]=id;
		int p=last;while(p&&!ch[p][c]) ch[p][c]=cur,p=fa[p];
		if(!p) fa[cur]=1;
		else
		{
			int q=ch[p][c];
			if(len[q]==len[p]+1) fa[cur]=q;
			else
			{
				int clone=++node_cnt;memcpy(ch[clone],ch[q],104),len[clone]=len[p]+1,fa[clone]=fa[q];
				fa[q]=fa[cur]=clone;while(p&&ch[p][c]==q) ch[p][c]=clone,p=fa[p];
			}
		}
		last=cur;
	}
}sam1,sam2;
struct edge{
	int v,nxt,w;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v,int w)
{
	c[++edge_cnt]=(edge){v,front[u],w};
	front[u]=edge_cnt;
}
int dep[N],val[N],rev[N];
int f[N<<1][21],pos,Log2[N<<1],fir[N];
ll dis[N],_dis[N<<1];
Finline int _min(int x,int y){return dep[x]<dep[y]?x:y;}
void dfs(int x)
{
	f[++pos][0]=x,fir[x]=pos,rev[pos]=x;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v,w=c[i].w;
		dep[v]=dep[x]+1,dis[v]=dis[x]+w;
		dfs(v),f[++pos][0]=x;
	}
}
Finline int lca(int l,int r)
{
	int k=Log2[r-l+1];
	return _min(f[l][k],f[r-(1<<k)+1][k]);
}
Finline ll getdis(int x,int y)
{
	if(x<=0||y>pos) return 0LL;
	return _dis[x]+_dis[y]-(dis[lca(x,y)]<<1);
}
struct seg_tr{
	struct Node{
		int ls,rs;
		int minn,maxx;
		ll sum;
		Node(){minn=inf,maxx=0;}
	}f[N*25];
	int node_cnt;
	Finline void pushup(int x)
	{
		f[x].minn=min(f[f[x].ls].minn,f[f[x].rs].minn);
		f[x].maxx=max(f[f[x].ls].maxx,f[f[x].rs].maxx);
		f[x].sum=f[f[x].ls].sum+f[f[x].rs].sum+getdis(f[f[x].ls].maxx,f[f[x].rs].minn);
	}
	void Update(int &cur,int pos,int l,int r)
	{
		if(!cur) cur=++node_cnt;
		if(l==r) return (void)(f[cur].minn=f[cur].maxx=l);
		int mid=(l+r)>>1;
		if(pos<=mid) Update(f[cur].ls,pos,l,mid);
		else Update(f[cur].rs,pos,mid+1,r);
		pushup(cur);
	}
	int merge(int a,int b,int l,int r)
	{
		if(!a||!b) return a|b;
		if(l==r) return a;
		int mid=(l+r)>>1;
		f[a].ls=merge(f[a].ls,f[b].ls,l,mid);
		f[a].rs=merge(f[a].rs,f[b].rs,mid+1,r);
		return pushup(a),a;
	}
	Finline ll Query(int root)
	{
		return (f[root].sum+getdis(f[root].minn,f[root].maxx))>>1;
	}
}tr;
int root[N];
int tax[N],A[N];
bool tag[N];
int main()
{
	for(int i=2;i<N<<1;++i) Log2[i]=Log2[i>>1]+1;
	int n=read_str(s+1);
	for(int i=1;i<=n;++i) sam1.insert(s[i]-97,i);
	for(int i=n;i>1;--i) sam2.insert(s[i]-97,i);
	ll ans=2;
	for(int i=1;i<=sam2.node_cnt;++i) ans+=sam2.len[i]-sam2.len[sam2.fa[i]];
	sam2.insert(s[1]-97,1);
	for(int i=2;i<=sam2.node_cnt;++i) val[i]=sam2.len[i]-sam2.len[sam2.fa[i]];
	for(int i=2;i<=sam2.node_cnt;++i) addedge(sam2.fa[i],i,val[i]);
	dfs(1);for(int i=pos;i>=1;--i) for(int j=1;j<=20&&i+(1<<(j-1))<=pos;++j) f[i][j]=_min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=pos;++i) _dis[i]=dis[rev[i]];

	int maxx=0;for(int i=1;i<=sam1.node_cnt;++i) chmax(maxx,sam1.len[i]);
	memset(tax,0,(maxx+3)<<2);
	for(int i=1;i<=sam1.node_cnt;++i) ++tax[sam1.len[i]];
	for(int i=1;i<=maxx;++i) tax[i]+=tax[i-1];
	for(int i=1;i<=sam1.node_cnt;++i) A[tax[sam1.len[i]]--]=i;
	for(int i=1;i<=sam1.node_cnt;++i)
	{
		if(sam1.rev[i]&&sam1.rev[i]<n)
		{
			if(sam1.rev[i]<n-1) tr.Update(root[i],fir[sam2.nd[sam1.rev[i]+2]],1,pos);
			tr.Update(root[i],fir[1],1,pos),tag[i]=true;
		}
	}
	for(int i=1;i<=sam1.node_cnt;++i) ans+=sam1.len[i]-sam1.len[sam1.fa[i]];
	for(int t=sam1.node_cnt;t>1;--t)
	{
		int i=A[t];
		if(!tag[i]) continue;
		ans+=1LL*(sam1.len[i]-sam1.len[sam1.fa[i]])*(tr.Query(root[i])+1);
		root[sam1.fa[i]]=tr.merge(root[sam1.fa[i]],root[i],1,pos);
		tag[sam1.fa[i]]|=tag[i];
	}
	printf("%lld\n",ans);
	return 0;
}