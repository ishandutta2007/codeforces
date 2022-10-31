// luogu-judger-enable-o2
// Author -- Frame
 
#pragma GCC optimize(2)
 
#include<cstdio>
#include<cstring>
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
const ll INF=0x7ffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool ismax(_Tp &a,const _Tp &b){return a>b?1:a=b,0;}
template <typename _Tp>Finline bool ismin(_Tp &a,const _Tp &b){return a<b?1:a=b,0;}
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
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}
 
const int N=200005;
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
char s[N];
int dir[N];
int minx,miny,maxx,maxy;
bool used[4];
bool check1(int n)
{
	int x=0,y=0;
	bool flag=0;
	int tmp=0;
	for(int i=1;i<=n;++i)
	{
		x+=dx[dir[i]];
		y+=dy[dir[i]];
		if(x==maxx)
		{
			if(flag) return 0;
			--x;
			flag=1;
		}
		chmin(tmp,x);
	}
	if(tmp<minx) return 0;
	return 1;
}
bool check2(int n)
{
	int x=0,y=0;
	bool flag=0;
	int tmp=0;
	for(int i=1;i<=n;++i)
	{
		x+=dx[dir[i]];
		y+=dy[dir[i]];
		if(x==minx)
		{
			if(flag) return 0;
			++x;
			flag=1;
		}
		chmax(tmp,x);
	}
	if(tmp>maxx) return 0;
	return 1;
}
bool check3(int n)
{
	int x=0,y=0;
	bool flag=0;
	int tmp=0;
	for(int i=1;i<=n;++i)
	{
		x+=dx[dir[i]];
		y+=dy[dir[i]];
		if(y==maxy)
		{
			if(flag) return 0;
			--y;
			flag=1;
		}
		chmin(tmp,y);
	}
	if(tmp<miny) return 0;
	return 1;
}
bool check4(int n)
{
	int x=0,y=0;
	bool flag=0;
	int tmp=0;
	for(int i=1;i<=n;++i)
	{
		x+=dx[dir[i]];
		y+=dy[dir[i]];
		if(y==miny)
		{
			if(flag) return 0;
			++y;
			flag=1;
		}
		chmax(tmp,y);
	}
	if(tmp>maxy) return 0;
	return 1;
}
void MAIN()
{
	scanf("%s",s+1);
	int l=strlen(s+1);
	memset(used,0,sizeof(used));
	for(int i=1;i<=l;++i)
	{
		if(s[i]=='W')
		{
			dir[i]=0;
		}
		else if(s[i]=='S')
		{
			dir[i]=1;
		}
		else if(s[i]=='A')
		{
			dir[i]=2;
		}
		else
		{
			dir[i]=3;
		}
		used[dir[i]]=1;
	}
	int x=0,y=0;
	miny=0,minx=0;
	maxx=0,maxy=0;
	for(int i=1;i<=l;++i)
	{
		x+=dx[dir[i]];
		y+=dy[dir[i]];
		chmin(minx,x);
		chmin(miny,y);
		chmax(maxx,x);
		chmax(maxy,y);
	}
	ll ans=1ll*(maxx-minx+1)*(maxy-miny+1);
	if(check1(l))
	{
		int tmp=maxx-1;
		chmax(tmp,0);
		if(used[1]&&!used[0]) tmp=max(1,maxx-1);
		chmin(ans,1ll*(tmp-minx+1)*(maxy-miny+1));
	}
	if(check2(l))
	{
		int tmp=minx+1;
		chmin(tmp,0);
		if(used[0]&&!used[1]) tmp=min(-1,minx+1);
		chmin(ans,1ll*(maxx-tmp+1)*(maxy-miny+1));
	}
	if(check3(l))
	{
		int tmp=maxy-1;
		chmax(tmp,0);
		if(used[3]&&!used[2]) tmp=max(1,maxy-1);
		chmin(ans,1ll*(maxx-minx+1)*(tmp-miny+1));
	}
	if(check4(l))
	{
		int tmp=miny+1;
		chmin(tmp,0);
		if(!used[3]&&used[2]) tmp=min(-1,miny+1);
		chmin(ans,1ll*(maxx-minx+1)*(maxy-tmp+1));
	}
	printf("%lld\n",ans);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}