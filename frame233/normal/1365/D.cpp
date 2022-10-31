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
typedef std::pair<ll,ll> pl;

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

const int N=55;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
char s[N][N];
bool dp[N][N];
pi _q[N*N];
int _l,_r;
void MAIN()
{
	memset(s,0,sizeof(s));
	memset(dp,0,sizeof(dp));
	int n,m;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		read_str(s[i]+1);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]=='B')
			{
				for(int dir=0;dir<4;++dir)
				{
					int u=i+dx[dir],v=j+dy[dir];
					if(u>=1&&v>=1&&u<=n&&v<=m)
					{
						if(s[u][v]=='.')
						{
							s[u][v]='#';
						}
					}
				}
			}
		}
	}
	_l=1,_r=0;
	if(s[n][m]!='#') _q[_l=_r=1]=mkpr(n,m);
	while(_l!=_r+1)
	{
		pi x=_q[_l++];
		for(int dir=0;dir<4;++dir)
		{
			int u=x.first+dx[dir],v=x.second+dy[dir];
			if(u>=1&&v>=1&&u<=n&&v<=m&&s[u][v]!='#'&&!dp[u][v])
			{
				dp[u][v]=true;
				_q[++_r]=mkpr(u,v);
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]=='G'&&!dp[i][j])
			{
				printf("No\n");
				return;
			}
			if(s[i][j]=='B'&&dp[i][j])
			{
				printf("No\n");
				return;
			}
		}
	}
	printf("Yes\n");
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}