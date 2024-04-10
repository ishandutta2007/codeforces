// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t, Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],cnt;
int dep[N];
int _q[N],_l,_r;
Finline void add(const int &u,const int &v){c[++cnt]=(edge){v,front[u]},front[u]=cnt;}
void bfs()
{
	dep[1]=0;
	_q[_l=_r=1]=1;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int i=front[x];i;i=c[i].nxt)
		{
			if(!~dep[c[i].v])
			{
				dep[c[i].v]=dep[x]+1;
				_q[++_r]=c[i].v;
			}
		}
	}
}
int main()
{
	int _;
	read(_);
	while(_--)
	{
		int n,m,x,y;
		read(n,m);
		memset(front,0,4*(n+3));
		memset(dep,255,4*(n+3));
		cnt=0;
		for(int i=1;i<=m;++i)
		{
			read(x,y);
			add(x,y),add(y,x);
		}
		bfs();
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;++i)
		{
			if(dep[i]&1) ++cnt1;
			else ++cnt2;
		}
		if(cnt1<cnt2)
		{
			printf("%d\n",cnt1);
			for(int i=1;i<=n;++i)
			{
				if(dep[i]&1)
				{
					printf("%d ",i);
				}
			}
			printf("\n");
		}
		else
		{
			printf("%d\n",cnt2);
			for(int i=1;i<=n;++i)
			{
				if(!(dep[i]&1))
				{
					printf("%d ",i);
				}
			}
			printf("\n");
		}
	}
	return 0;
}