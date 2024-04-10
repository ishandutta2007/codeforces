// Author -- Frame
 
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
 
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
 
#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;
 
uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
 
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}
 
const int N=300005;
const int mod[2]={1000000007,1000000009};
const int base=2333;
char s[N];
int a[N];
ll pw[2][N],inv[2][N];
ll ksm(ll a,ll b,ll mod)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
ll _inv[2]={ksm(base,mod[0]-2,mod[0]),ksm(base,mod[1]-2,mod[1])};
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
ll hash1[2][N];
ll hash2[2][N];
int dep[N],len[N],son[N];
int f[N][19];
int *Fa[N],*Son[N];
int top[N];
int v[N<<1],pos;
int val[N<<1],first[N];
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<19;++i)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int i=0;i<2;++i)
	{
		hash1[i][x]=(hash1[i][fa]*base+a[x])%mod[i];
		hash2[i][x]=(pw[i][dep[x]]*a[x]+hash2[i][fa])%mod[i];
	}
	len[x]=1;
	v[++pos]=x;
	val[pos]=dep[x];
	first[x]=pos;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			dfs1(c[i].v,x);
			v[++pos]=x;
			val[pos]=dep[x];
			if(len[c[i].v]+1>len[x])
			{
				len[x]=len[c[i].v]+1;
				son[x]=c[i].v;
			}
		}
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	if(x==topf)
	{
		Fa[x]=(int *)malloc((len[x]+1)<<2);
		int cur=x;
		for(int T=0;T<=len[x];++T)
		{
			Fa[x][T]=cur;
			cur=f[cur][0];
		}
		Son[x]=(int *)malloc((len[x]+1)<<2);
	}
	Son[topf][dep[x]-dep[topf]]=x;
	if(!son[x]) return;
	dfs2(son[x],topf);
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!top[c[i].v])
		{
			dfs2(c[i].v,c[i].v);
		}
	}
}
int F[N<<1][20],G[N<<1][20];
int Log2[N<<1];
void init()
{
	for(int i=2;i<N<<1;++i) Log2[i]=Log2[i>>1]+1;
	for(int i=pos;i>=1;--i)
	{
		F[i][0]=val[i];
		G[i][0]=v[i];
		for(int j=1;j<20&&(i+(1<<(j-1)))<=pos;++j)
		{
			if(F[i][j-1]>F[i+(1<<(j-1))][j-1])
			{
				F[i][j]=F[i+(1<<(j-1))][j-1];
				G[i][j]=G[i+(1<<(j-1))][j-1];
			}
			else
			{
				F[i][j]=F[i][j-1];
				G[i][j]=G[i][j-1];
			}
		}
	}
}
int lca(int l,int r)
{
	l=first[l],r=first[r];
	if(l>r) std::swap(l,r);
	int k=Log2[r-l+1];
	return F[l][k]<F[r-(1<<k)+1][k]?G[l][k]:G[r-(1<<k)+1][k];
}
int highbit[N];
Finline int jump(int x,int k)
{
	if(!k) return x;
	if(k>dep[x]) return 0;
	int qwq=highbit[k];
	x=f[x][qwq];
	k-=1<<qwq;
	int rest=dep[x]-dep[top[x]];
	return k<=rest?Son[top[x]][rest-k]:Fa[top[x]][k-rest];
}
int main()
{
	pw[0][0]=pw[1][0]=1;
	inv[0][0]=inv[1][0]=1;
	for(int i=1;i<N;++i)
	{
		for(int j=0;j<2;++j)
		{
			pw[j][i]=pw[j][i-1]*base%mod[j];
			inv[j][i]=inv[j][i-1]*_inv[j]%mod[j];
		}
		highbit[i]=31-__builtin_clz(i);
	}
	int n;
	read(n);
	read_str(s+1);
	for(int i=1;i<=n;++i) a[i]=s[i]-96;
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	dep[0]=-1;
	dfs1(1,0);
	dfs2(1,1);
	init();
	int _;
	read(_);
	int a,b,c,d;
	while(_--)
	{
		read(a,b,c,d);
		int l1=lca(a,b);
		int l2=lca(c,d);
		int len1=dep[a]+dep[b]-dep[l1]*2+1;
		int len2=dep[c]+dep[d]-dep[l2]*2+1;
		int l=0,r=min(len1,len2);
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			ll val1[2],val2;
			bool flag=true;
			if(mid<=dep[a]-dep[l1]+1)
			{
				int nd1=jump(a,mid);
				for(int i=0;i<2;++i)
				{
					val1[i]=(hash2[i][a]-hash2[i][nd1]+mod[i])*inv[i][dep[nd1]+1]%mod[i];
				}
			}
			else
			{
				int nd1=jump(b,len1-mid);
				for(int i=0;i<2;++i)
				{
					val1[i]=((hash2[i][a]-hash2[i][f[l1][0]]+mod[i])*inv[i][dep[l1]]%mod[i]*pw[i][dep[nd1]-dep[l1]]+(hash1[i][nd1]-hash1[i][l1]*pw[i][dep[nd1]-dep[l1]]%mod[i]+mod[i]))%mod[i];
				}
			}
			if(mid<=dep[c]-dep[l2]+1)
			{
				int nd2=jump(c,mid);
				for(int i=0;i<2;++i)
				{
					val2=(hash2[i][c]-hash2[i][nd2]+mod[i])*inv[i][dep[nd2]+1]%mod[i];
					if(val1[i]!=val2)
					{
						flag=false;
						break;
					}
				}
			}
			else
			{
				int nd2=jump(d,len2-mid);
				for(int i=0;i<2;++i)
				{
					val2=((hash2[i][c]-hash2[i][f[l2][0]]+mod[i])*inv[i][dep[l2]]%mod[i]*pw[i][dep[nd2]-dep[l2]]+(hash1[i][nd2]-hash1[i][l2]*pw[i][dep[nd2]-dep[l2]]%mod[i]+mod[i]))%mod[i];
					if(val1[i]!=val2)
					{
						flag=false;
						break;
					}
				}
			}
			if(flag) l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
	}
    return 0;
}