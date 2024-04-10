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

const int N=5e5+5,MOD[5]={1000000007,1000000009,998244353},base=131;
int n,k,ans,has[N],jc[N],mod;
char s[N],p[N];

vector<int> sm[N];

inline int query(int x,int y)//s1,s2...sx,s1,s2,sx...
{
	int res=sm[x][y/x]*jc[y%x]%mod+has[y%x];
	return res%mod;
}

signed main()
{
	srand(time(0));
	n=read();k=read();
	scanf("%s",s+1);
	ans=n;mod=MOD[rand()%3];
	for(int i=1;i<=n;++i)
		has[i]=(has[i-1]*base%mod+s[i])%mod;
	jc[0]=1;
	for(int i=1;i<=n;++i)
		jc[i]=jc[i-1]*base%mod;
	sm[n].push_back(0);
	for(int j=1;j<=k/n;++j)
		sm[n].push_back((sm[n][j-1]*jc[n-1]%mod*base%mod+has[n])%mod);
	for(int i=n-1;i>=1;--i)
	{
		sm[i].push_back(0);
		for(int j=1;j<=k/i;++j)
			sm[i].push_back((sm[i][j-1]*jc[i-1]%mod*base%mod+has[i])%mod);
		int l=1,r=k,ps=0;
		while(l<=r)
		{
			if(query(i,mid)==query(ans,mid))
				ps=mid,l=mid+1;
			else r=mid-1;
		}
		if(s[ps%ans+1]>s[ps%i+1])
			ans=i;
	}
	for(int i=1;i<=k;++i)
		printf("%c",s[(i-1)%ans+1]);
	return 0;
}