// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

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

const int N=1005;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const char ds[]={'R','L','D','U'};
struct node{
	int x,y;
	Finline bool operator == (const node &o)const
	{
		return x==o.x&&y==o.y;
	}
}a[N][N];
char s[N][N];
struct Node{
	int x,y;
	node st;
}_q[N*N];
int _l,_r;
bool vis[N][N];
int main()
{
	int n;
	read(n);
	_l=1,_r=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			read(a[i][j].x,a[i][j].y);
			if((node){i,j}==a[i][j])
			{
				vis[i][j]=1;
				s[i][j]='X';
				_q[++_r]={i,j,a[i][j]};
			}
		}
	}
	while(_l!=_r+1)
	{
		Node x=_q[_l++],tmp;
		for(int dir=0;dir<4;++dir)
		{
			tmp=x;
			tmp.x+=dx[dir];
			tmp.y+=dy[dir];
			if(tmp.x>=1&&tmp.x<=n&&tmp.y>=1&&tmp.y<=n&&!vis[tmp.x][tmp.y]&&a[tmp.x][tmp.y]==x.st)
			{
				vis[tmp.x][tmp.y]=1;
				s[tmp.x][tmp.y]=ds[dir^1];
				_q[++_r]=tmp;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(a[i][j]==(node){-1,-1})
			{
				bool flag=false;
				for(int dir=0;dir<4;++dir)
				{
					if(a[i+dx[dir]][j+dy[dir]]==a[i][j])
					{
						s[i][j]=ds[dir];
						flag=true;
						break;
					}
				}
				if(!flag)
				{
					printf("INVALID\n");
					return 0;
				}
				vis[i][j]=true;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(!vis[i][j])
			{
				printf("INVALID\n");
				return 0;
			}
		}
	}
	printf("VALID\n");
	for(int i=1;i<=n;++i)
	{
		printf("%s\n",s[i]+1);
	}
	return 0;
}