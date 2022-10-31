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

const int N=200005;
struct edge{
	int v,nxt,w;
}c[N<<1];
int front[N],edge_cnt=-1;
Finline void addedge(int u,int v,int w)
{
	c[++edge_cnt]=(edge){v,front[u],w};
	front[u]=edge_cnt;
}
bool vis[N];
int a[N];
double b[N];
int st[N],top;
void dfs(int x,int id)
{
	if(a[x]) st[++top]=x;
	vis[x]=true;
	for(int i=front[x];~i;i=c[i].nxt)
	{
		if(i!=id&&i!=(id^1))
		{
			int v=c[i].v;
			int _a=-a[x];
			double _b=c[i].w-b[x];
			if(vis[v])
			{
				if(_a==a[v])
				{
					if(_b!=b[v])
					{
						printf("NO\n");
						exit(0);
					}
				}
				else
				{
					double x=(_b-b[v])/(double)(a[v]-_a);
					while(top)
					{
						int nd=st[top--];
						b[nd]+=a[nd]*x;a[nd]=0;
					}
				}
			}
			else
			{
				a[v]=_a,b[v]=_b;
				dfs(v,i);
			}
		}
	}
}
double d[N];
int main()
{
	memset(front,255,sizeof(front));
	int n,m;read(n,m);
	int x,y,z;
	for(int i=1;i<=m;++i)
	{
		read(x,y,z);
		addedge(x,y,z),addedge(y,x,z);
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			top=0;
			a[i]=1,b[i]=0.0;
			dfs(i,-233);
			if(top)
			{
				int pos=0;
				for(int j=1;j<=top;++j)
				{
					int nd=st[j];
					if(a[nd]==1) d[++pos]=-b[nd];
					else d[++pos]=b[nd];
				}
				std::sort(d+1,d+pos+1);
				double val=d[(pos+1)>>1];
				for(int j=1;j<=top;++j) b[st[j]]+=a[st[j]]*val;
			}
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;++i) printf("%.8lf ",b[i]);
	printf("\n");
	return 0;
}