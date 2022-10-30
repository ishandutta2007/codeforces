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

const int N=23;
int dp[1<<22],id[1<<22];
int s[N],len[N],t[N];
struct node{
	int l,r,val;
	Finline bool operator < (const node &o)const
	{
		return l<o.l;
	}
}a[N];
int ans2[N];
void print(int st)
{
	if(!st) return;
	ans2[id[st]]=dp[st]-t[id[st]];
	print(st^(1<<id[st]));
}
int main()
{
	int n,p;read(n,p);
	for(int i=0;i<n;++i) read(s[i],len[i],t[i]),a[i]=(node){s[i],s[i]+len[i]-1,i};
	std::sort(a,a+n);
	memset(dp,63,sizeof(dp));
	dp[0]=1;
	for(int st=0;st<1<<n;++st)
	{
		if(dp[st]>=inf) continue;
		int _tim=dp[st];
		for(int i=0;i<n;++i)
		{
			if((st>>i)&1) continue;
			int pos=0,tim=_tim;
			if(s[i]<=tim) continue;
			while(pos<n)
			{
				if(s[i]<=tim) break;
				while(pos<n&&tim>a[pos].r) ++pos;
				while(pos<n&&!(((st>>a[pos].val)&1)||i==a[pos].val))
				{
					if(tim>=a[pos].l) chmax(tim,a[pos].r+1);
					++pos;
				}
				if(pos==n) break;
				if(tim>=a[pos].l){tim=a[pos].r+1;continue;}
				if(tim+t[i]<a[pos].l)
				{
					if(tim+t[i]<dp[st|(1<<i)])
					{
						dp[st|(1<<i)]=tim+t[i];
						id[st|(1<<i)]=i;
					}
					break;
				}
				chmax(tim,a[pos].r+1);
			}
		}
	}
	if(p==1)
	{
		if(dp[(1<<n)-1]<inf)
		{
			puts("YES");
			print((1<<n)-1);
			for(int i=0;i<n;++i) printf("%d %d\n",1,ans2[i]);
			return 0;
		}
		puts("NO");
		return 0;
	}
	for(int st=0;st<1<<n;++st)
	{
		if(dp[st]<inf&&dp[(1<<n)-1-st]<inf)
		{
			puts("YES");
			print(st);
			print((1<<n)-1-st);
			for(int i=0;i<n;++i) printf("%d %d\n",((st>>i)&1)+1,ans2[i]);
			return 0;
		}
	}
	puts("NO");
	return 0;
}