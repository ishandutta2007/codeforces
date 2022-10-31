// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=(1<<18)+5;
int cnt[N];
int main()
{
	int h;read(h);
	int n=(1<<h)-1,x;
	for(int i=1;i<=420;++i)
	{
		int u=rnd()%n+1,v=rnd()%n+1,w=rnd()%n+1;
		while(u==v||u==w||v==w) u=rnd()%n+1,v=rnd()%n+1,w=rnd()%n+1;
		printf("? %d %d %d\n",u,v,w),fflush(stdout);
		read(x),++cnt[x];
	}
	int max1=0,max2=0;
	for(int i=1;i<=n;++i)
	{
		if(cnt[i]>cnt[max1]) max2=max1,max1=i;
		else if(cnt[i]>cnt[max2]) max2=i;
	}
	for(int i=1;i<=n;++i)
	{
		if(i!=max1&&i!=max2)
		{
			printf("? %d %d %d\n",max1,max2,i),fflush(stdout);
			read(x);
			if(x==i)
			{
				printf("! %d\n",i),fflush(stdout);
				return 0;
			}
		}
	}
	return 0;
}