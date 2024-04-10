// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<int,int> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

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
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=1005;
const int dx[]={1,0,0,-1};
const int dy[]={0,1,-1,0};
char s[N][N];
int n,m;
bool check(int x,int y)
{
	if(x>1&&s[x-1][y]==s[x][y]) return false;
	if(x<n&&s[x+1][y]==s[x][y]) return false;
	if(y>1&&s[x][y-1]==s[x][y]) return false;
	if(y<m&&s[x][y+1]==s[x][y]) return false;
	return true;
}
struct node{
	int x,y;
};
node _q[N*N];
int _l,_r;
int a[N][N];
int main()
{
	memset(a,255,sizeof(a));
	int _;
	read(n,m,_);
	_l=1,_r=0;
	for(int i=1;i<=n;++i)
	{
		read_str(s[i]+1);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(!check(i,j))
			{
				a[i][j]=0;
				_q[++_r]=(node){i,j};
			}
		}
	}
	while(_l!=_r+1)
	{
		node x=_q[_l++];
		for(int i=0;i<4;++i)
		{
			node tmp=x;
			tmp.x+=dx[i];
			tmp.y+=dy[i];
			if(tmp.x>=1&&tmp.x<=n&&tmp.y>=1&&tmp.y<=m&&a[tmp.x][tmp.y]==-1)
			{
				a[tmp.x][tmp.y]=a[x.x][x.y]+1;
				_q[++_r]=tmp;
			}
		}
	}
	while(_--)
	{
		int x,y;
		ll z;
		read(x,y,z);
		if(a[x][y]==-1)
		{
			printf("%d\n",(int)(s[x][y]-48));
			continue;
		}
		if(z>a[x][y])
		{
			printf("%lld\n",((z-a[x][y])&1)^(s[x][y]-48));
		}
		else
		{
			printf("%d\n",(int)(s[x][y]-48));
		}
	}
	return 0;
}