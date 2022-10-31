// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

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
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
int dg[N];
Finline void add(int u,int v)
{
	++dg[v];
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int E[N][2];
int _q[N],_l,_r;
int q[N],l,r;
int s[N];
int n;
int last[N];
void topo()
{
	_l=1,_r=0;
	l=1,r=0;
	int rest=n;
	for(int i=1;i<=n;++i)
	{
		if(!dg[i])
		{
			_q[++_r]=i;
			q[++r]=i;
			--rest;
		}
	}
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		if(_r-_l+2==1)
		{
			s[x]+=rest;
		}
		else if(_r-_l+2==2)
		{
			int y=_q[_l];
			bool flag=true;
			for(int i=front[y];i;i=c[i].nxt)
			{
				if(dg[c[i].v]==1)
				{
					flag=false;
					break;
				}
			}
			if(flag) s[x]+=rest;
		}
		for(int i=front[x];i;i=c[i].nxt)
		{
			if(!--dg[c[i].v])
			{
				_q[++_r]=c[i].v;
				q[++r]=c[i].v;
				--rest;
			}
		}
	}
}
int main()
{
	int m;
	read(n,m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		add(x,y);
		E[i][0]=x,E[i][1]=y;
	}
	topo();
//	for(int i=1;i<=n;++i) printf("%d ",s[i]);
//	printf("\n");
	memset(dg,0,sizeof(dg));
	edge_cnt=0;
	memset(front,0,sizeof(front));
	for(int i=1;i<=m;++i)
	{
		add(E[i][1],E[i][0]);
	}
	topo();
//	for(int i=1;i<=n;++i) printf("%d ",s[i]);
//	printf("\n");
	int ans=0;
	for(int i=1;i<=n;++i) ans+=s[i]>=n-2;
	printf("%d\n",ans);
	return 0;
}