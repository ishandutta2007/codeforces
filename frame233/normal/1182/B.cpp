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

const int N=100005;
const int dx[]={1,0,0,-1},dy[]={0,1,-1,0};
char s[505][505];
int col[505],row[505];
int main()
{
	int w,h;
	read(w,h);
	int cnt=0;
	for(int i=1;i<=w;++i)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=h;++j)
		{
			if(s[i][j]=='*')
			{
				++cnt;
			}
		}
	}
	for(int i=2;i<w;++i)
	{
		for(int j=2;j<h;++j)
		{
			if(s[i][j]=='*'&&s[i-1][j]=='*'&&s[i+1][j]=='*'&&s[i][j-1]=='*'&&s[i][j+1]=='*')
			{
				int x=i,y=j;
				int CNT=1;
				for(int dir=0;dir<4;++dir)
				{
					int u=x,v=y;
					while(u+dx[dir]>=1&&u+dx[dir]<=w&&v+dy[dir]>=1&&v+dy[dir]<=h&&s[u+dx[dir]][v+dy[dir]]=='*')
					{
						u+=dx[dir];
						v+=dy[dir];
						++CNT;
					}
				}
				if(CNT==cnt)
				{
					printf("YES\n");
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}