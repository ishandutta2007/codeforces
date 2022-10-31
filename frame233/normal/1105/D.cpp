// luogu-judger-enable-o2
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
const double eps=1e-8;
 
uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
 
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
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
char s[N][N];
int a[N];
bool used[N][N];
struct node{
	int x,y,step;
};
node _q[N*N];
int _l,_r;
std::vector<std::pair<int,int> > pos[10];
int now_pos[10];
int cnt[10];
int main()
{
	int n,m,p;
	read(n,m,p);
	for(int i=1;i<=p;++i) read(a[i]);
	for(int i=1;i<=n;++i)
	{
		read_str(s[i]+1);
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]>=48&&s[i][j]<=57)
			{
				pos[s[i][j]-48].push_back(std::make_pair(i,j));
			}
			if(s[i][j]!='.')
			{
				used[i][j]=1;
			}
		}
	}
	for(int i=1;i<=p;++i) now_pos[i]=0;
	int now=0;
	bool flag=1;
	int turn=0;
	while(turn<=p)
	{
		flag=0;
		++now;
		if(now>p) now=1;
		_l=1,_r=0;
		for(int i=now_pos[now];i<(int)pos[now].size();++i)
		{
			_q[++_r]=(node){pos[now][i].first,pos[now][i].second,a[now]};
		}
		now_pos[now]=(int)pos[now].size();
		while(_l!=_r+1)
		{
			node x=_q[_l++],tmp;
			if(s[x.x][x.y]=='.')
			{
				pos[now].push_back(std::make_pair(x.x,x.y));
				s[x.x][x.y]=now+48;
				flag=1;
			}
			if(!x.step)
			{
				continue;
			}
			--x.step;			
			for(int i=0;i<4;++i)
			{
				tmp=x;
				tmp.x+=dx[i],tmp.y+=dy[i];
				if(tmp.x>=1&&tmp.x<=n&&tmp.y>=1&&tmp.y<=m&&!used[tmp.x][tmp.y])
				{
					_q[++_r]=tmp;
					used[tmp.x][tmp.y]=1;
				}
			}
		}
		if(flag) turn=0;
		else ++turn;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]>=48&&s[i][j]<=57)
			{
				++cnt[s[i][j]-48];
			}
		}
	}
	for(int i=1;i<=p;++i) printf("%d ",cnt[i]);
	printf("\n");
    return 0;
}