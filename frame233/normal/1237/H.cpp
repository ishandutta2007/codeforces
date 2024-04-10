// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=4005;
char s[N],t[N],a[N],b[N];
int c1[4],c2[4];
int cnt[4];
void MAIN()
{
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	int n=read_str(s+1);
	read_str(t+1);
	for(int i=1;i<=n;i+=2)
	{
		int x=(s[i]-48)*2+s[i+1]-48;
		++c1[x];
	}
	for(int i=1;i<=n;i+=2)
	{
		int x=(t[i]-48)*2+t[i+1]-48;
		++c2[x];
	}
	if(c1[0]!=c2[0]||c1[3]!=c2[3]) return (void)puts("-1");
	int pos=0;
	if(c1[1]!=c2[2])
	{
		for(int i=2;i<=n;i+=2)
		{
			memcpy(a,s,sizeof(a));
			memset(cnt,0,sizeof(cnt));
			std::reverse(a+1,a+i+1);
			for(int i=1;i<=n;i+=2)
			{
				int x=(a[i]-48)*2+a[i+1]-48;
				++cnt[x];
			}
			if(cnt[1]==c2[2])
			{
				pos=i;
				break;
			}
		}
		if(!pos)
		{
			for(int i=2;i<=n;i+=2)
			{
				memcpy(b,t,sizeof(b));
				memset(cnt,0,sizeof(cnt));
				std::reverse(b+1,b+i+1);
				for(int i=1;i<=n;i+=2)
				{
					int x=(b[i]-48)*2+b[i+1]-48;
					++cnt[x];
				}
				if(cnt[1]==c1[2])
				{
					pos=-i;
					break;
				}
			}
		}
		assert(pos);
	}
	std::vector<int> ans;
	if(pos>0)
	{
		ans.pb(pos);
		std::reverse(s+1,s+pos+1);
	}
	if(pos<0) std::reverse(t+1,t-pos+1);
	for(int i=0;i<n;i+=2)
	{
		for(int j=i+1;j<=n;j+=2)
		{
			if(s[j]==t[n-i]&&s[j+1]==t[n-i-1])
			{
				if(j>1) ans.pb(j-1),std::reverse(s+1,s+j);
				ans.pb(j+1);
				std::reverse(s+1,s+j+2);
				break;
			}
		}
	}
	if(pos<0)
	{
		ans.pb(-pos);
		std::reverse(s+1,s-pos+1);
	}
	printf("%d\n",SZ(ans));
	for(auto it:ans) printf("%d ",it);
	printf("\n");
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}