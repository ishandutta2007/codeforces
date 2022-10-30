// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

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
template <typename _Tp,typename... Args>Finline void read(_Tp& t,Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while((ch<65||ch>122||(ch>90&&ch<97))&&ch!='.') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)||ch=='.') *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=2005;
struct node{
	int x,y;
	Finline node(const int X=0,const int Y=0):x(X),y(Y){}
};
std::vector<node> pos[26];
char s[N][N],S[N][N];
std::vector<std::pair<node,node> > v;
void MAIN()
{
	v.clear();
	for(int i=0;i<26;++i) pos[i].clear();
	int n,m;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		read_str(s[i]+1);
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]!='.')
			{
				pos[s[i][j]-97].push_back(node(i,j));
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			S[i][j]='.';
		}
	}
	int cnt=-1;
	for(int i=0;i<26;++i)
	{
		if(pos[i].size())
		{
			cnt=i;
			node a=*pos[i].begin();
			node b=*--pos[i].end();
			if(a.x==b.x)
			{
				for(auto it:pos[i])
				{
					if(it.x!=a.x)
					{
						printf("NO\n");
						return;
					}
				}
				for(int j=a.y;j<=b.y;++j)
				{
					S[a.x][j]=i+97;
				}
			}
			else
			{
				for(auto it:pos[i])
				{
					if(it.y!=a.y)
					{
						printf("NO\n");
						return;
					}
				}
				for(int j=a.x;j<=b.x;++j)
				{
					S[j][a.y]=i+97;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]!=S[i][j])
			{
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n%d\n",cnt+1);
	std::pair<node,node> last;
	for(int i=cnt;i>=0;--i)
	{
		if(pos[i].size())
		{
			node a=*pos[i].begin();
			node b=*--pos[i].end();
			v.push_back(last=std::make_pair(a,b));
		}
		else
		{
			v.push_back(last);
		}
	}
	for(int i=v.size()-1;i>=0;--i)
	{
		printf("%d %d %d %d\n",v[i].first.x,v[i].first.y,v[i].second.x,v[i].second.y);
	}
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}
//