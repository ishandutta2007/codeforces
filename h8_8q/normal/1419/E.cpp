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
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=2e5+5;
int t,n,m,k,a[N],b[N],ans[N];

void dfs(int u,int s,int p)
{
	if(u==m+1)
	{
		if(s!=n&&s!=p)
			ans[++k]=s;
		return;
	}
	for(int i=0,j=1;i<=b[u];++i,j*=a[u])
		dfs(u+1,s*j,p);
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=0;k=0;
		int tmp=n;
		for(int i=2;i*i<=tmp;++i)
			if(tmp%i==0)
			{
				a[++m]=i;b[m]=0;
				while(tmp%i==0)
					tmp/=i,b[m]++;
			}
		if(tmp!=1) a[++m]=tmp,b[m]=1;
		for(int i=1;i<=m;++i)
		{
			for(int j=1,p=a[i];j<=b[i];++j,p*=a[i])
				if(i==m) dfs(i+1,p,-1);
				else dfs(i+1,p,a[i]*a[i+1]);
			if(i!=m&&a[i]*a[i+1]!=n) ans[++k]=a[i]*a[i+1];
		}
		ans[++k]=n;
		int sum=0;
		for(int i=2;i<=k;++i)
			if(__gcd(ans[i],ans[i-1])==1)
				sum++;
		if(__gcd(ans[1],ans[k])==1) sum++;
		for(int i=1;i<=k;++i)
			printf("%lld ",ans[i]);
		printf("\n%lld\n",sum);
	}
	return 0;
}