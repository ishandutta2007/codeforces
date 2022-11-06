#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=1e5+5;
int n,q,a[N],ne[N][20],hav[N];

vector<int> yz[N];

inline bool check(int x)
{
	for(int i=0;i<yz[x].size();++i)
		if(hav[yz[x][i]]) return 0;
	return 1;
}

signed main()
{
	n=read();q=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		int tmp=a[i];
		for(int j=2;j*j<=tmp;++j)
			if(tmp%j==0)
			{
				yz[i].push_back(j);
				while(tmp%j==0) tmp/=j;
			}
		if(tmp!=1) yz[i].push_back(tmp);
	}
	for(int l=1,r=0;l<=n;++l)
	{
		while(r+1<=n&&check(r+1))
		{
			++r;
			for(int i=0;i<yz[r].size();++i)
				hav[yz[r][i]]=1;
		}
		ne[l][0]=r+1;
		for(int i=0;i<yz[l].size();++i)
			hav[yz[l][i]]=0;
	}
	for(int i=1;i<=17;++i)
		for(int j=1;j<=n;++j)
			ne[j][i]=ne[ne[j][i-1]][i-1];
	while(q--)
	{
		int l=read(),r=read(),ans=0;
		for(int i=17;i>=0;--i)
			if(ne[l][i]&&ne[l][i]<=r+1)
				l=ne[l][i],ans+=(1<<i);
		if(l!=r+1) ans++;
		printf("%lld\n",ans);
	}
	return 0;
}